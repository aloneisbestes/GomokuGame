#ifndef __GG_GAME_SETTING_H__
#define __GG_GAME_SETTING_H__

/**
 * 设置
 */

class GGGameSetting
{
public:
	~GGGameSetting();

	static GGGameSetting* instance() {
		static GGGameSetting* ins=new GGGameSetting();
		return ins;
	}

public:
	bool m_isZoom;	// 是否启用缩放功能


private:
	GGGameSetting();
	GGGameSetting(const GGGameSetting& other)=delete;
	void operator=(const GGGameSetting& other)=delete;
	GGGameSetting(GGGameSetting&& other)=delete;
};


#endif // __GG_GAME_SETTING_H__

