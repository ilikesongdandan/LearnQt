#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtWidgets/QDialog>
#include "ui_geometry.h"
#include "headers.h"

class Geometry : public QDialog
{
	Q_OBJECT

public:
	Geometry(QWidget *parent = 0);
	~Geometry();
	void updatelabel();
private:
	Ui::GeometryClass ui;
	QLabel *xLabel;
	QLabel *ylabel;
	QLabel *xValuelabel;
	QLabel *yValuelabel;
	QLabel *FrmLabel;
	QLabel *FrmValueLabel;
	QLabel *poslabel;
	QLabel *posvaluelabel;
	QLabel *geoLabel;
	QLabel *geoValuelabel;
	QLabel *widthLabel;
	QLabel *widthvaluelabel;
	QLabel *heightLabel;
	QLabel *heightValueLabel;
	QLabel *rectLabel;
	QLabel *rectvaluelabel;
	QLabel *sizelabel;
	QLabel *sizevalueLabel;

	QGridLayout *mainlayout;
protected slots:
	void moveEvent(QMoveEvent *);
	void resizeEvent(QResizeEvent *);

};

#endif // GEOMETRY_H
