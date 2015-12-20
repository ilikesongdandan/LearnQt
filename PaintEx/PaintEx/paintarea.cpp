#include "paintarea.h"

paintArea::paintArea(QWidget *parent)
	: QWidget(parent)
{
	setPalette(QPalette(Qt::green));
	setAutoFillBackground(true);
	setMinimumSize(400, 400);
}

paintArea::~paintArea()
{

}
void paintArea::setShape(Shape s){
	shape = s;
	update();
}
void paintArea::setPen(QPen p){
	pen = p;
	update();
}
void paintArea::setBrush(QBrush b){
	brush = b;
	update();
}
void paintArea::setFillRule(Qt::FillRule rule){
	fillRule = rule;
	update();
}
void paintArea::paintEvent(QPaintEvent *){
	QPainter p(this);
	p.setPen(pen);
	p.setBrush(brush);
	QRect rect(50, 100, 300, 200);
	static const QPoint points[4] = {
		QPoint(150, 100),
		QPoint(300, 150),
		QPoint(350, 250),
		QPoint(100, 300)
	};
	int startAngle = 30 * 16;
	int spanAngle = 120 * 16;
	
	QPainterPath path;
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);

	switch (shape)
	{
	case paintArea::Line:
		p.drawLine(rect.topLeft(), rect.bottomRight());
		break;
	case paintArea::Rectangle:
		p.drawRect(rect);
		break;
	case paintArea::RoundRect:
		p.drawEllipse(rect);
		break;
	case paintArea::Ellipse:
		p.drawEllipse(rect);
		break;
	case paintArea::Polygon:
		p.drawPolygon(points, 4);
		break;
	case paintArea::Polyline:
		p.drawPolyline(points, 4);
		break;
	case paintArea::Points:
		p.drawPoints(points, 4);
		break;
	case paintArea::Arc:
		p.drawArc(rect, startAngle, spanAngle);
		break;
	case paintArea::Path:
		p.drawPath(path);
		break;
	case paintArea::Text:
		p.drawText(rect, Qt::AlignCenter, tr("hello qt!"));
		break;
	case paintArea::Pixmap:
		p.drawPixmap(150, 150,  QPixmap("1.png"));
		break;
	default:
		break;
	}
}
