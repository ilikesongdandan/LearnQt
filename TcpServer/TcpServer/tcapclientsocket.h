#ifndef TCAPCLIENTSOCKET_H
#define TCAPCLIENTSOCKET_H

#include "headers.h"

class TcapClientSocket : public QTcpSocket
{
	Q_OBJECT

public:
	TcapClientSocket(QObject *parent=0);
	~TcapClientSocket();

private:
	

signals :
	void updateClients(QString, int);
	void disconnected(int);
protected slots:
	void dataReceived();
	void slotDisconnected();
};

#endif // TCAPCLIENTSOCKET_H
