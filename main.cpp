#include <QApplication>
#include "GGGomokuGame.h"

int main(int argc,char* argv[])
{
	QApplication a(argc,argv);

	GGGomokuGame gomokuGame;
	gomokuGame.show();

	return a.exec();
}
