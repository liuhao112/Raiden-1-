#ifndef _BACKGROUND_H__
#define _BACKGROUND_H__

#include "GameObject.h"
class BackGround :
	public GameObject
{
public:
	BackGround(HBITMAP hbmp);
	virtual ~BackGround();
	void DrawMe( HDC hdc) override;
	void BackGroundRun();
private:

};

#endif

