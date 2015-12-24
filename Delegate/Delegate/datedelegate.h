#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QtWidgets/QItemDelegate>
#include "headers.h"

class DateDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	DateDelegate(QObject *parent=0);
	~DateDelegate();

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
	
};

#endif // DATEDELEGATE_H
