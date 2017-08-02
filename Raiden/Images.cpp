#include "inc.h"
#include "Images.h"

Images::Images(HINSTANCE hInst)
{
	hImgAddHealth = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ADDHEALTH));
	hImgBoss = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BOSS1));
	hImgBullet = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BULLET));
	hImgChangeFire[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CHANGEFIRE1));
	hImgChangeFire[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CHANGEFIRE2));
	hImgChangeFire[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CHANGEFIRE3));
	hImgChangeFire[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CHANGEFIRE4));
	hImgChangeFire[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CHANGEFIRE5));
	hImgContinue = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CONTINUE));
	hImgEnemyBullet = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMYBULLET));
	hImgEnter = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENTER));
	hImgExplode[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE1));
	hImgExplode[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE2));
	hImgExplode[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE3));
	hImgExplode[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE4));
	hImgExplode[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE5));
	hImgExplode[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE6));
	hImgExplode[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE7));
	hImgExplode[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE8));
	hImgExplode[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE9));
	hImgExplode[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE10));
	hImgExplode[10] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE11));
	hImgExplode[11] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE12));
	hImgExplode[12] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE13));
	hImgExplode[13] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE14));
	hImgExplode[14] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE15));
	hImgExplode[15] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE16));
	hImgExplode[16] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE17));
	hImgExplode[17] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE18));
	hImgExplode[18] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE19));
	hImgExplode[19] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE20));
	hImgExplode[20] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EXPLODE21));
	hImgGameOver = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_GAMEOVER));
	hImgHealth = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_HEALTH));
	hImgLaser = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_LASER));
	hImgLife = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_LIFE));
	hImgNum[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM0));
	hImgNum[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM1));
	hImgNum[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM2));
	hImgNum[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM3));
	hImgNum[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM4));
	hImgNum[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM5));
	hImgNum[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM6));
	hImgNum[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM7));
	hImgNum[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM8));
	hImgNum[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_NUM9));
	hImgPanel = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PANEL));
	hImgPass = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PASS));
	hImgHero = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_HERO));
	hImgEnemy[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY1));
	hImgEnemy[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY2));
	hImgEnemy[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY3));
	hImgEnemy[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY4));
	hImgEnemy[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY5));
	hImgEnemy[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY6));
	hImgEnemy[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY7));
	hImgEnemy[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY8));
	hImgEnemy[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY9));
	hImgEnemy[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY10));
	hImgEnemy[10] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY11));
	hImgEnemy[11] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY12));
	hImgEnemy[12] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY13));
	hImgEnemy[13] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY14));
	hImgEnemy[14] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ENEMY15));
	hImgSky = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_SKY));
	hImgStartBg = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_STARTBG));
	hImgStore = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_STORE));
	hImgGoods[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_GOODS1));
	hImgGoods[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_GOODS2));
	hImgGoods[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_GOODS3));
	hImgGoods[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_GOODS4));
	hImgSuperBullet = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_SUPERBULLET));
}


Images::~Images()
{
}
