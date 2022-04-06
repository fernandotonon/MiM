#ifndef _EVENTLISTENER_H
#define _EVENTLISTENER_H

#include "Session.h"

class EventListener
{
    public:
        virtual void OnReceive(Session *session) = 0;
        virtual void OnConnect(Session *session) = 0;
        virtual void OnDisconnet(Session *session) = 0;
};

#endif // _EVENTLISTENER_H

