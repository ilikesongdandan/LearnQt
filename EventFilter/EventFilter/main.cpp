#include "eventfilter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EventFilter w;
	w.show();
	return a.exec();
}
