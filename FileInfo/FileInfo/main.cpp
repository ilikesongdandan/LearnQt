#include "fileinfo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileInfo w;
	w.show();
	return a.exec();
}
