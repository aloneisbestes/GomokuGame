#include "GGGlobalVariable.h"
#include <QScreen>
#include <QApplication>
#include "GGGameSetting.h"

GGGlobalVariable::~GGGlobalVariable()
{

}

GGGlobalVariable::GGGlobalVariable()
{
    // 获取主屏幕实例
    QScreen* primaryScreen = QApplication::primaryScreen();

    // 获取主屏幕的几何矩形
    QRect screenGeometry = primaryScreen->geometry();
    m_screenMainSize=QSize(screenGeometry.width(), screenGeometry.height());

    // 设置缩放比例
    if (GGGameSetting::instance()->m_isZoom) {
        m_zoomWidth=m_screenMainSize.width()/m_defaultWidth;
        m_zoomHeight=m_screenMainSize.height()/m_defaultHeight;
    }
    else {
        m_zoomWidth=1.0;
        m_zoomHeight=1.0;
    }

    // 棋盘类型
    m_chessboardType=ChessBoardType_1515;
}
