#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent)
	: QScrollArea(parent)
{
	svgWidget = new SvgWidget;
	setWidget(svgWidget);
}

SvgWindow::~SvgWindow()
{

}
void SvgWindow::setFile(QString filename){
	svgWidget->load(filename);
	QSvgRenderer *render = svgWidget->renderer();
	svgWidget->resize(render->defaultSize());
}
void SvgWindow::mousePressEvent(QMouseEvent *event)
{
	mousePressPos = event->pos();
	scrollBarValuesOnMousePress.rx() = horizontalScrollBar()->value();
	scrollBarValuesOnMousePress.ry() = verticalScrollBar()->value();
	event->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
	horizontalScrollBar()->setValue(scrollBarValuesOnMousePress.x() - event->pos().x() + mousePressPos.x());	//��ˮƽ����������λ�ý�������
	verticalScrollBar()->setValue(scrollBarValuesOnMousePress.y() - event->pos().y() + mousePressPos.y());      //�Դ�ֱ����������λ�ý�������
	horizontalScrollBar()->update();
	verticalScrollBar()->update();
	event->accept();
}