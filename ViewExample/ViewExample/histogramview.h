#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QtWidgets/QAbstractItemView>
#include "headers.h"

class HistogramView : public QAbstractItemView
{
	Q_OBJECT

public:
	HistogramView(QWidget *parent=0);
	~HistogramView();

	QRect visualRect(const QModelIndex &index)const;
	void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
	QModelIndex indexAt(const QPoint &point)const;
	//Ϊselections����ֵ
	void setSelectionModel(QItemSelectionModel *selectionModel);
	QRegion itemRegion(QModelIndex index);

	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *event);

protected slots:
	void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
	void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);

protected:
	QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
	int horizontalOffset()const;
	int verticalOffset()const;
	bool isIndexHidden(const QModelIndex &index)const;
	void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags);
	QRegion visualRegionForSelection(const QItemSelection &selection)const;

private:
	QItemSelectionModel *selections;
	QList<QRegion> MRegionList;
	QList<QRegion> FRegionList;
	QList<QRegion> SRegionList;
};

#endif // HISTOGRAMVIEW_H