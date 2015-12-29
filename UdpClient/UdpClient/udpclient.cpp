#include "udpclient.h"

UdpClient::UdpClient(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("UDP Client"));

	ReceiveTextEdit = new QTextEdit;
	CloseBtn = new QPushButton(tr("close"));

	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(ReceiveTextEdit);
	mainLayout->addWidget(CloseBtn);

	connect(CloseBtn, SIGNAL(clicked()), this, SLOT(CloseBtnClicked()));

	port = 5555;
	udpSocket = new QUdpSocket(this);
	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));

	bool result = udpSocket->bind(port);
	if (!result)
	{
		QMessageBox::information(this, tr("error"), tr("udp socket create error!"));
		return;
	}
}

UdpClient::~UdpClient()
{

}
void UdpClient::CloseBtnClicked(){
	close();
}
void UdpClient::dataReceived(){
	while (udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());
		QString msg = datagram.data();
		ReceiveTextEdit->insertPlainText(msg);

	}
}