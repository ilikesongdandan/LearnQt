#include "testhello.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestHello w;
	w.show();
	return a.exec();
}
