#ifndef CLOCK_H
#define CLOCK_H

#include <QtWidgets/QDialog>
//#include "ui_clock.h"

class Clock : public QDialog
{
	Q_OBJECT

public:
	Clock(QWidget *parent = 0);
	~Clock();

private:
	//Ui::ClockClass ui;
};

#endif // CLOCK_H
