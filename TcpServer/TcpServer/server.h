#ifndef SERVER_H
#define SERVER_H

#include "headers.h"
#include "tcapclientsocket.h"
//#include <QTcpServer>

class Server : public QTcpServer
{
	Q_OBJECT

public:
	Server(QObject *parent=0,int port=0);
	~Server();
	QList<TcapClientSocket*> TcapClientSocketList;

private:

signals :
	void updateServer(QString, int);
public slots:
	void updateClients(QString, int);
	void slotDisconnected(int);
protected:
	void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
