#ifndef EXTENSIONDLG_H
#define EXTENSIONDLG_H

#include <QtWidgets/QDialog>
#include "headers.h"
//#include "ui_extensiondlg.h"

class ExtensionDlg : public QDialog
{
	Q_OBJECT

public:
	ExtensionDlg(QWidget *parent = 0);
	~ExtensionDlg();

private:
	//Ui::ExtensionDlgClass ui;
	void createBaseInfo();
	void createDetailInfo();
	QWidget *baseWidget;
	QWidget *detailWidget;
	private slots:
	void showDetailInfo();
};

#endif // EXTENSIONDLG_H
