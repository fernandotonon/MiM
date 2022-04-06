/*
 *
 *
 *
 *
 *
 */

#ifndef _TCPClient_h
#define _TCPClient_h

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/exception/all.hpp>
#include <windows.h>
#include <deque>

#include "TCPClientEventListener.h"
#include "Session.h"

using namespace boost;
using asio::ip::tcp;

class TCPClient
{
public:
    TCPClient(const std::string& ip, const std::string& port, int id = 0);
    TCPClient();
    void Connect(const std::string& ip, const std::string& port, int id = 0);
    void Send(const std::string& data);
    ~TCPClient();
    void SetEventListener(TCPClientEventListener* eventListener);
    TCPClientEventListener* mEventListener;
    void Error(const boost::system::error_code& error);

private:
    void Receive();
    void OnReceive(const boost::system::error_code& error, std::size_t size);
    void StartReceive();
    asio::io_service mService;
    const std::string server;
    const std::string port;
    Session* mSession;
    tcp::socket mSocket;
    boost::array<char, 32768> mBufferReceiver;
};

#endif



