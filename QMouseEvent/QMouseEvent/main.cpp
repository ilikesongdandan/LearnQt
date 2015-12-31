#include "mouseevent.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MouseEvent w;
	w.show();
	return a.exec();
}
