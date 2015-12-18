#include "showwidget.h"


showWidget::showWidget(QWidget *parent)
	: QWidget(parent)
{
	imagelabel = new QLabel;
	imagelabel->setScaledContents(true);
	
	text = new QTextEdit;
	
	QHBoxLayout *mainlayout = new QHBoxLayout(this);

	
	mainlayout->addWidget(imagelabel);
	mainlayout->addWidget(text);
	//mainlayout->setSizeConstraint(QLayout::SetFixedSize);
	
}

showWidget::~showWidget()
{

}
