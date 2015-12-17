#include "digclock.h"


DigClock::DigClock(QWidget *parent)
	: QLCDNumber(parent)
{
	QPalette p = palette();
	p.setColor(QPalette::Window, Qt::blue);
	setPalette(p);

	setWindowFlags(Qt::FramelessWindowHint);
	setWindowOpacity(0.5);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);
	showTime();
	resize(500, 100);
	showColon = true;
}

DigClock::~DigClock()
{

}
void DigClock::showTime(){
	QTime time = QTime::currentTime();
	QString text = time.toString("hh:mm");
	//QString text = time.toString(Qt::TextDate);
	if (showColon){
		text[2] = ':';
		//text[4] = ':';
		showColon = false;
	}
	else
	{
		text[2] = ' ';
		//text[4] = ' ';
		showColon = true;
	}
	display(text);
}
void DigClock::mousePressEvent(QMouseEvent *event){
	if (event->button() == Qt::LeftButton){
		dragPositions = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
	if (event->button() == Qt::RightButton){
		close();
	}
}
void DigClock::mouseMoveEvent(QMouseEvent *event){
	if (event->buttons()&Qt::LeftButton){
		move(event->globalPos() - dragPositions);
		event->accept();
	}
}