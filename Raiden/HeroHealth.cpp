#include "HeroHealth.h"


HeroHealth::HeroHealth(HBITMAP hbmp) :GameObject(hbmp)
{
	this->SetX(20);
	this->SetY(560);
	this->hp = 0;
}


HeroHealth::~HeroHealth()
{
}

void HeroHealth::SetHp(int hp)
{
	this->hp = hp;
}
void HeroHealth::DrawMe(HDC hdc)		//Ðéº¯Êý£¬äÖÈ¾ÎïÌå
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());
		for (int i = 0; i < hp;i++)
			BitBlt(hdc, GetX()+i*3, GetY(), GetWidth(), GetHeight(), hdcsrc, 0, 0,SRCCOPY);
		DeleteDC(hdcsrc);
	}
}