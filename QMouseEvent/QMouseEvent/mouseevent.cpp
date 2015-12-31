#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("mouse event"));

	statusLabel = new QLabel;
	statusLabel->setText(tr("Current Position"));
	statusLabel->setFixedWidth(100);
	MousePosLabel = new QLabel;
	MousePosLabel->setText(tr(""));
	MousePosLabel->setFixedWidth(100);
	statusBar()->addPermanentWidget(statusLabel);
	statusBar()->addPermanentWidget(MousePosLabel);
	this->setMouseTracking(true);
	resize(400, 200);

}

MouseEvent::~MouseEvent()
{

}
void MouseEvent::mousePressEvent(QMouseEvent *e){
	QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";

	if (e->button()==Qt::LeftButton)
	{
		statusBar()->showMessage(tr("leftButton:") + str);
	}
	else if (e->button()==Qt::RightButton)
	{
		statusBar()->showMessage(tr("rightButton:") + str);
	}
	else if (e->button()==Qt::MiddleButton)
	{
		statusBar()->showMessage(tr("midButton:") + str);
	}
}
void MouseEvent::mouseMoveEvent(QMouseEvent *e){
	MousePosLabel->setText("(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")");
}
void MouseEvent::mouseReleaseEvent(QMouseEvent *e){
	QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
	statusBar()->showMessage(tr("Release:") + str,3000);
}
void MouseEvent::mouseDoubleClickEvent(QMouseEvent *e){}