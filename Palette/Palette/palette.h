#ifndef PALETTE_H
#define PALETTE_H

#include <QtWidgets/QDialog>
//#include "ui_palette.h"
#include "headers.h"

class Palette : public QDialog
{
	Q_OBJECT

public:
	Palette(QWidget *parent = 0);
	~Palette();
	void createCtrlFrame();
	void createContentFrame();
	void fillColorList(QComboBox *);

private:
	//Ui::PaletteClass ui;
	QFrame *ctrlFrame;
	QLabel *windowLabel;
	QComboBox *windowComboBox;
	QLabel *windowTextLabel;
	QComboBox *windowTextComboBox;
	QLabel *buttonLabel;
	QComboBox *buttonComboBox;
	QLabel *buttonTextLabel;
	QComboBox *buttonTextComboBox;
	QLabel *baseLabel;
	QComboBox *baseComboBox;

	QFrame *contentFrame;
	QLabel *lable1;
	QComboBox *comboBox1;
	QLabel *label2;
	QLineEdit *lineEdit2;
	QTextEdit *textEdit2;
	QPushButton *okBtn;
	QPushButton *cancelBtn;

	private slots:
	void showWindow();
	void showWindowText();
	void showButton();
	void showButtonText();
	void showBase();
};

#endif // PALETTE_H
