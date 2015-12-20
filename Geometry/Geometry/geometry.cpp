#include "geometry.h"

Geometry::Geometry(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Geometry"));
	xLabel = new QLabel(tr("X():"));
	xValuelabel = new QLabel;
	ylabel = new QLabel(tr("Y():"));
	yValuelabel = new QLabel;
	FrmLabel = new QLabel(tr("Frame:"));
	FrmValueLabel = new QLabel;
	poslabel = new QLabel(tr("Pos():"));
	posvaluelabel = new QLabel;
	geoLabel = new QLabel(tr("geometry():"));
	geoValuelabel = new QLabel;
	widthLabel = new QLabel(tr("width():"));
	widthvaluelabel = new QLabel;
	heightLabel = new QLabel(tr("height():"));
	heightValueLabel = new QLabel;

	rectLabel = new QLabel(tr("rect():"));
	rectvaluelabel = new QLabel;
	sizelabel = new QLabel(tr("size():"));
	sizevalueLabel = new QLabel;

	mainlayout = new QGridLayout(this);
	mainlayout->addWidget(xLabel, 0, 0);
	mainlayout->addWidget(xValuelabel, 0, 1);
	mainlayout->addWidget(ylabel, 1, 0);
	mainlayout->addWidget(yValuelabel, 1, 1);
	mainlayout->addWidget(poslabel, 2, 0);
	mainlayout->addWidget(posvaluelabel, 2, 1);
	mainlayout->addWidget(FrmLabel, 3, 0);
	mainlayout->addWidget(FrmValueLabel, 3, 1);
	mainlayout->addWidget(geoLabel, 4, 0);
	mainlayout->addWidget(geoValuelabel, 4, 1);
	mainlayout->addWidget(widthLabel,5, 0);
	mainlayout->addWidget(widthvaluelabel, 5, 1);
	mainlayout->addWidget(heightLabel, 6, 0);
	mainlayout->addWidget(heightValueLabel, 6, 1);
	mainlayout->addWidget(rectLabel, 7, 0);
	mainlayout->addWidget(rectvaluelabel, 7, 1);
	mainlayout->addWidget(sizelabel, 8, 0);
	mainlayout->addWidget(sizevalueLabel, 8, 1);
	mainlayout->setMargin(15);
	mainlayout->setSpacing(10);
	updatelabel();
}

Geometry::~Geometry()
{

}
void Geometry::updatelabel(){
	QString xStr;
	xValuelabel->setText(xStr.setNum(x()));
	QString yStr;
	yValuelabel->setText(yStr.setNum(y()));

	QString frameStr;
	QString tempStr1, tempStr2, tempStr3, tempStr4;
	frameStr = tempStr1.setNum(frameGeometry().x()) + "," + tempStr2.setNum(frameGeometry().y()) + "," + tempStr3.setNum(frameGeometry().width()) + ","
		+ tempStr4.setNum(frameGeometry().height());
	FrmValueLabel->setText(frameStr);

	QString positionStr;
	QString tempStr11, tempStr22;
	positionStr = tempStr11.setNum(pos().x()) + "," + tempStr22.setNum(pos().y());
	posvaluelabel->setText(positionStr);

	QString geoStr;
	QString tempStr13, tempStr23, tempStr33, tempStr43;
	geoStr = tempStr13.setNum(geometry().x()) + "," + tempStr23.setNum(geometry().y()) + "," + tempStr33.setNum(geometry().width()) +","+ tempStr43.setNum(geometry().height());
	geoValuelabel->setText(geoStr);

	QString wStr, hStr;
	widthvaluelabel->setText(wStr.setNum(width()));
	heightValueLabel->setText(hStr.setNum(height()));

	QString rectStr;
	QString tempStr14, tempStr24, tempStr34, tempStr44;
	rectStr = tempStr14.setNum(rect().x()) + "," + tempStr24.setNum(rect().y()) + "," + tempStr34.setNum(rect().width()) + "," + tempStr44.setNum(rect().height());
	rectvaluelabel->setText(rectStr);

	QString sizeStr;
	QString tempStr15, tempStr25, tempStr35, tempStr45;
	sizeStr = tempStr15.setNum(size().width()) + "," + tempStr25.setNum(size().height());
	sizevalueLabel->setText(sizeStr);
}
void Geometry::moveEvent(QMoveEvent *){
	updatelabel();
}
void Geometry::resizeEvent(QResizeEvent *){
	updatelabel();
}
