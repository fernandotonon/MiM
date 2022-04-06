#include "Session.h"

Session::Session(tcp::socket *socket, int ID)
:mSocket(socket)
,isWrittingBuffer(false)
,IsFree(true)
,mStream(32768)
{
    SetIDSession(ID);
};

/// Retorna o ID da Sessão
int Session::GetIDSession()
{
    return IDSession;
}

/// Seta o ID da Sessão
void Session::SetIDSession(int _idSession)
{
    IDSession = _idSession;
}

/// Troca o socket da sessão
void Session::ChangeSessionSocket(tcp::socket *socket, int ID)
{
    SetIDSession(ID);
    mSocket = socket;
}

/// Libera a Sessão
void Session::ReleaseSession()
{
    IsFree = true;
}

/// Seta se a sessão está livre
void Session::SetIsFree(bool _isFree)
{
    IsFree = _isFree;
}

/// Retorna se a sessão está livre
bool Session::SessionIsFree()
{
    return IsFree;
}
