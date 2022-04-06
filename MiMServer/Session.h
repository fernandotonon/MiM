#ifndef _SESSION_H
#define _SESSION_H

/// Includes padrões
#include <string>
#include <list>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Session
{
	public:
        /// Construtor
        Session(tcp::socket *socket, int ID);
        /// Troca o socket da sessão
        void ChangeSessionSocket(tcp::socket *socket, int ID);
        /// Libera a Sessão
        void ReleaseSession();
        /// Seta se a sessão está livre
        void SetIsFree(bool _isFree);
        /// Retorna se a sessão tá livre
        bool SessionIsFree();
        /// Retorna o ID da Sessão
        int GetIDSession();
        /// Seta o ID da Sessão
        void SetIDSession(int _idSession);

        tcp::socket *mSocket;
        boost::asio::streambuf mStream;
        boost::system::error_code errorCode;
        bool isWrittingBuffer;
        boost::array<char, 32768> mBuffer;
	private:
        /// ID da sessão
        int IDSession;
        /// Situação da Sessão: se está livre ou não
        bool IsFree;
};

#endif
