#include "producer.h"

Producer::Producer(QObject *parent)
	: QThread(parent)
{

}

Producer::~Producer()
{

}
void Producer::run(){
	for (int i = 0; i < DataSize;++i)
	{
		freeBytes.acquire();
		buffer[i%BufferSize] = (i%BufferSize);
		usedBytes.release();
	}
}

Consumer::Consumer(QObject *parent)
: QThread(parent)
{

}

Consumer::~Consumer()
{

}
void Consumer::run(){
	for (int i = 0; i < DataSize; ++i)
	{
		usedBytes.acquire();
		fprintf(stderr, "%d", buffer[i%BufferSize]);
		if (i%16==0&&i!=0)
		{
			fprintf(stderr, "\n");
		}
		freeBytes.release();
	}
	fprintf(stderr, "\n");
}