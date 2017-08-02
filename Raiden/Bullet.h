#ifndef _Bullet_H__
#define _Bullet_H__

#include "GameObject.h"

class Bullet :
	public GameObject
{
public:
	Bullet(float x, float y, HBITMAP hbmp, int damage, enum BulletDirection dir,int speed = 3);
	virtual ~Bullet();
	int GetDamage();
	void SetDead(bool isDead);
	bool IsDead();
	void BulletRun();
	virtual void DrawMe(HDC hdc) override;			//Ðéº¯Êý£¬äÖÈ¾ÎïÌå
private:
	int damage;
	int speed;
	bool isDead;
	enum BulletDirection bulletDir;
};

#endif

