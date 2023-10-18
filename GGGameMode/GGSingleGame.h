#pragma once

#include <QObject>

/**
 * ����ģʽ
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
