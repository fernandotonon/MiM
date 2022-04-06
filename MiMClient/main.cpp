#include "Server.h"
#include "Util.hpp"

#define SERVER_WIN32

using namespace std;

int main()
{
    try
    {
        Server* server = new Server(7121);
        std::string command;
        std::cout<<"Command:";
        while (cin>>command)
        {
            if(command=="quit"||command=="q"||command=="sair"||command=="s")
            {
                std::cout<<"Desligando servidor...";
                delete server;
                std::cout<<"OK!";
                return 0;
            }

        }
    }
    catch (boost::exception &e)
    {
#ifdef WIN32
        //MessageBox( NULL, ((std::string)boost::diagnostic_information(e)).c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        std::cerr << "An exception has occured: " << ((std::string)boost::diagnostic_information(e)).c_str() << std::endl;
#endif
    }

    catch (std::logic_error const& le)
    {
#ifdef WIN32
        //MessageBox( NULL, le.what(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        std::cerr << "An exception has occured: " << le.what().c_str() << std::endl;
#endif
    }
    catch (std::exception const &le)
    {
#ifdef WIN32
        //MessageBox( NULL, le.what(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        std::cerr << "An exception has occured: " << le.what().c_str() << std::endl;
#endif
    }
    catch (...)
    {
#ifdef WIN32
        //MessageBox(NULL, "Unknow exception", "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        std::cerr << "Unknow exception" << std::endl;
#endif
    }
    return 0;
}
