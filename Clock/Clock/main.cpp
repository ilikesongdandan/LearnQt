#include "clock.h"
#include <QtWidgets/QApplication>
#include "digclock.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Clock w;
	//w.show();
	DigClock clock;
	clock.show();
	return a.exec();
}
