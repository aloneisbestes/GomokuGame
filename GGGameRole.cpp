#include "GGGameRole.h"

GGGameRole::GGGameRole(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::GGGameRoleClass())
{
	ui->setupUi(this);
}

GGGameRole::~GGGameRole()
{
	delete ui;
}
