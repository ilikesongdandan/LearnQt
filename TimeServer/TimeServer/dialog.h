#ifndef DIALOG_H
#define DIALOG_H

#include "headers.h"
#include <QtWidgets/QDialog>
#include "ui_dialog.h"

class TimeServer;

class Dialog : public QDialog
{
	Q_OBJECT

public:
	Dialog(QWidget *parent = 0);
	~Dialog();

private:
	Ui::DialogClass ui;

	QLabel *label1;
	QLabel *label2;
	QPushButton *quitBtn;

	TimeServer *timeServer;
	int count;
public slots:
	void slotSHow();
};

#endif // DIALOG_H
