#pragma once
#include "GameObject.h"
class HeroHealth :
	public GameObject
{
public:
	HeroHealth(HBITMAP hbmp);
	~HeroHealth();
	void SetHp(int hp);
	void DrawMe(HDC hdc)override;		//Ğéº¯Êı£¬äÖÈ¾ÎïÌå
private:
	int hp;
};

