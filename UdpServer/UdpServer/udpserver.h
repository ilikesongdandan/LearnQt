#ifndef UDPSERVER_H
#define UDPSERVER_H
#include "headers.h"
#include <QtWidgets/QDialog>
//#include "ui_udpserver.h"

class UdpServer : public QDialog
{
	Q_OBJECT

public:
	UdpServer(QWidget *parent = 0);
	~UdpServer();

private:
	//Ui::UdpServerClass ui;
	QLabel *TimerLabel;
	QLineEdit *TextLineEdit;
	QPushButton *StartBtn;
	QVBoxLayout *mainLayout;

	int port;
	bool isStarted;
	QUdpSocket *UdpSocket;
	QTimer *timer;
public slots:
	void StartBtnClicked();
	void timeout();
};

#endif // UDPSERVER_H
