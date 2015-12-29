#include "server.h"

Server::Server(QObject *parent,int port)
	: QTcpServer(parent)
{
	listen(QHostAddress::Any, port);
}

Server::~Server()
{

}
void Server::incomingConnection(int socketDescriptor){
	TcapClientSocket *tcpClientSocket = new TcapClientSocket(this);
	connect(tcpClientSocket, SIGNAL(updateClients(QString, int)), this, SLOT(updateClients(QString, int)));
	connect(tcpClientSocket, SIGNAL(disconnect(int)), this, SLOT(slotDisconnected(int)));

	tcpClientSocket->setSocketDescriptor(socketDescriptor);
	TcapClientSocketList.append(tcpClientSocket);
}
void Server::updateClients(QString msg, int length){
	emit updateServer(msg, length);
	for (int i = 0; i < TcapClientSocketList.count();++i)
	{
		QTcpSocket *item = TcapClientSocketList.at(i);
		if (item->write(msg.toLatin1(), length) != length)
		{
			continue;
		}
	}
}
void Server::slotDisconnected(int descriptor){
	for (int i = 0; i < TcapClientSocketList.count(); i++)
	{
		QTcpSocket *item = TcapClientSocketList.at(i);
		if (item->socketDescriptor()==descriptor)
		{
			TcapClientSocketList.removeAt(i);
			return;
		}
	}
	return;
}