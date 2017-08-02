#ifndef _CONTROLLER_H__
#define _CONTROLLER_H__

#include "Images.h"
#include "Enemy.h"
#include <list>
#include <Windows.h>
#include "HeroHealth.h"
#include "HeroLife.h"
#include "BuffGoods.h"
#include "Explode.h"
#include "BackGround.h"

using namespace std;

class Enemy;
class Controller
{
public:
	Controller(HWND hwnd);	//构造函数，需要传进来一个HWND
	~Controller();
	void GameStart();		//游戏开始
	void GamePause();		//游戏暂停
	void GameEnd();			//游戏结束
	void OpenStore();		//打开商店
	void CloseStore();		//关闭商店
	void GameWaitReset();	//游戏等待重置Hero
	void ResetHero();		//重置Hero
	void RenderScene();		//渲染场景
	void SetGoingUp(bool up);			//设置Hero运动方向向上
	void SetGoingDown(bool down);		//设置Hero运动方向向下
	void SetGoingLeft(bool left);		//设置Hero运动方向向左
	void SetGoingRight(bool right);		//设置Hero运动方向向右
	void SetHeroFire(bool fire);		//设置Hero开火
	void SetHeroFireMode(int type,int demage);	//设置Hero开火模式
	void AddEnemy();
	void AddBuffGoods();
	void DrawAllEnemy(HDC hdc);
	void DrawAllEnemyBullet(HDC hdc);
	void DrawAllExplode(HDC hdc);
	void DrawAllBuffGoods(HDC hdc);
	void DrawStartBackGround(HDC hdc);
	void DrawGameOver(HDC hdc);
	void DrawGameContinue(HDC hdc);
	void DrawScore(HDC hdc);
	void DrawStore(HDC hdc);
	void DrawAttribute(HDC hdc);
	void AllRun();						//控制所有物体运动
	void AllBulletRun();
	void AllEnemyRun();
	void AllBuffGoodsRun();
	bool Buy(int goodType);
	void SetGotGoods(int g1, int g2, int g3, int g4);
	void AddGoods(int goodsType);	
	Images* GetImages();

public:
	list<Enemy> * m_pEnemyList;
	list<Bullet> * m_pEnemyBulletList;
	list<Explode> * m_pExplodeList;
	list<BuffGoods> *m_pBuffGoodsList;
private:
	void HeroRun();			//控制Hero运动

private:
	HWND m_hWnd;				//保存窗口句柄
	HINSTANCE m_hInst;			//保存程序实例
	Images *m_pImages;			//所有资源图片句柄
	BackGround *m_pBackGround;	//游戏物体-背景
	Hero *m_pHero;				//游戏物体-Hero
	HeroHealth *m_pHeroHealth;	//游戏物体-Hero 生命值条
	HeroLife *m_pHeroLife;		//游戏物体-Hero 生命数

	bool isGoingUp;
	bool isGoingDown;
	bool isGoingLeft;
	bool isGoingRight;
	bool isFire;
	int  allScore;
	int heroCurentDemage;
	int  state;					//游戏状态 -1:游戏未开始 0:暂停 1:运行 2:结束 3:Hero死亡
	bool isStoreOpen;				//商店是否打开

	bool isGotGoods1;			//得到物品1
	bool isGotGoods2;			//得到物品2
	bool isGotGoods3;			//得到物品3
	bool isGotGoods4;			//得到物品4
};

#endif
