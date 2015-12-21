#ifndef MAINWIDOW_H
#define MAINWIDOW_H

#include <QtWidgets/QMainWindow>
//#include "ui_mainwidow.h"
#include "headers.h"
#include "drawwidget.h"

class MainWidow : public QMainWindow
{
	Q_OBJECT

public:
	MainWidow(QWidget *parent = 0);
	~MainWidow();
	void createToolBar();
private:
	//Ui::MainWidowClass ui;
public slots:
	void showStyle();
	void showColor();
private:
	drawWidget *drawwidget;
	QLabel *styleLabel;
	QComboBox *styleComboBox;
	QLabel *widthLabel;
	QSpinBox *widthSpinBox;
	QToolButton *colorBtn;
	QToolButton *clearBtn;

};

#endif // MAINWIDOW_H
