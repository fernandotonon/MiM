#ifndef _TCPSERVER_H
#define _TCPSERVER_H

/// Includes padrões
#include <string>
#include <deque>
#include <list>

/// Includes Outras Bibliotecas
//boost
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

/// Includes Jogo
#include "Receiver.h"
#include "Session.h"

using boost::asio::ip::tcp;

class TCPServer
{
    public:
        TCPServer(int Port);
        virtual ~TCPServer();
        bool Start();
        void MainThread();
        void DoAccept();
        void OnAccept(int ID, Receiver* r, const boost::system::error_code& error);
        void AddListener(EventListener* listener);
        void Send(const std::string& SendBuffer, tcp::socket& socket);
        void Error(const boost::system::error_code& error);
        tcp::socket* GetSocket(int ID);
        tcp::socket* CloseSocket(int ID);
        int GetSessionSize();
        Session* GetSession(int ID);

        /// Seta hasReleasedSession
        ///@ foi preciso esse metodo por causa da thread quando conecta.
        void SetHasReleasedSession(bool _hasReleasedSession);
        /// Retorna hasReleasedSession
        ///@ foi preciso esse metodo por causa da thread quando conecta.
        bool GetHasReleasedSession();
    protected:
    private:
        bool hasReleasedSession;
        int ReleasedSession;
        int IDSocket;
        int ID;
        boost::asio::io_service mIOService;
        std::deque<Session*> mSessions;
        std::deque<Receiver*> mReceiver;
        std::list<EventListener*> mListeners;
        tcp::acceptor mAcceptor;
        boost::mutex mutexHasReleasedSession;
};

#endif // _TCPSERVER_H
