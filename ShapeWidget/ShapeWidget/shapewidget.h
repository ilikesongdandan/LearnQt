#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include "headers.h"
#include <QtWidgets/QWidget>
//#include "ui_shapewidget.h"

class ShapeWidget : public QWidget
{
	Q_OBJECT

public:
	ShapeWidget(QWidget *parent = 0);
	~ShapeWidget();
protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);
private:
	//Ui::ShapeWidgetClass ui;
	QPoint dragPosition;
};

#endif // SHAPEWIDGET_H
