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

void TCPClient::SetEventListener(TCPClientEventListener *eventListener)
{
    mEventListener = eventListener;
}

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
            /*boost::asio::async_read_until(*mSession->mSocket, mSession->mStream,"",
                                          boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error));
            */
           /* mSession->mSocket->async_read_some(boost::asio::buffer(mBufferReceiver),
                                                      boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error,
                                                                  boost::asio::placeholders::bytes_transferred));
*/
            boost::asio::async_read(
                *mSession->mSocket,
                boost::asio::buffer(mBufferReceiver),
                boost::asio::transfer_all(),
                boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
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

void TCPClient::OnReceive(const boost::system::error_code& error, std::size_t size)
{
    std::cout<<"\n\n---TCPClient::OnReceive---\n\n";
    std::cout<<mBufferReceiver.data();
    mSession->errorCode = error;
    if (!error)
    {
        /*std::istream stream(&mSession->mStream);
        //std::string str((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        std::stringstream oss;
        oss << stream.rdbuf();*/
        mSession->mBuffer = mBufferReceiver;//.data();

        mEventListener->OnTCPClientReceive(mSession);
        std::string x = "";
        mBufferReceiver.assign('\0');
        //mBufferReceiver.c

        //mSession->mBuffer.clear();
        //mBufferReceiver.assign("");

        /*mSocket.async_read_some(boost::asio::buffer(mSession->mBuffer),
                                boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error));*/
        boost::asio::async_read(
            *mSession->mSocket,
            boost::asio::buffer(mBufferReceiver),
            boost::asio::transfer_all(),
            boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));

        /*mSession->mSocket->async_read(boost::asio::buffer(mBufferReceiver),
                                                  boost::bind(&TCPClient::OnReceive, this, boost::asio::placeholders::error,
                                                              boost::asio::placeholders::bytes_transferred));*/

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
        std::cout<<"\n\nenviando\n\n"<<std::endl;
        std::cout<<data<<std::endl;
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
