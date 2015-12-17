#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QtWidgets/QWidget>
#include "headers.h"
class showWidget : public QWidget
{
	Q_OBJECT

public:
	showWidget(QWidget *parent=0);
	~showWidget();
	QImage img;
	QLabel *imagelabel;
	QTextEdit *text;
signals:

public slots:
	
private:
	
};

#endif // SHOWWIDGET_H
