#ifndef MODELEX_H
#define MODELEX_H

#include <QtWidgets/QMainWindow>
#include "ui_modelex.h"
#include "headers.h"
#include <QtCore/QMap>
#include <QtCore/QVector>
#include <QtCore/QStringList>

class ModelEx : public QMainWindow,public QAbstractTableModel
{
	Q_OBJECT

public:
	ModelEx(QWidget *parent = 0);
	~ModelEx();
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
signals:
public slots:
	
private:
	Ui::ModelExClass ui;
	QVector<short> army;
	QVector<short> weaponType;
	QMap<short, QString> armyMap;
	QMap<short, QString> weaponTypeMap;
	QStringList weapon;
	QStringList header;
	void populateModel();
};

#endif // MODELEX_H
