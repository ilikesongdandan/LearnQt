#ifndef COMBODELEGATE_H
#define COMBODELEGATE_H

#include <QtWidgets/QItemDelegate>
#include "headers.h"

class ComboDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	ComboDelegate(QObject *parent=0);
	~ComboDelegate();
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex	&index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const  QModelIndex &index) const;
private:
	
};

#endif // COMBODELEGATE_H
