#ifndef _IMAGES_H__
#define _IMAGES_H__

#include <Windows.h>

class Images
{
public:
	Images(HINSTANCE hInst);
	~Images();
public:
	HBITMAP hImgAddHealth;
	HBITMAP hImgBoss;
	HBITMAP hImgBullet;
	HBITMAP hImgChangeFire[5];
	HBITMAP hImgContinue;
	HBITMAP hImgEnemyBullet;
	HBITMAP hImgEnter;
	HBITMAP hImgExplode[21];
	HBITMAP hImgGameOver;
	HBITMAP hImgHealth;
	HBITMAP hImgLaser;
	HBITMAP hImgLife;
	HBITMAP hImgNum[10];
	HBITMAP hImgPanel;
	HBITMAP hImgPass;
	HBITMAP hImgHero;
	HBITMAP hImgEnemy[15];
	HBITMAP hImgSky;
	HBITMAP hImgStartBg;
	HBITMAP hImgStore;
	HBITMAP hImgGoods[4];
	HBITMAP hImgSuperBullet;
};

#endif