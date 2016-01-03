#include "timeclient.h"

TimeClient::TimeClient(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Thread Time Client"));

	serverNameLabel = new QLabel(tr("Server Name:"));
	serverNameLineEdit = new QLineEdit("Local host");

	portLabel = new QLabel(tr("Port:"));
	portLineEdit = new QLineEdit;

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(serverNameLabel, 0, 0);
	layout->addWidget(serverNameLineEdit, 0, 1);
	layout->addWidget(portLabel, 1, 0);
	layout->addWidget(portLineEdit, 1, 1);

	dateTimeEdit = new QDateTimeEdit(this);
	QHBoxLayout *layout1 = new QHBoxLayout;
	layout1->addWidget(dateTimeEdit);

	stateLabel = new QLabel(tr("Please start server time!"));
	QHBoxLayout *layout2 = new QHBoxLayout;
	layout2->addWidget(stateLabel);

	getBtn = new QPushButton(tr("get time"));
	getBtn->setDefault(true);
	getBtn->setEnabled(false);
	quitBtn = new QPushButton(tr("quit"));
	QHBoxLayout *layout3 = new QHBoxLayout;
	layout3->addStretch();
	layout3->addWidget(getBtn);
	layout3->addWidget(quitBtn);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(layout);
	mainLayout->addLayout(layout1);
	mainLayout->addLayout(layout2);
	mainLayout->addLayout(layout3);

	connect(serverNameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableGetBtn()));
	connect(portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableGetBtn()));
	connect(getBtn, SIGNAL(clicked()), this, SLOT(getTime()));
	connect(quitBtn, SIGNAL(clicked()), this, SLOT(close()));

	tcpSocket = new QTcpSocket(this);
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTime()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(showError(QAbstractSocket::SocketError)));

	portLineEdit->setFocus();

}

TimeClient::~TimeClient()
{

}
void TimeClient::enableGetBtn()
{
	getBtn->setEnabled(!serverNameLineEdit->text().isEmpty() && !portLineEdit->text().isEmpty());
}
void TimeClient::getTime()
{
	getBtn->setEnabled(false);
	time2u = 0;
	tcpSocket->abort();
	tcpSocket->connectToHost(serverNameLineEdit->text(), portLineEdit->text().toInt());
}

void TimeClient::readTime()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_3);
	if (time2u == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(uint))
			return;
		in >> time2u;
	}
	dateTimeEdit->setDateTime(QDateTime::fromTime_t(time2u));
	getBtn->setEnabled(true);
}

void TimeClient::showError(QAbstractSocket::SocketError socketError)
{
	switch (socketError)
	{
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, tr("Time Server"), tr("Host cannot reach"));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Time Server Client"), tr("Reach is refuse"));
		break;
	default:
		QMessageBox::information(this, tr("Time Server Client"), tr("Ereor: %1.").arg(tcpSocket->errorString()));
	}
	getBtn->setEnabled(true);
}
