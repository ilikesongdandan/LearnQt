#include "watcher.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Watcher w;
	w.show();
	return a.exec();
}
