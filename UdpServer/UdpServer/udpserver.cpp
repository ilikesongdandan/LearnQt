#include "udpserver.h"

UdpServer::UdpServer(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("UDP Server"));

	TimerLabel = new QLabel(tr("Timer:"));
	TextLineEdit = new QLineEdit;
	StartBtn = new QPushButton(tr("start"));

	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(TimerLabel);
	mainLayout->addWidget(TextLineEdit);
	mainLayout->addWidget(StartBtn);

	connect(StartBtn, SIGNAL(clicked()), this, SLOT(StartBtnClicked()));

	port = 5555;
	isStarted = false;
	UdpSocket = new QUdpSocket(this);
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

UdpServer::~UdpServer()
{

}
void UdpServer::StartBtnClicked(){
	if (!isStarted)
	{
		StartBtn->setText(tr("stop"));
		timer->start(1000);
		isStarted = true;
	}
	else
	{
		StartBtn->setText(tr("start"));
		//timer->start(1000);
		isStarted = false;
		timer->stop();
	}
}

void UdpServer::timeout(){
	QString msg = TextLineEdit->text();
	int length = 0;
	if (msg=="")
	{
		return;
	}
	if ((length=UdpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length())
	{
		return;
	}
}