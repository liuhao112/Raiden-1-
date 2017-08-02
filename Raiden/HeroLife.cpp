#include "HeroLife.h"


HeroLife::HeroLife(HBITMAP hbmp) :GameObject(hbmp)
{
	this->SetX(600);
	this->SetY(550);
	this->numOfLife = 4;
}


HeroLife::~HeroLife()
{
}

void HeroLife::SetLifeNum(int numOfLife)
{
	this->numOfLife = numOfLife;
}

int HeroLife::GetLifeNum()
{
	return this->numOfLife;
}
void HeroLife::DrawMe(HDC hdc)
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());
		for (int i = 0; i < numOfLife; i++)
			TransparentBlt(hdc, GetX() + i * 50, GetY(), GetWidth(), GetHeight(), hdcsrc, 0, 0, GetWidth(),GetHeight(),RGB(255,255,255));
		DeleteDC(hdcsrc);
	}
}

