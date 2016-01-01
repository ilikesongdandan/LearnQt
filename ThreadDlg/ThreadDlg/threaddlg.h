#ifndef THREADDLG_H
#define THREADDLG_H

#include <QtWidgets/QDialog>
#include "ui_threaddlg.h"
#include "headers.h"
#include "workthread.h"

#define  MAXSIZE 1


class ThreadDlg : public QDialog
{
	Q_OBJECT

public:
	ThreadDlg(QWidget *parent = 0);
	~ThreadDlg();

private:
	Ui::ThreadDlgClass ui;

	QPushButton *startBtn;
	QPushButton *stopBtn;
	QPushButton *quitBtn;

	QHBoxLayout *mainLayout;


public slots:
	void slotStart();
	void slotStop();
private:
	WorkThread *workThread[MAXSIZE];
};

#endif // THREADDLG_H
