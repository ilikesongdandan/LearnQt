#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtWidgets/QDialog>
//#include "ui_tcpclient.h"
#include "headers.h"

class TcpClient : public QDialog
{
	Q_OBJECT

public:
	TcpClient(QWidget *parent = 0);
	~TcpClient();

private:
	//Ui::TcpClientClass ui;
	QListWidget *contentListWidget;
	QLineEdit *sendLineEdit;
	QPushButton *sendBtn;
	QLabel *userNameLabel;
	QLineEdit *userNameLineEdit;
	QLabel *serverIPLabel;
	QLineEdit *serverIPLineEdit;
	QLabel *portLabel;
	QLineEdit *portLineEdit;
	QPushButton *enterBtn;
	QGridLayout *mainLayout;

	bool status;
	int port;
	QHostAddress *serverIP;
	QString userName;
	QTcpSocket *tcpSocket;
public slots:
	void slotEnter();
	void slotConnected();
	void slotDisconnected();
	void dataReceived();
	void slotSend();
};

#endif // TCPCLIENT_H
