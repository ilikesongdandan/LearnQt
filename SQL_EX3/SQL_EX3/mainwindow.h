#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "headers.h"


#include <QtWidgets/QMainWindow>
//#include "ui_mainwindow.h"
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlTableModel>
#include <QtCore/QModelIndex>
#include <QtXml/QDomNode>
#include <QtXml/QDomDocument>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	//MainWindow(QWidget *parent = 0);
	MainWindow(const QString &factoryTable, const QString &carTable, QFile *carDetails, QWidget *parent = 0);   //¹¹Ôìº¯Êý
	~MainWindow();

private:
	//Ui::MainWindowClass ui;
	QGroupBox *createCarGroupBox();
	QGroupBox *createFactoryGroupBox();
	QGroupBox *createDetailsGroupBox();
	void createMenuBar();

	QTableView *carView;
	QTableView *factoryView;

	QListWidget *attribList;

	QLabel *profileLabel;
	QLabel *titleLabel;

	void decreaseCarCount(QModelIndex index);
	void getAttribList(QDomNode car);
	QModelIndex indexOfFactory(const QString &factory);
	void readCarData();
	void removeCarFromDatabase(QModelIndex index);
	void removeCarFromFile(int id);

	QDomDocument carData;
	QFile *file;
	QSqlRelationalTableModel *carModel;
	QSqlTableModel *factoryModel;
private slots:
	void addCar();
	void changeFactory(QModelIndex index);
	void delCar();
	void showCarDetails(QModelIndex index);
	void showFactorytProfile(QModelIndex index);

};

#endif // MAINWINDOW_H
