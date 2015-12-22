#ifndef BUTTERFLY_H
#define BUTTERFLY_H


#include <QtCore/QObject>
#include "headers.h"

class butterFly : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	butterFly(QWidget *parent=0);
	~butterFly();
	void timerEvent(QTimerEvent *);
	QRectF boundingRect() const;
private:
	bool up;
	QPixmap pix_up;
	QPixmap pix_down;
	qreal angle;
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	
};

#endif // BUTTERFLY_H
