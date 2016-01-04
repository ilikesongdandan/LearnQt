#include "headers.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setHostName("wangjj");
	db.setDatabaseName("wangjj.db");
	db.setUserName("wangjunjie");
	db.setPassword("1234567890");
	db.open();

	bool ret = db.open();
	if (ret)
		qDebug() << "true" << endl;

	//创建数据库表
	QSqlQuery query(db);
	bool success = query.exec("create table automobil(id int primary key,attribute varchar(20),type varchar(20),kind varchar(20),nation int,carnumber int,elevaltor int,distance int,oil int,temperature int)");
	if (success)
		qDebug() << QObject::tr("succeed! \n");
	else
		qDebug() << QObject::tr("fail! \n");

	//查询
	query.exec("select * from automobil");
	QSqlRecord rec = query.record();
	qDebug() << QObject::tr("automobil number of table fileds:") << rec.count();

	//插入
	QTime t;
	t.start();
	query.prepare("insert into automobil values(?,?,?,?,?,?,?,?,?,?)");

	long records = 100;
	for (int i = 0; i < records; i++)
	{
		query.bindValue(0, i);
		query.bindValue(1, "four-wheel");
		query.bindValue(2, "car");
		query.bindValue(3, "fukang");
		query.bindValue(4, rand() % 100);
		query.bindValue(5, rand() % 10000);
		query.bindValue(6, rand() % 300);
		query.bindValue(7, rand() % 200000);
		query.bindValue(8, rand() % 52);
		query.bindValue(9, rand() % 100);

		success = query.exec();
		if (!success)
		{
			QSqlError lastError = query.lastError();
			qDebug() << lastError.driverText() << QString(QObject::tr("insert fail"));
		}
	}
	qDebug() << QObject::tr("insert %1 record，cost:%2 ms").arg(records).arg(t.elapsed());

	//排序
	t.restart();
	success = query.exec("select * from automobil order by id desc");
	if (success)
		qDebug() << QObject::tr("sort %1 record，cost:%2 ms").arg(records).arg(t.elapsed());
	else
		qDebug() << QObject::tr("sort fail");

	//更新记录
	t.restart();
	for (int i = 0; i < records; i++)
	{
		query.clear();
		query.prepare(QString("update automobil set attribute=?,type=?,"
			"kind=?,nation=?,"
			"carnumber=?,elevaltor=?,"
			"distance=?,oil=?,"
			"temperature=? where id=%1").arg(i));

		query.bindValue(0, "four-wheel");
		query.bindValue(1, "car");
		query.bindValue(2, "fukang");
		query.bindValue(3, rand() % 100);
		query.bindValue(4, rand() % 10000);
		query.bindValue(5, rand() % 300);
		query.bindValue(6, rand() % 200000);
		query.bindValue(7, rand() % 52);
		query.bindValue(8, rand() % 100);

		success = query.exec();
		if (!success)
		{
			QSqlError lastError = query.lastError();
			qDebug() << lastError.driverText() << QString(QObject::tr("update fail "));
		}
	}
	qDebug() << QObject::tr("update %1 record，cost:%2 ms").arg(records).arg(t.elapsed());

	//删除
	t.restart();
	query.exec("delete from automobil where id=15");
	qDebug() << QObject::tr("delete a record，cost:%1 ms").arg(t.elapsed());

	//return 0;

	//return a.exec();
}
