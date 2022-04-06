#include "Receiver.h"
#include <sstream>
#include <iostream>

boost::mutex mMutex;

Receiver::Receiver(Session *_session)
{
    mSession = _session;
    //ctor
}

Receiver::~Receiver()
{
    //dtor
}

void Receiver::ChangeSession(Session *_session)
{
    mSession = _session;
}

void Receiver::Receive()
{
    mSession->mSocket->async_read_some(boost::asio::buffer(mBufferReceiver),
                                              boost::bind(&Receiver::CreateBuffer, this, boost::asio::placeholders::error));
    /*boost::asio::async_read_until(*mSession->mSocket, mSession->mStream,"\0",
                                  boost::bind(&Receiver::CreateBuffer, this, boost::asio::placeholders::error));*/
}
void Receiver::CreateBuffer( const boost::system::error_code& error)
{
    mMutex.lock();
    mSession->errorCode = error;
    if (!error)
    {
        //std::istream stream(&mSession->mStream);
        ////std::string str((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        //std::stringstream oss;
        //oss << stream.rdbuf();

        //std::getline(stream, str);
        //while (mSession->isWrittingBuffer)
          //  Util::Delay(0);
        //mSession->isWrittingBuffer = true;
        mSession->mBuffer = mBufferReceiver;//.data();
        std::cout<<"receiving data lenght:"<<mSession->mBuffer.size()<<std::endl;
        //std::cout<<"INICIO\n"<<mSession->mBuffer<<"\nFIM"<<std::endl;
        //mSession->isWrittingBuffer = false;
        NotifyListeners();
        Receive();
    }
    else
    {
//        std::cout<<"erro! disconnecting socket"<<error.data()<<std::endl;
        std::list<EventListener*>::iterator iter;
        for (iter=mListeners->begin();iter!=mListeners->end();iter++)
        {
            //EventListener *evt = (*iter);
            (*iter)->OnDisconnet(mSession);
            mSession->ReleaseSession();
        }
    }
    mMutex.unlock();
}

void Receiver::AddListener(EventListener* listener)
{
    mListeners->push_back(listener);
}

void Receiver::SetListener(std::list<EventListener*> *listeners)
{
    mListeners = listeners;
}

void Receiver::NotifyListeners()
{
    std::list<EventListener*>::iterator iter;
    for(iter=mListeners->begin();iter!=mListeners->end();iter++)
    {
        (*iter)->OnReceive(mSession);
    }
}
