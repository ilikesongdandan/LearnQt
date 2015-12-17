#include "palette.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Palette w;
	w.show();
	return a.exec();
}
