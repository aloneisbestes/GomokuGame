#pragma once

#include <QGraphicsScene>

class GGGraphicsMapScene  : public QGraphicsScene
{
	Q_OBJECT

public:
	GGGraphicsMapScene(QObject *parent=nullptr);
	~GGGraphicsMapScene();
};
