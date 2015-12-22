#ifndef PIXITEM_H
#define PIXITEM_H

//#include <QGraphicsItem>
#include "headers.h"
#include <QtWidgets/QGraphicsItem>
class PixItem : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	//PixItem(QObject *parent=0);
	//
	PixItem(QPixmap *pixmap);
	~PixItem();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
	QPixmap pix;  //��ΪͼԪ��ʾ��ͼƬ
};

#endif // PIXITEM_H
