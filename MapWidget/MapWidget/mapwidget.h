#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include "headers.h"

#include <QtWidgets/QGraphicsView>

class MapWidget : public QGraphicsView
{
	Q_OBJECT

public:
	MapWidget(QWidget *parent=0);
	~MapWidget();

	void readMap();
	QPointF mapToMap(QPointF);
private:
	QPixmap map;
	qreal zoom;
	QLabel *viewCoord;
	QLabel *sceneCoord;
	QLabel *mapCoord;
	double x1, y1;
	double x2, y2;
protected:
	void drawBackground(QPainter *painter, const QRectF &rect);
	void mouseMoveEvent(QMouseEvent *event);
	public slots:
void slotZoom(int);
};

#endif // MAPWIDGET_H
