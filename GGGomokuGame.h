#pragma once

#include <QWidget>
#include "ui_GGGomokuGame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GGGomokuGameClass; };
QT_END_NAMESPACE


class GGGraphicsMapView;

class GGGomokuGame : public QWidget
{
	Q_OBJECT

public:
	GGGomokuGame(QWidget *parent = nullptr);
	~GGGomokuGame();

private:
	Ui::GGGomokuGameClass *ui;

	GGGraphicsMapView* m_graphicsMapView;
};
