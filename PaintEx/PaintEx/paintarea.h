#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QtWidgets/QWidget>
#include "headers.h"

class paintArea : public QWidget
{
	Q_OBJECT

public:
	paintArea(QWidget *parent=0);
	~paintArea();
	enum Shape{Line,Rectangle,RoundRect,Ellipse,Polygon,Polyline,Points,Arc,Path,Text,Pixmap};
	
	void setShape(Shape);
	void setPen(QPen);
	void setBrush(QBrush);
	void setFillRule(Qt::FillRule);
	void paintEvent(QPaintEvent *);

private:
	Shape shape;
	QPen pen;
	QBrush brush;
	Qt::FillRule fillRule;
};

#endif // PAINTAREA_H
