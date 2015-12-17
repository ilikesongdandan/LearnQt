#ifndef SPLASHESREEN_H
#define SPLASHESREEN_H

#include <QtWidgets/QMainWindow>
#include "headers.h"
//#include "ui_splashesreen.h"

class SplasheSreen : public QMainWindow
{
	Q_OBJECT

public:
	SplasheSreen(QWidget *parent = 0);
	~SplasheSreen();

private:
	//Ui::SplasheSreenClass ui;
};

#endif // SPLASHESREEN_H
