#include "Server.h"
#include "Protocol.pb.h"
#include "base64.h"

/// Construtor
Server::Server(int Port)
{
    server = new TCPServer(Port);


    server->AddListener(this);

    server->Start();

}

/// Destrutor
Server::~Server()
{
}

/// Listener de quando recebe dados em um determinado socket.
void Server::OnReceive(Session* session)
{
    std::cout<<"inicio - OnReceive\n";
    Protocol::Data data;
    data.ParseFromArray(session->mBuffer.data(), session->mBuffer.size());
//    /data.ParseFromIstream();

    bool newConnection = false;
    std::string host;
    std::string port;
    for(int i = 0; i<data.config_size();++i)
    {
        const Protocol::Config& config = data.config(i);
        if(config.key()=="host")
        {
            host = config.value();
            newConnection = true;
        }
        if(config.key() == "port")
        {
            port = config.value();
        }
    }
    if(newConnection)
    {
        mClients[session->GetIDSession()] = new TCPClient(host,port);
        mClients[session->GetIDSession()]->SetEventListener(this);
    }
    if(data.has_data())
    {

        //std::cout<<"Recebido do client:\n"<<data.data()<<std::endl;
        //std::cout<<"Tamanho  do client:\n"<<data.data().size()<<std::endl;

        int len = Base64::GetDataLength( (int)data.data().size());
        unsigned char* outData = new unsigned char[ len ];
        std::wstring tmp;
        tmp.assign(data.data().begin(),data.data().end());
        int realLen = Base64::Decode( tmp, (int)data.data().size(), outData );
        char *buffer = new char[len];
        memcpy(buffer,outData,len);

        std::string decryptedData;
        decryptedData.assign(buffer,len);
        delete buffer;
        delete outData;

        //Envia para o HOST destino
        //std::cout<<"Enviando ao HOST:\n"<<decryptedData<<std::endl;
        //std::cout<<"Tamanho  ao HOST:\n"<<len<<std::endl;
        mClients[session->GetIDSession()]->Send(decryptedData);
    }
    std::cout<<"fim - OnReceive\n";
}
void Server::OnTCPClientReceive(Session *session)
{
    std::cout<<"inicio - OnTCPClientReceive\n";
    Protocol::Data data;
    ///Criptografa
    std::wstring encryptedData;
    unsigned char* buffer = new unsigned char[session->mBuffer.size()];
    memcpy(buffer, (void*)session->mBuffer.data(), session->mBuffer.size());
    Base64::Encode(buffer,session->mBuffer.size(),encryptedData);
    std::string str;
    str.assign(encryptedData.begin(),encryptedData.end());

    //std::cout<<"Encrypted:"<<str<<std::endl;

    data.set_data(str);

    //Envia para o MiMClient
    server->Send(data.SerializeAsString(),*server->GetSession(session->GetIDSession())->mSocket);
    std::cout<<"fim - OnTCPClientReceive\n";
}

void Server::OnConnect(Session* session)
{
    std::cout<<"\nConexao - "<<"ID: "<<session->GetIDSession()<<std::endl;
}

void Server::OnDisconnet(Session *session)
{
    /*TCPClient* tmp = mClients[session->GetIDSession()];
    mClients.erase(session->GetIDSession());
    delete tmp;*/
    std::cout<<"\nDesConexao - "<<"ID: "<<session->GetIDSession()<<std::endl;
}
