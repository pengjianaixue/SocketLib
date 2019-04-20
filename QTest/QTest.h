#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InstumentSet.h"
#include "CSockt.h"
class QTest : public QMainWindow
{

	Q_OBJECT
public:
	QTest(QWidget *parent = Q_NULLPTR);
	~QTest();
private:
	void InitUi();
public slots:
	int CmdSend();
private:
	Ui::QTestClass ui;
	CSockt  *m_socktCommuni;
signals:
	void  recvi(std::string recvi);
public slots:
	void DisplayRecvi(std::string recvi);


};
