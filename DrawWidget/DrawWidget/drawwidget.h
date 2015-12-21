#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#include "headers.h"

#include <QtWidgets/QWidget>

class drawWidget : public QWidget
{
	Q_OBJECT

public:
	drawWidget(QWidget *parent=0);
	~drawWidget();
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
private:
	QPixmap *pix;
	QPoint startPos;
	QPoint endPos;
	int style;
	int weight;
	QColor color;
signals:

public slots :
	void setStyle(int);
	void setWeight(int);
	void setColor(QColor);
	void clear();
};

#endif // DRAWWIDGET_H
