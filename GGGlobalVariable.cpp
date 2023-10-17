#include "GGGlobalVariable.h"
#include <QScreen>
#include <QApplication>
#include "GGGameSetting.h"

GGGlobalVariable::~GGGlobalVariable()
{

}

GGGlobalVariable::GGGlobalVariable()
{
    // ��ȡ����Ļʵ��
    QScreen* primaryScreen = QApplication::primaryScreen();

    // ��ȡ����Ļ�ļ��ξ���
    QRect screenGeometry = primaryScreen->geometry();
    m_screenMainSize=QSize(screenGeometry.width(), screenGeometry.height());

    // �������ű���
    if (GGGameSetting::instance()->m_isZoom) {
        m_zoomWidth=m_screenMainSize.width()/m_defaultWidth;
        m_zoomHeight=m_screenMainSize.height()/m_defaultHeight;
    }
    else {
        m_zoomWidth=1.0;
        m_zoomHeight=1.0;
    }

    // ��������
    m_chessboardType=ChessBoardType_1515;
}
