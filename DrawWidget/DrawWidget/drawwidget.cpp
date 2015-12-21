#include "drawwidget.h"


drawWidget::drawWidget(QWidget *parent)
	: QWidget(parent)
{
	setAutoFillBackground(true);
	setPalette(QPalette(Qt::white));
	pix = new QPixmap(size());//此pixmap对象用来准备随时接受绘制的内容
	pix->fill(Qt::white);
	setMinimumSize(600, 400);
}

drawWidget::~drawWidget()
{

}
void drawWidget::setStyle(int s){
	style = s;
}
void drawWidget::setWeight(int w){
	weight = w;
}
void drawWidget::setColor(QColor c){
	color = c;
}
void drawWidget::mousePressEvent(QMouseEvent *e){
	startPos = e->pos();
}
void drawWidget::mouseMoveEvent(QMouseEvent *e){
	QPainter *painter = new QPainter;
	QPen pen;
	pen.setStyle((Qt::PenStyle)style);
	pen.setWidth(weight);
	pen.setColor(color);

	painter->begin(pix);
	painter->setPen(pen);
	painter->drawLine(startPos, e->pos());
	painter->end();
	startPos = e->pos();
	update();
}
void drawWidget::paintEvent(QPaintEvent *){
	QPainter painter(this);
	painter.drawPixmap(QPoint(0, 0), *pix);
}
void drawWidget::resizeEvent(QResizeEvent *e){
	if (height() > pix->height() || width() > pix->width()){
		QPixmap *newpix = new QPixmap(size());
		newpix->fill(Qt::white);
		QPainter p(newpix);
		p.drawPixmap(QPoint(0, 0), *pix);
		pix = newpix;
	}
	QWidget::resizeEvent(e);
}
void drawWidget::clear(){
	QPixmap *clearpix = new QPixmap(size());
	clearpix->fill(Qt::white);
	pix = clearpix;
	update();
}