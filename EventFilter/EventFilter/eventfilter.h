#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QtWidgets/QMainWindow>
#include "ui_eventfilter.h"
#include "headers.h"

class EventFilter : public QDialog
{
	Q_OBJECT

public:
	EventFilter(QWidget *parent = 0);
	~EventFilter();

private:
	Ui::EventFilterClass ui;
	QLabel *label1;
	QLabel *label2;
	QLabel *label3;

	QLabel *stateLabel;

	QImage Image1;
	QImage Image2;
	QImage Image3;

public slots:
	bool eventFilter(QObject *, QEvent *);
};

#endif // EVENTFILTER_H
