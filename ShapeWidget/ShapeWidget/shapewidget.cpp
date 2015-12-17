#include "shapewidget.h"

ShapeWidget::ShapeWidget(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	QPixmap pix;
	pix.load("1.gif", 0, Qt::ThresholdDither | Qt::AvoidDither | Qt::ThresholdAlphaDither);
	resize(pix.size());
	setMask(QBitmap(pix.mask()));
}

ShapeWidget::~ShapeWidget()
{

}
void ShapeWidget::mousePressEvent(QMouseEvent *event){
	if (event->button() == Qt::LeftButton){
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
	if (event->button() == Qt::RightButton){
		close();
	}
}
void ShapeWidget::mouseMoveEvent(QMouseEvent *event){
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dragPosition);
		event->accept();
	}
}
void ShapeWidget::paintEvent(QPaintEvent *event){
	QPainter painter(this);
	painter.drawPixmap(0, 0, QPixmap("1.gif"));
}