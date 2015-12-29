#include "udpclient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UdpClient w;
	w.show();
	return a.exec();
}
