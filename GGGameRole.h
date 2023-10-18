#pragma once

#include <QWidget>
#include "ui_GGGameRole.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GGGameRoleClass; };
QT_END_NAMESPACE

class GGGameRole : public QWidget
{
	Q_OBJECT

public:
	GGGameRole(QWidget *parent = nullptr);
	~GGGameRole();

private:
	Ui::GGGameRoleClass *ui;
};
