#include "GGSingleGame.h"
#include "GGGomokuGame.h"

GGSingleGame::GGSingleGame(GGGomokuGame* gomokuGame, QObject *parent)
	: QObject(parent)
{
	m_gomokuGame=gomokuGame;
}

GGSingleGame::~GGSingleGame()
{}
