#ifndef FILEINFO_H
#define FILEINFO_H
#include "headers.h"
#include <QtWidgets/QDialog>
//#include "ui_fileinfo.h"

class FileInfo : public QDialog
{
	Q_OBJECT

public:
	FileInfo(QWidget *parent = 0,Qt::WindowFlags f=0);
	~FileInfo();

private:
	//Ui::FileInfoClass ui;
public slots :
	void slotFile();
	void slotGet();
private:
	QLabel *fileNameLabel;
	QLineEdit *fileNameLineEdit;
	QPushButton *fileBtn;

	QLabel *sizeLabel;
	QLineEdit *sizeLineEdit;

	QLabel *createTimeLabel;
	QLineEdit *createTimeLineEdit;

	QLabel *lastModifiedLabel;
	QLineEdit *lastModifiedLineEdit;

	QLabel *lastReadLabel;
	QLineEdit *lastReadLineEdit;

	QLabel *propertyLabel;
	QCheckBox *isDirCheckBox;
	QCheckBox *isFileCheckBox;
	QCheckBox *isSymLinkCheckBox;
	QCheckBox *isHiddenCheckBox;
	QCheckBox *isReadableCheckBox;
	QCheckBox *isWritableCheckBox;
	QCheckBox *isExecutableCheckBox;

	QPushButton *getBtn;
};

#endif // FILEINFO_H
