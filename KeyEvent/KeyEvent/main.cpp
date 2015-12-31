#include "keyevent.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KeyEvent w;
	w.show();
	return a.exec();
}
