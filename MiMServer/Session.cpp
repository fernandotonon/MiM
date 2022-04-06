#include "Session.h"

Session::Session(tcp::socket *socket, int ID)
:mSocket(socket)
,isWrittingBuffer(false)
,IsFree(true)
,mStream(32768)
{
    SetIDSession(ID);
};

/// Retorna o ID da Sess�o
int Session::GetIDSession()
{
    return IDSession;
}

/// Seta o ID da Sess�o
void Session::SetIDSession(int _idSession)
{
    IDSession = _idSession;
}

/// Troca o socket da sess�o
void Session::ChangeSessionSocket(tcp::socket *socket, int ID)
{
    SetIDSession(ID);
    mSocket = socket;
}

/// Libera a Sess�o
void Session::ReleaseSession()
{
    IsFree = true;
}

/// Seta se a sess�o est� livre
void Session::SetIsFree(bool _isFree)
{
    IsFree = _isFree;
}

/// Retorna se a sess�o est� livre
bool Session::SessionIsFree()
{
    return IsFree;
}
