#include "QTest.h"

QTest::QTest(QWidget *parent): QMainWindow(parent),m_socktCommuni(nullptr)
{
	
	m_socktCommuni = new CSockt("127.0.0.1", "8080", SOCKTTYPE::TCP, CLIENTTYPE::Server);
	ui.setupUi(this);
	InitUi();
	QObject::connect(this->ui.pushButton, &QPushButton::clicked,this, &QTest::CmdSend);
	QObject::connect(this, &QTest::recvi, this, &QTest::DisplayRecvi);
	

}
QTest::~QTest()
{
	delete m_socktCommuni;
}
void QTest::InitUi()
{
	QStringList StrListSaItems;
	StrListSaItems.append("LAN");
	StrListSaItems.append("GPIB");
	StrListSaItems.append("SERIAL");
	StrListSaItems.append("USB");
	ui.comboBox->addItems(StrListSaItems);
	ui.comboBox_2->addItems(StrListSaItems);
	ui.comboBox_3->addItems(StrListSaItems);
	StrListSaItems.clear();
	StrListSaItems.append("SA");
	StrListSaItems.append("SG");
	StrListSaItems.append("ENA");
	StrListSaItems.append("RRU");
	StrListSaItems.append("RUMA");
	ui.comboBox_6->addItems(StrListSaItems);

}
int QTest::CmdSend()
{

	if(!m_socktCommuni->IsConnect())
	{
		m_socktCommuni->Connect();
	}
	QString Cmd = ui.editcmd->text();
	std::string recvi = "";
	m_socktCommuni->Recvi(recvi, 1000);
	m_socktCommuni->SendData(Cmd.toStdString(), 3);
	emit this->recvi(recvi);
	return 0;
}
void QTest::DisplayRecvi(std::string recvi)
{

	ui.textEdit->insertPlainText(recvi.c_str());

}

