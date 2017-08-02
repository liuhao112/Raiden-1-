#pragma once
#include "GameObject.h"
class HeroLife :
	public GameObject
{
public:
	HeroLife(HBITMAP hbmp);
	~HeroLife();
	void SetLifeNum(int numOfLife);
	int GetLifeNum();
	void DrawMe(HDC hdc) override;
private:
	int numOfLife;
};

