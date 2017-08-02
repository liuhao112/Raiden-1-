#include "BuffGoods.h"


BuffGoods::BuffGoods(HBITMAP hbmp,int type) :GameObject(hbmp)
{
	this->SetX(rand() % 600 + 100);
	this->SetY(0);
	this->SetDead(false);
	this->speed_x = (rand() % 5 - 2);
	this->speed_y = rand() % 2 + 1;
	this->type = type;
	if (this->speed_x == 0 && this->speed_y == 1)
		this->speed_x = 1;
}


BuffGoods::~BuffGoods()
{
}

void BuffGoods::DrawMe(HDC hdc)//虚函数，渲染物体
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());

		TransparentBlt(hdc, GetX(), GetY(), GetWidth(), GetHeight(), hdcsrc, 0, 0, GetWidth(), GetHeight(), RGB(255, 255, 255));
		DeleteDC(hdcsrc);
	}
}
void BuffGoods::SetDead(bool isDead)
{
	this->isDead = isDead;
}
bool BuffGoods::IsDead()
{
	return this->isDead;
}
void BuffGoods::BuffRun()
{
	if (rand() % 100 == 1)
		this->SetX(this->GetX() + speed_x);
	else
		this->SetX(this->GetX() - speed_x);
	this->SetY(this->GetY() + speed_y);//运动
	if (this->IsOutWindow())
	{
		this->SetDead(true);
	}
}

int BuffGoods::GetType()
{
	return this->type;
}