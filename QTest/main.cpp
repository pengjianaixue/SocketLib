#include "QTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QApplication::setStyle("Fusion");
	QTest w;
	w.setWindowTitle("InstrumentContrlAssistnt");
	QIcon icon;
	QSize IcoSize;
	IcoSize.setHeight(30);
	IcoSize.setWidth(40);
	icon.addFile(QStringLiteral("./ImageResource/Test.ico"), IcoSize, QIcon::Active, QIcon::On);
	w.setWindowIcon(icon);
	w.show();
	return a.exec();
}
