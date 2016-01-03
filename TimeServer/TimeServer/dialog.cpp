#include "dialog.h"
#include "timeserver.h"

Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowTitle(tr("Thread Time Server"));
	label1 = new QLabel(tr("Server port£º"));
	label2 = new QLabel;

	quitBtn = new QPushButton(tr("Quit"));
	QHBoxLayout *BtnLayout = new QHBoxLayout;
	BtnLayout->addStretch(1);
	BtnLayout->addWidget(quitBtn);
	BtnLayout->addStretch(1);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(label1);
	mainLayout->addWidget(label2);
	mainLayout->addLayout(BtnLayout);

	connect(quitBtn, SIGNAL(clicked()), this, SLOT(close()));

	count = 0;
	timeServer = new TimeServer(this);
	if (!timeServer->listen())
	{
		QMessageBox::critical(this, tr("Thread Time Server"),tr("cannot start sever:%1.").arg(timeServer->errorString()));
		close();
		return;
	}
	label1->setText(tr("server port:%1.").arg(timeServer->serverPort()));

}

Dialog::~Dialog()
{

}
void Dialog::slotSHow(){
	label2->setText(tr("%1 times request.").arg(++count));
}