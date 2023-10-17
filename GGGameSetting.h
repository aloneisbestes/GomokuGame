#ifndef __GG_GAME_SETTING_H__
#define __GG_GAME_SETTING_H__

/**
 * ����
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
	bool m_isZoom;	// �Ƿ��������Ź���


private:
	GGGameSetting();
	GGGameSetting(const GGGameSetting& other)=delete;
	void operator=(const GGGameSetting& other)=delete;
	GGGameSetting(GGGameSetting&& other)=delete;
};


#endif // __GG_GAME_SETTING_H__

