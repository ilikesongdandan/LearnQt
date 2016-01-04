#ifndef CONNDLG_H
#define CONNDLG_H
#include "headers.h"
#include <QtWidgets/QDialog>
#include "ui_conndlg.h"

class QSqlError;

class ConnDlg : public QDialog
{
	Q_OBJECT

public:
	ConnDlg(QWidget *parent = 0);
	~ConnDlg();

private:
	Ui::QSqlConnectionDialogUi ui;
	QString driverName() const;
	QString databaseName() const;
	QString userName() const;
	QString password() const;
	QString hostName() const;
	int port() const;
	QSqlError addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port = -1);
	void creatDB();
	void addSqliteConnection();
private slots:
	void on_okButton_clicked();
	void on_cancelButton_clicked() { reject(); }
	void driverChanged(const QString &);
};

#endif // CONNDLG_H
