#ifndef DIGCLOCK_H
#define DIGCLOCK_H

#include <QtWidgets/QLCDNumber>

#include "headers.h"

class DigClock : public QLCDNumber
{
	Q_OBJECT

public:
	DigClock(QWidget *parent=0);
	~DigClock();
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
private:
	QPoint dragPositions;
	bool showColon;
	private slots:
void showTime();
};

#endif // DIGCLOCK_H
