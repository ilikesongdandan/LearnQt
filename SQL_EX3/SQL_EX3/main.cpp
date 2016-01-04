#include "mainwindow.h"
#include "conndlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ConnDlg dialog;
	if (dialog.exec()!=QDialog::Accepted)
	{
		return -1;
	}
	//dialog.show();
	QFile *carDetails = new QFile("attribs.xml");
	MainWindow window("factory", "cars", carDetails);
	window.show();

	//MainWindow w;
	//w.show();
	return a.exec();
}
