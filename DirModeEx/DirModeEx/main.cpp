#include "dirmodeex.h"
#include <QtWidgets/QApplication>
#include <QtCore/QAbstractItemModel>
#include <QtWidgets/QAbstractItemView>
#include <QtCore/QItemSelectionModel>

#include <QtWidgets/QDirModel>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QListView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QSplitter>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDirModel model;
	QListView list;
	QTreeView tree;
	QTableView table;
	tree.setModel(&model);
	list.setModel(&model);
	table.setModel(&model);
	
	tree.setSelectionMode(QAbstractItemView::MultiSelection);

	list.setSelectionModel(tree.selectionModel());
	//list.setSelectionMode(QAbstractItemView::MultiSelection);
	table.setSelectionModel(tree.selectionModel());
	//table.setSelectionMode(QAbstractItemView::MultiSelection);

	QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &list, SLOT(setRootIndex(QModelIndex)));
	QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &table, SLOT(setRootIndex(QModelIndex)));

	QSplitter *splitter = new QSplitter;
	splitter->addWidget(&tree);
	splitter->addWidget(&list);
	splitter->addWidget(&table);
	splitter->setWindowTitle(QObject::tr("Model/View"));
	splitter->show();

	//DirModeEx w;
	//w.show();
	return a.exec();
}
