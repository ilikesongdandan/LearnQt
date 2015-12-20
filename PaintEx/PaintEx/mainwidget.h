#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_mainwidget.h"
#include "paintarea.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

private:
	Ui::MainWidgetClass ui;
	paintArea *paintarea;

	QLabel *shapeLabel;
	QComboBox *shapeComboBox;
	QLabel *penWidthLabel;
	QSpinBox *penWidthSpinBox;
	QLabel *penColorLabel;
	QFrame *penColorFrame;
	QPushButton *penColorBtn;
	QLabel *penStyleLabel;
	QComboBox *penStyleComboBox;
	QLabel *penCapLabel;
	QComboBox *penCapComboBox;
	QLabel *penJoinLabel;
	QComboBox *penJoinComboBox;
	QLabel *fillRuleLabel;
	QComboBox *fillRuleComboBox;
	QLabel *spreadLabel;
	QComboBox *spreadComboBox;
	QGradient::Spread spread;
	QLabel *brushStyleLabel;
	QComboBox *brushStyleComboBox;
	QLabel *brushColorlabel;
	QFrame *brushColorFrame;
	QPushButton *brushColorBtn;

	QGridLayout *rightLayout;
protected slots:
	void showShape(int);
	void showPenWidth(int);
	void showPenColor();
	void showPenStyle(int);
	void showPenCap(int);
	void showPenJoin(int);
	void showSpreadStyle();
	void showFillRule();
	void showBrushColor();
	void showBrush(int);
};

#endif // MAINWIDGET_H
