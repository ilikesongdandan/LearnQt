#ifndef TIMETHREAD_H
#define TIMETHREAD_H
#include "headers.h"
#include <QtCore/QThread>

class TimeThread : public QThread
{
	Q_OBJECT

public:
	TimeThread(QObject *parent=0);
	~TimeThread();
	TimeThread(int socketDescriptor, QObject *parent = 0);
	void run();
private:
	int socketDescriptor;
signals:
	void error(QTcpSocket::SocketError sockerError);
};

#endif // TIMETHREAD_H
