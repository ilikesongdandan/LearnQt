#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include "headers.h"

class WorkThread : public QThread
{
	Q_OBJECT

public:
	WorkThread(QObject *parent=0);
	~WorkThread();

private:
	void run();
};

#endif // WORKTHREAD_H
