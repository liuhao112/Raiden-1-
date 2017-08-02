#pragma once
#include "GameObject.h"
class BuffGoods :
	public GameObject
{
public:
	BuffGoods(HBITMAP hbmp,int type);
	~BuffGoods();

	virtual void DrawMe(HDC hdc) override;		//Ðéº¯Êý£¬äÖÈ¾ÎïÌå
	void SetDead(bool isDead);
	bool IsDead();
	void BuffRun();
	int GetType();
private:
	bool isDead;
	int type;
	float speed_x;
	float speed_y;
};

