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
	virtual void DrawMe(HDC hdc) override;		//�麯������Ⱦ����
	void SetDead(bool isDead);
	bool IsDead();
	void AddHealth(int health);
	void SetFireMode(HBITMAP hbmpOfFire, int demage, int bulletType);
	void EnemyRun();
	void BeHit(Hero *hero);						//�ж��Ƿ񱻻���
	int GetScore();							//��ȡ�÷�
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
	int enemyType;			//1:boss1  2:boss2 3:boss3 4:boss4 0:С��
};

#endif
