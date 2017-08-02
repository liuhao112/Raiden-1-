#include "Enemy.h"
#include "Controller.h"
#include "Bullet.h"

Enemy::Enemy(HBITMAP hbmp, Controller *pController,int health,int type) :GameObject(hbmp)
{
	this->SetX((float)(rand() % 600 + 100));
	this->SetY(1);
	this->SetDead(false);
	this->speed_x = (rand() % 5 - 2);		
	this->speed_y = rand() % 2 + 1;
	this->health = health;
	if (this->speed_x == 0 && this->speed_y == 1)
		this->speed_x = 1;
	m_pController = pController;
	this->enemyType = type;
	if (enemyType == 0)
	{
		SetFireMode(m_pController->GetImages()->hImgEnemyBullet, rand() % 5+3, rand() % 7);
	}
	else
	{
		SetFireMode(m_pController->GetImages()->hImgEnemyBullet, 2, rand() % 7);
	}
	this->score = 50;
}


Enemy::~Enemy()
{
	
}

void Enemy::Fire()
{
	if (enemyType == 0)
	{
		m_pController->m_pEnemyBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY() + this->GetHeight(), this->hbmpOfFire, this->demage, (BulletDirection)(bulletType + 7)));
	}
	else
	{
		m_pController->m_pEnemyBulletList->push_back(Bullet(this->GetX() + this->GetWidth() / 2, this->GetY() + this->GetHeight(), this->hbmpOfFire, this->demage, (BulletDirection)(rand() % 7 + 7)));
	}
}
void Enemy::DrawMe(HDC hdc)		//虚函数，渲染物体
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());

		TransparentBlt(hdc, (int)GetX(), (int)GetY(), (int)GetWidth(), (int)GetHeight(), hdcsrc, 0, 0, (int)GetWidth(), (int)GetHeight(), RGB(0, 0, 255));
		DeleteDC(hdcsrc);
	}
}
void Enemy::SetDead(bool isDead)
{
	this->isDead = isDead;
}
bool Enemy::IsDead()
{
	return this->isDead;
}
void Enemy::AddHealth(int health)
{
	this->health += health;
	if (this->health <= 0)
	{
		this->isDead = true;
		if (this->enemyType == 1)
		{
			if (rand() % 100 > 49)
				m_pController->AddGoods(1);
		}
		else if (this->enemyType == 2)
		{
			if (rand() % 100>49)
				m_pController->AddGoods(2);
		}
		else if (this->enemyType == 3)
		{
			if (rand() % 100>49)
				m_pController->AddGoods(3);
		}
		else if (this->enemyType == 4)
		{
			if (rand() % 100>49)
				m_pController->AddGoods(4);
		}
		m_pController->m_pExplodeList->push_back(Explode(m_pController->GetImages()->hImgExplode, this->GetX(), this->GetY()));
	}
}
void Enemy::SetFireMode(HBITMAP hbmpOfFire, int demage,  int type)
{
	this->hbmpOfFire = hbmpOfFire;
	this->demage = demage;
	this->bulletType = type;
}

void Enemy::EnemyRun()
{
	if (enemyType == 0)
	{
		if (rand() % 100 == 1)
			this->SetX(this->GetX() + speed_x);
		else
			this->SetX(this->GetX() - speed_x);
		this->SetY(this->GetY() + speed_y);//运动
		if (this->IsOutWindow())
		{
			this->score = 0;//分值设为0
			this->SetDead(true);
		}
		if (rand() % 100 > 98)//开火
			Fire();
	}
	else
	{
		if (rand() % 100 == 1)
			speed_x = -speed_x;
		this->SetX(this->GetX() + speed_x);
		this->SetY(this->GetY() + speed_y);//运动
		if (this->GetX() < 0)
			this->SetX(1);
		if (this->GetX() > 800 - this->GetWidth())
			this->SetX(800 - this->GetWidth());
		if (this->GetY() > 50)
			this->SetY(50);
		if (rand() % 100 > 96)//开火
			Fire();
	}	
}

void Enemy::BeHit(Hero *hero)					//判断是否被击中
{
	for (auto & i : *(hero->m_pHeroBulletList))
	{
		if (i.IsCollision(this))
		{
			this->AddHealth(-i.GetDamage());
			i.SetDead(true);
		}
	}
}

int Enemy::GetScore()
{
	return this->score;
}