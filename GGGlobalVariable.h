#ifndef __GG_GLOBAL_VARIABLE_H__
#define __GG_GLOBAL_VARIABLE_H__

/**
 * 全局相关变量
 */

#include <QSize>
#include "GGCommon.h"

class GGGlobalVariable
{
public:
	~GGGlobalVariable();

	static GGGlobalVariable* instance() {
		static GGGlobalVariable* ins=new GGGlobalVariable();
		return ins;
	}

public:
	QSize m_screenMainSize;

	qreal m_zoomWidth;
	qreal m_zoomHeight;

	GGChessboardType m_chessboardType;

private:
	GGGlobalVariable();
	GGGlobalVariable(const GGGlobalVariable& other)=delete;
	void operator=(const GGGlobalVariable& other)=delete;
	GGGlobalVariable(GGGlobalVariable&& other)=delete;

	const qreal m_defaultWidth=1920.0;
	const qreal m_defaultHeight=1080.0;
};


#endif // !__GG_GLOBAL_VARIABLE_H__

