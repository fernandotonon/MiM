#include "Server.h"
#include "Protocol.pb.h"
#include "base64.h"
#include "hacks.h"

/// Construtor
Server::Server(int Port)
{
    server = new TCPServer(Port);


    server->AddListener(this);

    server->Start();

}

/// Destrutor
Server::~Server()
{
}

/// Listener de quando recebe dados em um determinado socket.
void Server::OnReceive(Session* session)
{
    std::cout<<"Recebido:\n"<<session->mBuffer<<std::endl;

    Protocol::Data data;
    ///Encripta pra mandar pro servidor do MiM

    std::wstring encryptedData;
    unsigned char* buffer = new unsigned char[session->mBuffer.size()];
    memcpy(buffer, (void*)session->mBuffer.data(), session->mBuffer.size());
    Base64::Encode(buffer,session->mBuffer.size(),encryptedData);
    std::string str;
    str.assign(encryptedData.begin(),encryptedData.end());

    std::cout<<"Encrypted:\n"<<str<<std::endl;
    std::cout<<"Tamanho  :\n"<<str.size()<<std::endl;
    data.set_data(str);

    mClients[session->GetIDSession()]->Send(data.SerializeAsString());
}
///recebe os dados do MiMServer
void Server::OnTCPClientReceive(Session *session)
{
    Protocol::Data data;
    data.ParseFromString(session->mBuffer);

    int len = Base64::GetDataLength( (int)data.data().size());
    unsigned char* outData = new unsigned char[ len ];
    std::wstring tmp;
    tmp.assign(data.data().begin(),data.data().end());
    int realLen = Base64::Decode( tmp, (int)data.data().size(), outData );
    char *buffer = new char[len];
    memcpy(buffer,outData,len);

    std::string decryptedData = buffer;
    //decryptedData.copy(outData,realLen);
    std::cout<<"sem hack: "<<decryptedData<<std::endl;
    decryptedData = Hacks::Hack(decryptedData);
    std::cout<<"sem hack: "<<decryptedData<<std::endl;
    server->Send(decryptedData,*server->GetSession(session->GetIDSession())->mSocket);
}

void Server::OnConnect(Session* session)
{
    std::cout<<"Cliente conectado - "<<"ID: "<<session->GetIDSession()<<std::endl;
    std::cout<<"Conectando ao servidor do MiM"<<std::endl;

    mClients[session->GetIDSession()] = new TCPClient("localhost","80");
    mClients[session->GetIDSession()]->SetEventListener(this);

    std::cout<<"Enviando ao servidor do MiM"<<std::endl;
    //Carrega configuraçoes
    Protocol::Data data;
    Protocol::Config* config =  data.add_config();
    config->set_key("host");
    config->set_value("devap1");
    config =  data.add_config();
    config->set_key("port");
    config->set_value("80");
    mClients[session->GetIDSession()]->Send(data.SerializeAsString());
}

void Server::OnDisconnet(Session *session)
{
    /*TCPClient* tmp = mClients[session->GetIDSession()];
    mClients.erase(session->GetIDSession());
    delete tmp;*/
    std::cout<<"\nDesConexao - "<<"ID: "<<session->GetIDSession()<<std::endl;
}
