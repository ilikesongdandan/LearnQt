#include "splashesreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//SplasheSreen w;
	//w.show();

	QPixmap pixmap("1.png");
	QSplashScreen splash(pixmap);
	splash.show();
	a.processEvents();
	SplasheSreen w;
	w.show();
	splash.finish(&w);
	return a.exec();
}
