#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QtWidgets/QMainWindow>
#include "ui_mouseevent.h"
#include "headers.h"

class MouseEvent : public QMainWindow
{
	Q_OBJECT

public:
	MouseEvent(QWidget *parent = 0);
	~MouseEvent();

private:
	Ui::MouseEventClass ui;

	QLabel *statusLabel;
	QLabel *MousePosLabel;
protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
};

#endif // MOUSEEVENT_H
