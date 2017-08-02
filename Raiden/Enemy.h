#ifndef _Enemy_H__
#define _Enemy_H__

#include "inc.h"
#include "GameObject.h"
#include "Hero.h"

class Controller;
class Enemy :
	public GameObject
{
public:
	Enemy(HBITMAP hbmp, Controller *pController,int health,int type = 0);
	virtual ~Enemy();
	virtual void Fire();
	virtual void DrawMe(HDC hdc) override;		//虚函数，渲染物体
	void SetDead(bool isDead);
	bool IsDead();
	void AddHealth(int health);
	void SetFireMode(HBITMAP hbmpOfFire, int demage, int bulletType);
	void EnemyRun();
	void BeHit(Hero *hero);						//判断是否被击中
	int GetScore();							//获取得分
private:
	int health;
	int demage;
	int bulletType;
	bool isDead;
	HBITMAP hbmpOfFire;
	Controller * m_pController;
	int speed_x;
	int speed_y;
	int score;
	int enemyType;			//1:boss1  2:boss2 3:boss3 4:boss4 0:小怪
};

#endif
