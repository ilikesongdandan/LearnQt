#include "workthread.h"

WorkThread::WorkThread(QObject *parent)
	: QThread(parent)
{
	//run();
}

WorkThread::~WorkThread()
{

}
void WorkThread::run(){
	while (true)
	{
		for (int n = 0; n < 10;++n)
		{
			qDebug() << n << n << n << n << n << n << n << n;
		}
	}
}