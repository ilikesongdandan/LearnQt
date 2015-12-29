#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include "headers.h"
#include <QtWidgets/QMainWindow>
//#include "ui_udpclient.h"

class UdpClient : public QDialog
{
	Q_OBJECT

public:
	UdpClient(QWidget *parent = 0);
	~UdpClient();

private:
	//Ui::UdpClientClass ui;
	QTextEdit *ReceiveTextEdit;
	QPushButton *CloseBtn;
	QVBoxLayout *mainLayout;
	int port;
	QUdpSocket *udpSocket;
public slots:
	void CloseBtnClicked();
	void dataReceived();
};

#endif // UDPCLIENT_H
