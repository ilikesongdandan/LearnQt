#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	fileFun();
}

MainWindow::~MainWindow()
{

}
void MainWindow::fileFun(){
	QFile file("binary.dat");
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);
	QDataStream out(&file);
	out << QString(tr("wangjj:"));
	out << QDate::fromString("1991/11/18", "yyyy/MM/dd");
	out << (qint32)25;
	file.close();

	file.setFileName("binary.dat");
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "error!";
		return;
	}

	QDataStream in(&file);
	QString name;
	QDate birthday;
	qint32 age;
	in >> name >> birthday >> age;
	qDebug() << name << birthday << age;
	file.close();
}