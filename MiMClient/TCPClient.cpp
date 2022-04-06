#include "TCPClient.h"

TCPClient::TCPClient(const std::string& ip, const std::string& port, int id)
    :mSocket(mService)
{
    try
    {
        mSession = new Session(&mSocket,id);
        tcp::resolver mResolver(mService);
        tcp::resolver::query query(tcp::v4(), ip.data(), port.data());
        tcp::resolver::iterator mIterator = mResolver.resolve(query);
        mSocket.connect(*mIterator);
        StartReceive();
    }
    catch (std::logic_error const& le)
    {
        std::cerr << "STD::LOGIC_ERROR: " << le.what() << std::endl;
    }
    catch (boost::exception &e)
    {
        std::cerr << "TCPClient::TCPClient::BOOST_ERROR: " << ((std::string)boost::diagnostic_information(e)).c_str() << std::endl;
    }
    catch (...)
    {
        std::cout<<"UNKNOWN_ERROR"<<std::endl;
    }
};
TCPClient::TCPClient()
    :mSocket(mService)
{

};

void TCPClient::SetEventListener(TCPClientEventListener *eventListener)
{
    mEventListener = eventListener;
}

void TCPClient::Connect(const std::string &ip, const std::string &port, int id)
{

    try
    {
        if(mSession)
            throw std::logic_error("Already Connected!");
        mSession = new Session(&mSocket,id);
        tcp::resolver mResolver(mService);
        tcp::resolver::query query(tcp::v4(), ip.data(), port.data());
        tcp::resolver::iterator mIterator = mResolver.resolve(query);
        mSocket.connect(*mIterator);
        StartReceive();
    }
    catch (std::logic_error const& le)
    {
        std::cerr << "STD::LOGIC_ERROR: " << le.what() << std::endl;
    }
    catch (boost::exception &e)
    {
        std::cerr << "TCPClient::TCPClient::BOOST_ERROR: " << ((std::string)boost::diagnostic_information(e)).c_str() << std::endl;
    }
    catch (...)
    {
        std::cout<<"UNKNOWN_ERROR"<<std::endl;
    }
}

TCPClient::~TCPClient()
{
};

void TCPClient::Receive()
{
    while (1)
    {
        try
        {
            //session.bytes_transferred = mSocket.read_some(boost::asio::buffer(session.mBuffer));
           /* mSocket.async_read_some(boost::asio::buffer(mSession->mBuffer),
                                    boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error,
                                                boost::asio::placeholders::bytes_transferred));*/
            mSession->mSocket->async_read_some(boost::asio::buffer(mBufferReceiver),
                                                      boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error));

            mService.run();
        }
        catch (std::logic_error const& le)
        {
            std::cerr << "STD::LOGIC_ERROR: " << le.what() << std::endl;
        }
        catch (boost::exception &e)
        {
            std::cerr << "TCPClient::Receive::BOOST_ERROR: " << ((std::string)boost::diagnostic_information(e)).c_str() << std::endl;
        }
        catch (...)
        {
            std::cout<<"UNKNOWN_ERROR"<<std::endl;
        }

    }
};

void TCPClient::OnReceive(const boost::system::error_code& error)
{
    mSession->errorCode = error;
    if (!error)
    {
        /*std::istream stream(&mSession->mStream);
        //std::string str((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        std::stringstream oss;
        oss << stream.rdbuf();*/
        mSession->mBuffer = mBufferReceiver.data();
        //mSession->mBuffer.assign(mBufferReceiver.begin(),)

        mEventListener->OnTCPClientReceive(mSession);

        mSession->mBuffer.clear();
        //mBufferReceiver.assign("");

        /*mSocket.async_read_some(boost::asio::buffer(mSession->mBuffer),
                                boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error));*/
        mSession->mSocket->async_read_some(boost::asio::buffer(mBufferReceiver),
                                                  boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error));

    }
    else if (error != boost::asio::error::eof)
    {
        mSocket.close();
    }
}

void TCPClient::StartReceive()
{
    boost::thread mThread(boost::bind( &TCPClient::Receive, this ));
}

void TCPClient::Send(const std::string& data)
{
start:
    try
    {
        std::cout<<"sending data lenght:"<<data.length()<<std::endl;

        boost::asio::async_write(mSocket,
                                 boost::asio::buffer(data,data.length()),
                                 boost::bind(&TCPClient::Error, this,
                                             boost::asio::placeholders::error));
    }
    catch (std::logic_error const& le)
    {
        std::cerr << "TCPClient::Send::STD::LOGIC_ERROR: " << le.what() << std::endl;
    }
    catch (boost::exception &e)
    {
        std::cerr << "TCPClient::Send::BOOST_ERROR: " << ((std::string)boost::diagnostic_information(e)).c_str() << std::endl;
        goto start;
    }
    catch (...)
    {
        std::cout<<"UNKNOWN_ERROR"<<std::endl;
    }
};
void TCPClient::Error(const boost::system::error_code& error)
{
    if (error)
    {
        //throw std::logic_error("ERRO AQUI!!");
    }
}
