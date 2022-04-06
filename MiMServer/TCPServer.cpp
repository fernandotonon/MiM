#include "TCPServer.h"
#include <iostream>

TCPServer::TCPServer(int Port)
        :mAcceptor(mIOService, tcp::endpoint(tcp::v4(), Port)),
        IDSocket(0)
        ,ID(0)
{
    //ctor
}

TCPServer::~TCPServer()
{
    //dtor
}

bool TCPServer::Start()
{
//    DA::Connect();

    boost::thread trd(boost::bind( &TCPServer::MainThread, this ));

    return true;
}

void TCPServer::MainThread()
{
    DoAccept();
    mIOService.run();
}

void TCPServer::DoAccept()
{
    ReleasedSession = 0;
    SetHasReleasedSession(false);
    for(int c=0; c<mSessions.size();++c)
    {
        if(mSessions[c]->SessionIsFree())
        {
            ReleasedSession = c;
            SetHasReleasedSession(true);
            break;
        }

    }

    if(GetHasReleasedSession())
    {
        mSessions[ReleasedSession]->ChangeSessionSocket(new tcp::socket(mIOService), ReleasedSession);
        //PlayerVector::GetInstance()->ChangeSession(mSessions[ReleasedSession]);
        mReceiver[ReleasedSession]->ChangeSession(mSessions[ReleasedSession]);
        mAcceptor.async_accept(*mSessions[ReleasedSession]->mSocket,
                               boost::bind(&TCPServer::OnAccept, this, ReleasedSession, mReceiver[ReleasedSession],
                                           boost::asio::placeholders::error));


    }
    else
    {

        mSessions.push_back(new Session(new tcp::socket(mIOService), ID));
        Receiver* rcv = new Receiver(mSessions[ID]);
        rcv->SetListener(&mListeners);
        mReceiver.push_back(rcv);

        //PlayerVector::GetInstance()->AddPlayer(mSessions[ID]);

        mAcceptor.async_accept(*mSessions[ID]->mSocket,
                               boost::bind(&TCPServer::OnAccept, this, ID, mReceiver[ID],
                                           boost::asio::placeholders::error));
    }


}

void TCPServer::OnAccept(int _ID, Receiver* r, const boost::system::error_code& error)
{
    if (!error)
    {
        r->Receive();
        std::list<EventListener*>::iterator iter;
        for(iter=mListeners.begin();iter!=mListeners.end();iter++)
        {
            (*iter)->OnConnect(mSessions[_ID]);
            mSessions[_ID]->SetIsFree(false);
        }
        if(!GetHasReleasedSession())
        {
            ID++;
        }
        DoAccept();
    }
}

void TCPServer::Send(const std::string& SendBuffer, tcp::socket& socket)
{
    std::cout<<"\n\nenviado\n\n";
    std::cout<<SendBuffer;
    boost::asio::async_write(socket, boost::asio::buffer(SendBuffer.data(), SendBuffer.length()),
                             boost::bind(&TCPServer::Error, this, boost::asio::placeholders::error));
}

void TCPServer::Error(const boost::system::error_code& error)
{
    if(error)
    {
    }
}

/// Adiciona um observador
void TCPServer::AddListener(EventListener* listener)
{
    mListeners.push_back(listener);
}

/// Retorna um socket da lista
tcp::socket* TCPServer::GetSocket(int ID)
{
    return mSessions[ID]->mSocket;
}

/// Fecha um socket da lista
tcp::socket* TCPServer::CloseSocket(int ID)
{
    mSessions[ID]->mSocket->close();
    return NULL;
}

/// Retorna um socket da lista
Session* TCPServer::GetSession(int ID)
{
    return mSessions[ID];
}

/// Retorna o tamanho da lista de Sessions
int TCPServer::GetSessionSize()
{
    return mSessions.size();
}

/// Seta hasReleasedSession
///@ foi preciso esse metodo por causa da thread quando conecta.
void TCPServer::SetHasReleasedSession(bool _hasReleasedSession)
{
    boost::mutex::scoped_lock(mutexHasReleasedSession);
    hasReleasedSession = _hasReleasedSession;
}

/// Retorna hasReleasedSession
///@ foi preciso esse metodo por causa da thread quando conecta.
bool TCPServer::GetHasReleasedSession()
{
    boost::mutex::scoped_lock(mutexHasReleasedSession);
    return hasReleasedSession;
}
