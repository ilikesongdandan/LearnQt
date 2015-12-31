#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QtWidgets/QWidget>
#include "ui_keyevent.h"
#include "headers.h"

class KeyEvent : public QWidget
{
	Q_OBJECT

public:
	KeyEvent(QWidget *parent = 0);
	~KeyEvent();

	void drawPix();
	void keyPressEvent(QKeyEvent *e);
	void paintEvent(QPaintEvent *e);

private:
	Ui::KeyEventClass ui;
	QPixmap *pix;
	QImage image;
	int startX;
	int startY;
	int width;
	int height;
	int step;
};

#endif // KEYEVENT_H
