#ifndef SVGWIDGET_H
#define SVGWIDGET_H
#include "headers.h"

#include <QtSvg/QtSvg>
#include <QtSvg/QSvgWidget>
#include <QtSvg/QSvgRenderer>


class SvgWidget : public QSvgWidget
{
	Q_OBJECT

public:
	SvgWidget(QWidget *parent=0);
	~SvgWidget();
	void wheelEvent(QWheelEvent *);
private:
	QSvgRenderer *render;
};

#endif // SVGWIDGET_H
