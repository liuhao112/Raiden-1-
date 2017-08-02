#include "Bullet.h"
#include "inc.h"

Bullet::Bullet(float x, float y, HBITMAP hbmp, int damage, enum BulletDirection dir,int speed) :GameObject(hbmp)
{
	this->SetX(x-this->GetWidth()/2);
	this->SetY(y-this->GetHeight()/2);
	this->damage = damage;
	this->isDead = false;
	this->speed = speed;
	this->bulletDir = dir;
}


Bullet::~Bullet()
{
}

int Bullet::GetDamage()
{
	return this->damage;
}
void Bullet::SetDead(bool isDead)
{
	this->isDead = isDead;
}
bool Bullet::IsDead()
{
	return this->isDead;
}

void Bullet::BulletRun()
{
	if (this->bulletDir == BulletDirection::D)
	{
		this->SetY(this->GetY() + speed);
	}
	else if (this->bulletDir == BulletDirection::L)
	{
		this->SetX(this->GetX() - speed);
	}
	else if (this->bulletDir == BulletDirection::LD)
	{
		this->SetY(this->GetY() + speed);
		this->SetX(this->GetX() - speed);
	}
	else if (this->bulletDir == BulletDirection::LDD)
	{
		this->SetY(this->GetY() + 2*speed);
		this->SetX(this->GetX() - speed);
	}
	else if (this->bulletDir == BulletDirection::LLD)
	{
		this->SetY(this->GetY() + speed);
		this->SetX(this->GetX() - 2 * speed);
	}
	else if (this->bulletDir == BulletDirection::LLU)
	{
		this->SetY(this->GetY() - speed);
		this->SetX(this->GetX() - 2 * speed);
	}
	else if (this->bulletDir == BulletDirection::LU)
	{
		this->SetY(this->GetY() - speed);
		this->SetX(this->GetX() - speed);
	}
	else if (this->bulletDir == BulletDirection::LUU)
	{
		this->SetY(this->GetY() - 2*speed);
		this->SetX(this->GetX() - speed);
	}
	else if (this->bulletDir == BulletDirection::R)
	{
		this->SetX(this->GetX() + speed);
	}
	else if (this->bulletDir == BulletDirection::RD)
	{
		this->SetY(this->GetY() + speed);
		this->SetX(this->GetX() + speed);
	}
	else if (this->bulletDir == BulletDirection::RDD)
	{
		this->SetY(this->GetY() + 2*speed);
		this->SetX(this->GetX() + speed);
	}
	else if (this->bulletDir == BulletDirection::RRD)
	{
		this->SetY(this->GetY() + speed);
		this->SetX(this->GetX() + 2 * speed);
	}
	else if (this->bulletDir == BulletDirection::RRU)
	{
		this->SetY(this->GetY() - speed);
		this->SetX(this->GetX() + 2 * speed);
	}
	else if (this->bulletDir == BulletDirection::RU)
	{
		this->SetY(this->GetY() - speed);
		this->SetX(this->GetX() + speed);
	}
	else if (this->bulletDir == BulletDirection::RUU)
	{
		this->SetY(this->GetY() - 2 * speed);
		this->SetX(this->GetX() + speed);
	}
	else if (this->bulletDir == BulletDirection::U)
	{
		this->SetY(this->GetY() - speed);
	}
	
	if (IsOutWindow())
		SetDead(true);
}
void Bullet::DrawMe(HDC hdc)			//Ðéº¯Êý£¬äÖÈ¾ÎïÌå
{	
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());

		TransparentBlt(hdc, (int)GetX(), (int)GetY(), (int)GetWidth(), (int)GetHeight(), hdcsrc, 0, 0, (int)GetWidth(), (int)GetHeight(), RGB(255, 255, 255));
		DeleteDC(hdcsrc);
	}
}