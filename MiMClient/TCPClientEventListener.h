#ifndef TCPCLIENTEVENTLISTENER_H
#define TCPCLIENTEVENTLISTENER_H

#include "Session.h"

class TCPClientEventListener
{
    public:
        virtual void OnTCPClientReceive(Session *session) = 0;
        //virtual void OnTCPClientConnect(Session *session) = 0;
};

#endif // TCPCLIENTEVENTLISTENER_H
