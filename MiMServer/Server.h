#ifndef _SERVER_H
#define _SERVER_H

/// Includes padrões
#include <iostream>
#include <boost/exception/diagnostic_information.hpp>

#include "Protocol.pb.h"
#include "TCPServer.h"
#include "TCPClient.h"


class Server:public EventListener, public TCPClientEventListener
{
    public:
        Server(int Port);
        ~Server();
        void OnReceive(Session* session);
        void OnConnect(Session* session);
        void OnDisconnet(Session* session);
        void OnTCPClientReceive(Session *session);
    protected:
    private:
        void Process(std::string Message, int IDSocket);
        TCPServer *server;
        std::map<int, TCPClient*> mClients;
};

#endif // _SERVER_H
