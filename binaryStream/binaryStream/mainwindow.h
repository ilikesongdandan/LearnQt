#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
//#include "ui_mainwindow.h"
#include "headers.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	void fileFun();
private:
	//Ui::MainWindowClass ui;
};

#endif // MAINWINDOW_H
