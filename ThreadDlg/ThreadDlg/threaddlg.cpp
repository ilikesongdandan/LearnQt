#include "threaddlg.h"

ThreadDlg::ThreadDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("Thread"));

	startBtn = new QPushButton(tr("Start"));
	stopBtn = new QPushButton(tr("Stop"));
	quitBtn = new QPushButton(tr("Quit"));

	mainLayout = new QHBoxLayout(this);

	mainLayout->addWidget(startBtn);
	mainLayout->addWidget(stopBtn);
	mainLayout->addWidget(quitBtn);

	connect(startBtn, SIGNAL(clicked()), this, SLOT(slotStart()));
	connect(stopBtn, SIGNAL(clicked()), this, SLOT(slotStop()));
	connect(quitBtn, SIGNAL(clicked()), this, SLOT(close()));

}

ThreadDlg::~ThreadDlg()
{

}
void ThreadDlg::slotStart(){
	for (int i = 0; i < MAXSIZE;++i)
	{
		workThread[i] = new WorkThread();
	}
	for (int i = 0; i < MAXSIZE;++i)
	{
		workThread[i]->start();
	}
	startBtn->setEnabled(false);
	stopBtn->setEnabled(true);
}
void ThreadDlg::slotStop(){
	for (int i = 0; i < MAXSIZE;i++)
	{
		workThread[i]->terminate();
		workThread[i]->wait();
	}
	startBtn->setEnabled(true);
	stopBtn->setEnabled(false);
}