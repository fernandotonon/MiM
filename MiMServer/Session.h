#ifndef _SESSION_H
#define _SESSION_H

/// Includes padr�es
#include <string>
#include <list>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Session
{
	public:
        /// Construtor
        Session(tcp::socket *socket, int ID);
        /// Troca o socket da sess�o
        void ChangeSessionSocket(tcp::socket *socket, int ID);
        /// Libera a Sess�o
        void ReleaseSession();
        /// Seta se a sess�o est� livre
        void SetIsFree(bool _isFree);
        /// Retorna se a sess�o t� livre
        bool SessionIsFree();
        /// Retorna o ID da Sess�o
        int GetIDSession();
        /// Seta o ID da Sess�o
        void SetIDSession(int _idSession);

        tcp::socket *mSocket;
        boost::asio::streambuf mStream;
        boost::system::error_code errorCode;
        bool isWrittingBuffer;
        boost::array<char, 32768> mBuffer;
	private:
        /// ID da sess�o
        int IDSession;
        /// Situa��o da Sess�o: se est� livre ou n�o
        bool IsFree;
};

#endif
