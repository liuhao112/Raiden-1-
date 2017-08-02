#include "inc.h"
#include "Hero.h"
#include "Bullet.h"
Hero::Hero(HBITMAP hbmp):GameObject(hbmp)
{
	this->health = 100;
	this->isDead = false;
	this->SetX((800 - this->GetWidth()) / 2);
	this->SetY(500);
	m_pHeroBulletList = new list<Bullet>();
}


Hero::~Hero()
{
	if (m_pHeroBulletList != nullptr)
		delete m_pHeroBulletList;
}

void Hero::Left()
{
	float x = this->GetX()-5;
	if (x <= 0)
		this->SetX(0);
	else
		this->SetX(x);
}
void Hero::Right()
{
	float x = this->GetX() + 5;
	if (x >= (800-this->GetWidth()))
		this->SetX(800 - this->GetWidth());
	else
		this->SetX(x);
}
void Hero::Down()
{
	float y = this->GetY() + 5;
	if (y >= (600-this->GetHeight()))
		this->SetY(600 - this->GetHeight());
	else
		this->SetY(y);

}
void Hero::Up()
{
	float y = this->GetY() - 5;
	if (y <= 0)
		this->SetY(0);
	else
		this->SetY(y);
}
void Hero::DrawMe(HDC hdc)
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());

		TransparentBlt(hdc, (int)GetX(), (int)GetY(), (int)GetWidth(), (int)GetHeight(), hdcsrc, 0, 0, (int)GetWidth(), (int)GetHeight(), RGB(255, 255, 255));
		DeleteDC(hdcsrc);		
	}
	DrawAllHeroBullet(hdc);//渲染所有HeroBullet
}

bool Hero::IsDead()
{
	return this->isDead;
}
void Hero::AddHealth(int health)
{
	this->health += health;
	if (this->health <= 0)
	{
		this->isDead = true;
	}
}

void Hero::SetHealth(int health)
{
	if (health >= 100)
		this->health = 100;
	else
		this->health = health;
}
void Hero::Reset()
{
	this->health = 100;
	this->isDead = false;
	this->SetX((800 - this->GetWidth()) / 2);
	this->SetY(500);
	this->SetVisible(true);
}
void Hero::Fire()
{
	static int i = 0;
	++i;
	if (i % 5 == 0)
	{
		if (i % 2 == 0)
		{
			if (type == 0)
			{
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::U, 20));
			}
			else if (type == 1)
			{
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2 - 10, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::U, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2 + 10, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::U, 20));
			}
			else if (type == 2)
			{
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::U, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::LU, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::RU, 20));
			}
			else if (type == 3)
			{
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::U, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::LLU, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::LU, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::RRU, 20));
				m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage, BulletDirection::RU, 20));
			}
		}		
		if (type == 4)
		{
			m_pHeroBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY(), this->hbmpOfFire, this->demage*6, BulletDirection::U, 20));
		}
	}
}

void Hero::SetFireMode(HBITMAP hbmpOfFire, int demage, int type)
{
	this->hbmpOfFire = hbmpOfFire;
	this->demage = demage;
	this->type = type;
}

void Hero::DrawAllHeroBullet(HDC hdc)			//渲染所有HeroBullet
{
	for (auto&i : *m_pHeroBulletList)
	{
		i.DrawMe(hdc);
	}
	for (std::list<Bullet>::iterator i = m_pHeroBulletList->begin(); i != m_pHeroBulletList->end();)
	{
		if (i->IsDead())
		{
			i = m_pHeroBulletList->erase(i);
		}
		else
		{
			++i;
		}
	}
}

void Hero::AllHeroBulletRun()
{
	for (auto&i : *m_pHeroBulletList)
	{
		i.BulletRun();
	}
}

int Hero::GetHealth()
{
	return this->health;
}