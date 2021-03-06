#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <QtGui/QtGui>
#include <QtSql/QtSql>
#include <QtXml/QtXml>
#include <QtWidgets/QDialogButtonBox>
#include "headers.h"

#include "ui_conndlg.h"
class Dialog : public QDialog
{
	Q_OBJECT

public:
	Dialog(QSqlRelationalTableModel *cars, QSqlTableModel *factory, QDomDocument details, QFile *output, QWidget *parent = 0);
	~Dialog();
private slots:
	void revert();
	void submit();

private:
	int addNewCar(const QString &name, int factoryId);
	int addNewFactory(const QString &factory, const QString &address);
	void addAttribs(int carId, QStringList attribs);
	QDialogButtonBox *createButtons();
	QGroupBox *createInputWidgets();
	int findFactoryId(const QString &factory);
	int generateCarId();
	int generateFactoryId();

	QSqlRelationalTableModel *carModel;
	QSqlTableModel *factoryModel;
	QDomDocument carDetails;
	QFile *outputFile;

	QLineEdit *factoryEditor;
	QLineEdit *addressEditor;
	QLineEdit *carEditor;
	QSpinBox *yearEditor;
	QLineEdit *attribEditor;
};

#endif // DIALOG_H
