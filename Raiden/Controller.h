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
	Controller(HWND hwnd);	//���캯������Ҫ������һ��HWND
	~Controller();
	void GameStart();		//��Ϸ��ʼ
	void GamePause();		//��Ϸ��ͣ
	void GameEnd();			//��Ϸ����
	void OpenStore();		//���̵�
	void CloseStore();		//�ر��̵�
	void GameWaitReset();	//��Ϸ�ȴ�����Hero
	void ResetHero();		//����Hero
	void RenderScene();		//��Ⱦ����
	void SetGoingUp(bool up);			//����Hero�˶���������
	void SetGoingDown(bool down);		//����Hero�˶���������
	void SetGoingLeft(bool left);		//����Hero�˶���������
	void SetGoingRight(bool right);		//����Hero�˶���������
	void SetHeroFire(bool fire);		//����Hero����
	void SetHeroFireMode(int type,int demage);	//����Hero����ģʽ
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
	void AllRun();						//�������������˶�
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
	void HeroRun();			//����Hero�˶�

private:
	HWND m_hWnd;				//���洰�ھ��
	HINSTANCE m_hInst;			//�������ʵ��
	Images *m_pImages;			//������ԴͼƬ���
	BackGround *m_pBackGround;	//��Ϸ����-����
	Hero *m_pHero;				//��Ϸ����-Hero
	HeroHealth *m_pHeroHealth;	//��Ϸ����-Hero ����ֵ��
	HeroLife *m_pHeroLife;		//��Ϸ����-Hero ������

	bool isGoingUp;
	bool isGoingDown;
	bool isGoingLeft;
	bool isGoingRight;
	bool isFire;
	int  allScore;
	int heroCurentDemage;
	int  state;					//��Ϸ״̬ -1:��Ϸδ��ʼ 0:��ͣ 1:���� 2:���� 3:Hero����
	bool isStoreOpen;				//�̵��Ƿ��

	bool isGotGoods1;			//�õ���Ʒ1
	bool isGotGoods2;			//�õ���Ʒ2
	bool isGotGoods3;			//�õ���Ʒ3
	bool isGotGoods4;			//�õ���Ʒ4
};

#endif
