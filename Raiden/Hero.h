#ifndef _HERO_H__
#define _HERO_H__

#include "GameObject.h"
#include "inc.h"
class Bullet;
class Hero :
	public GameObject
{
public:
	Hero(HBITMAP hbmp);
	~Hero();
	void Left();
	void Right();
	void Down();
	void Up();
	void DrawMe(HDC hdc) override;	
	bool IsDead();
	void AddHealth(int health);
	int  GetHealth();
	void SetHealth(int health);
	void Reset();
	void Fire();
	void SetFireMode(HBITMAP hbmpOfFire, int demage, int type);
	void Hero::DrawAllHeroBullet(HDC hdc);			//渲染所有HeroBullet
	void AllHeroBulletRun();
	
	std::list<Bullet>* m_pHeroBulletList;	//Hero子弹链表
private:

	bool isDead;
	int health;
	HBITMAP hbmpOfFire;
	int demage;
	int type;
	
};

#endif

