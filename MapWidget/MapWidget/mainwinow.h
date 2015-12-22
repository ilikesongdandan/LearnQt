#ifndef MAINWINOW_H
#define MAINWINOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwinow.h"

class MainWinow : public QMainWindow
{
	Q_OBJECT

public:
	MainWinow(QWidget *parent = 0);
	~MainWinow();

private:
	Ui::MainWinowClass ui;
};

#endif // MAINWINOW_H
