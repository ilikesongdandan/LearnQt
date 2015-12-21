#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "svgwindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void createMenu();
private:
	Ui::MainWindowClass ui;
	SvgWindow *svgWindow;
public slots:
	void slotOpenFile();
};

#endif // MAINWINDOW_H
