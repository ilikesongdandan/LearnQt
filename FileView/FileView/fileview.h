#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QtWidgets/QDialog>
//#include "ui_fileview.h"
#include "headers.h"

class FileView : public QDialog
{
	Q_OBJECT

public:
	FileView(QWidget *parent = 0);
	~FileView();
	void showFileInfoList(QFileInfoList list);
private:
	//Ui::FileViewClass ui;
public slots :
	void slotShow(QDir dir);
	void slotDirShow(QListWidgetItem *item);
private: 
	QLineEdit *fileLineEdit;
	QListWidget *fileListWidget;
	QVBoxLayout *mainlayout;
};

#endif // FILEVIEW_H
