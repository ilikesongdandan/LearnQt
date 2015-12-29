#include "networkinformation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NetworkInformation w;
	w.show();
	return a.exec();
}
