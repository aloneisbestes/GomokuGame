#include "GGGomokuGame.h"
#include "GGGraphicsMapView.h"

GGGomokuGame::GGGomokuGame(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::GGGomokuGameClass())
{
	ui->setupUi(this);

	m_graphicsMapView=new GGGraphicsMapView(this);
	ui->hl_gomokuMap->addWidget(m_graphicsMapView);
}

GGGomokuGame::~GGGomokuGame()
{
	delete ui;
}
