#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtWidgets/QDialog>
#include "headers.h"
//#include "ui_tcpserver.h"
#include "server.h"
class TcpServer : public QDialog
{
	Q_OBJECT

public:
	TcpServer(QWidget *parent = 0);
	~TcpServer();

private:
	//Ui::TcpServerClass ui;
	QListWidget *ContentListWidget;
	QLabel *PortLabel;
	QLineEdit *PortLineEdit;
	QPushButton *CreateBtn;
	QGridLayout *mainLayout;

	int port;
	Server *server;
public slots:
	void slotCreateServer();
	void updateServer(QString, int);

};

#endif // TCPSERVER_H
