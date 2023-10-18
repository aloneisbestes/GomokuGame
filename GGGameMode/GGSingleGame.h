#pragma once

#include <QObject>

/**
 * 单机模式
 */

class GGGomokuGame;

class GGSingleGame  : public QObject
{
	Q_OBJECT

public:
	GGSingleGame(GGGomokuGame *gomokuGame, QObject *parent=nullptr);
	~GGSingleGame();

private:
	GGGomokuGame* m_gomokuGame;
};
