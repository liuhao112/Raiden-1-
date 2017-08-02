#ifndef _Explode_H__
#define _Explode_H__

#include "GameObject.h"
class Explode :
	public GameObject
{
public:
	Explode(HBITMAP *hbmp,float x,float y,int num = 21);
	~Explode();
	virtual void DrawMe(HDC hdc) override;		//Ðéº¯Êý£¬äÖÈ¾ÎïÌå
	HBITMAP GetExplodeHBitMap();
	bool IsDead();
private:
	HBITMAP explode[21];
	int state;
	bool isDead;
};

#endif
