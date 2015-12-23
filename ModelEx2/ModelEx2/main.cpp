#include "modelex.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ModelEx w;
	QTableView view;
	view.setModel(&w);
	view.setWindowTitle(QObject::tr("ModelEX"));
	view.resize(400, 400);
	view.show();
	//w.show();
	return a.exec();
}
