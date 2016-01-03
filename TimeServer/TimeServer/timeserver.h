#ifndef TIMESERVER_H
#define TIMESERVER_H

#include "headers.h"
#include <QtNetwork/QTcpServer>
class Dialog;
class TimeServer : public QTcpServer
{
	Q_OBJECT

public:
	TimeServer(QObject *parent=0);
	~TimeServer();

private:
	Dialog *dlg;
protected:
	void incomingConnection(int socketDescriptor);
};

#endif // TIMESERVER_H
