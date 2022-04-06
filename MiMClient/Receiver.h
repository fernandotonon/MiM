#ifndef _RECEIVER_H
#define _RECEIVER_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <string>
#include <deque>
#include <list>

/// Includes Jogo
#include "Util.hpp"
#include "EventListener.h"
#include "Session.h"

using boost::asio::ip::tcp;

class Receiver
{
    public:
        Receiver(Session *_session);
        ~Receiver();
        void ChangeSession(Session *_session);
        void Receive();
        void CreateBuffer( const boost::system::error_code& error);
        void NotifyListeners();
        void AddListener(EventListener* listener);
        void SetListener(std::list<EventListener*> *listeners);
    private:
        boost::mutex mMutex;
        std::list<EventListener*> *mListeners;
        Session *mSession;
        boost::array<char, 32768> mBufferReceiver;

};

#endif // _RECEIVER_H
