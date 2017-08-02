#include "Controller.h"                                               //本模块负责游戏的整体控制，从游戏的运行以及其中各种操作的处理，此模块为
#include "inc.h"                                                      //该项目的核心模块，也是在学习中重点了解的模块
#include "Bullet.h"

Controller::Controller(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
	m_pImages = new Images(m_hInst);
	m_pBackGround = new BackGround(m_pImages->hImgSky);

	this->heroCurentDemage = 2;//初始伤害为2

	m_pHero = new Hero(m_pImages->hImgHero);	
	m_pHeroHealth = new HeroHealth(m_pImages->hImgHealth);	
	m_pHeroLife = new HeroLife(m_pImages->hImgLife);
	ResetHero();//重置Hero对象
	m_pEnemyBulletList = new list<Bullet>();
	m_pEnemyList = new list<Enemy>();
	m_pExplodeList = new list<Explode>();
	m_pBuffGoodsList = new list<BuffGoods>();
	this->allScore = 0;
	this->state = -1;
	
}


Controller::~Controller()
{
}

void Controller::GameStart()
{
	if (this->state == -1)
		this->state = 1;
	if (this->state == 3)
		this->ResetHero();
}
void Controller::GamePause()
{
	if (this->state == 1)
	{
		this->state = 0;
	}
	else if (this->state == 0)
	{
		this->state = 1;
	}
	
}
void Controller::GameEnd()
{
	this->state = 2;
}
void Controller::OpenStore()
{
	if (!isStoreOpen)//商店未打开
	{
		//打开商店
		if (this->state == 1 || this->state == 0)
		{
			this->state = 0;
			this->isStoreOpen = true;
		}
	}
	else//商店已经打开
	{
		CloseStore();//关闭商店
	}
		
}
void Controller::CloseStore()
{
	if (this->isStoreOpen)
	{
		this->isStoreOpen = false;
		this->state = 1;
	}
}
void Controller::GameWaitReset()	//游戏等待重置Hero
{
	this->state = 3;
}
void Controller::RenderScene()                                       //用双缓冲技术来完成画面的显示
{
	HDC hdc = GetDC(m_hWnd);
	HDC hdcBuffer = CreateCompatibleDC(hdc);
	HBITMAP hBitmapBuf = CreateCompatibleBitmap(hdc, 800, 600);
	SelectObject(hdcBuffer, hBitmapBuf);

	if (state != -1)
	{
		if (state != 0)
			AllRun();
		m_pBackGround->DrawMe(hdcBuffer);
		m_pHeroHealth->DrawMe(hdcBuffer);
		m_pHeroLife->DrawMe(hdcBuffer);
		m_pHero->DrawMe(hdcBuffer);

		this->DrawAttribute(hdcBuffer);
		this->DrawScore(hdcBuffer);
		this->DrawAllEnemy(hdcBuffer);
		this->DrawAllEnemyBullet(hdcBuffer);
		this->DrawAllExplode(hdcBuffer);
		this->DrawAllBuffGoods(hdcBuffer);
		
		if (this->isStoreOpen)
			this->DrawStore(hdcBuffer);

		if (state == 2)
		{
			this->DrawGameOver(hdcBuffer);//游戏结束
		}	
		if (state == 3)
		{
			this->DrawGameContinue(hdcBuffer);//继续游戏
		}
	}
	else
	{
		this->DrawStartBackGround(hdcBuffer);//入口场景
	}
	
	BitBlt(hdc, 0, 0, 800, 600, hdcBuffer, 0, 0, SRCCOPY);

	DeleteObject(hBitmapBuf);
	DeleteDC(hdcBuffer);
	ReleaseDC(m_hWnd, hdc);
}	

void Controller::SetGoingUp(bool up)			//设置Hero运动方向向上
{
	this->isGoingUp = up;
}
void Controller::SetGoingDown(bool down)		//设置Hero运动方向向下
{
	this->isGoingDown = down;
}
void Controller::SetGoingLeft(bool left)		//设置Hero运动方向向左
{
	this->isGoingLeft = left;
}
void Controller::SetGoingRight(bool right)		//设置Hero运动方向向右
{
	this->isGoingRight = right;
}

void Controller::SetHeroFire(bool fire)		//设置Hero开火
{
	this->isFire = fire;
}

void Controller::SetHeroFireMode(int type,int demage)	//设置Hero开火模式
{
	if (m_pHero != nullptr)
	{
		m_pHero->SetFireMode(m_pImages->hImgBullet, demage, type);
	}
}

void Controller::HeroRun()			//控制Hero运动
{
	if (m_pHero == nullptr)
		return;
	if (this->isGoingUp)
		m_pHero->Up();
	if (this->isGoingDown)
		m_pHero->Down();
	if (this->isGoingLeft)
		m_pHero->Left();
	if (this->isGoingRight)
		m_pHero->Right();
	if (this->isFire)
		m_pHero->Fire();
}

Images* Controller::GetImages()
{
	return m_pImages;
}

void Controller::AddEnemy()
{
	static int i = 0;
	static int count = 1;
	++i;
	if (i == 6000)
	{
		count++;
		i = 0;
	}
	if (m_pEnemyList->size() < 10&&rand()%100>95)
		m_pEnemyList->push_back(Enemy(m_pImages->hImgEnemy[rand() % 15], this,count*20));
}
void Controller::AddBuffGoods()
{
	if (m_pBuffGoodsList->size() < 3 && rand() % 1000 > 990)
	{
		int type = rand() % 5;
		m_pBuffGoodsList->push_back(BuffGoods(m_pImages->hImgChangeFire[type], type));
	}
}

void Controller::DrawAllEnemy(HDC hdc)
{
	for (auto&i : *m_pEnemyList)
	{
		i.DrawMe(hdc);
	}
}
void Controller::DrawAllEnemyBullet(HDC hdc)
{
	for (auto&i : *m_pEnemyBulletList)
	{
		i.DrawMe(hdc);
	}
}
void Controller::DrawAllExplode(HDC hdc)
{
	for (auto&i : *m_pExplodeList)
	{
		i.DrawMe(hdc);
	}
	for (std::list<Explode>::iterator i = m_pExplodeList->begin(); i != m_pExplodeList->end();)
	{
		if (i->IsDead())
		{
			i = m_pExplodeList->erase(i);
		}
		else
		{
			++i;
		}
	}
}

void Controller::DrawAllBuffGoods(HDC hdc)
{
	for (auto&i : *m_pBuffGoodsList)
	{
		i.DrawMe(hdc);
	}
	for (std::list<BuffGoods>::iterator i = m_pBuffGoodsList->begin(); i != m_pBuffGoodsList->end();)
	{
		if (i->IsDead())
		{
			i = m_pBuffGoodsList->erase(i);
		}
		else
		{
			++i;
		}
	}
}
void Controller::AllRun()						//控制所有物体运动
{
	if (!m_pHero->IsDead())
	{
		HeroRun();//Hero运动
	}	
	m_pBackGround->BackGroundRun();//背景移动
	m_pHero->AllHeroBulletRun();//所有Hero bullet运动
	AllEnemyRun();
	AllBulletRun();
	AllBuffGoodsRun();
	
}
void Controller::AllBulletRun()
{
	for (auto&i : *m_pEnemyBulletList)
	{
		i.BulletRun();
		if (!m_pHero->IsDead()&&i.IsCollision(this->m_pHero))
		{
			this->m_pHero->AddHealth(-i.GetDamage());
			if (m_pHero->IsDead())//Hero Die
			{
				this->m_pExplodeList->push_back(Explode(this->GetImages()->hImgExplode, m_pHero->GetX(), m_pHero->GetY()));
				m_pHero->SetVisible(false);
				if (m_pHeroLife->GetLifeNum() > 0)
					GameWaitReset();//等待Hero重置
				else
					GameEnd();//游戏结束
			}
			this->m_pHeroHealth->SetHp(m_pHero->GetHealth());
			i.SetDead(true);
		}
	}
	for (std::list<Bullet>::iterator i = m_pEnemyBulletList->begin(); i != m_pEnemyBulletList->end();)
	{
		if (i->IsDead())
		{
			i = m_pEnemyBulletList->erase(i);
		}
		else
		{
			++i;
		}
	}
}
void Controller::AllEnemyRun()
{
	AddEnemy();//添加敌人

	for (auto&i : *m_pEnemyList)
	{
		i.EnemyRun();
		i.BeHit(m_pHero);
		if (!this->m_pHero->IsDead()&&i.IsCollision(this->m_pHero))
		{
			this->m_pHero->AddHealth(-5);//撞飞机减5血
			if (m_pHero->IsDead())//Hero Die
			{
				this->m_pExplodeList->push_back(Explode(GetImages()->hImgExplode, m_pHero->GetX(), m_pHero->GetY()));
				m_pHero->SetVisible(false);
				if (m_pHeroLife->GetLifeNum() > 0)
					GameWaitReset();//等待Hero重置
				else
					GameEnd();//游戏结束
			}
			this->m_pHeroHealth->SetHp(m_pHero->GetHealth());
			i.AddHealth(-100);//敌机减血100
		}
	}
	for (std::list<Enemy>::iterator i = m_pEnemyList->begin(); i != m_pEnemyList->end();)
	{
		if (i->IsDead())
		{
			this->allScore += i->GetScore();//计分
			i = m_pEnemyList->erase(i);//消除该敌人对象
		}
		else
		{
			++i;
		}
	}
}

void Controller::AllBuffGoodsRun()
{
	AddBuffGoods();//添加增益物品

	for (auto&i : *m_pBuffGoodsList)
	{
		i.BuffRun();
		if (!this->m_pHero->IsDead() && i.IsCollision(this->m_pHero))
		{
			//Buff效果
			if (i.GetType() < 4)
			{
				m_pHero->SetFireMode(m_pImages->hImgBullet, heroCurentDemage, i.GetType());
			}
			else if (i.GetType() == 4)
			{
				m_pHero->SetFireMode(m_pImages->hImgLaser, heroCurentDemage, i.GetType());
			}
			else if (i.GetType() == 6)
			{
				this->isGotGoods1 = true;
			}
			else if (i.GetType() == 7)
			{
				this->isGotGoods2 = true;
			}
			else if (i.GetType() == 8)
			{
				this->isGotGoods3 = true;
			}
			else if (i.GetType() == 9)
			{
				this->isGotGoods4 = true;
			}
			i.SetDead(true);
		}
	}
	for (std::list<BuffGoods>::iterator i = m_pBuffGoodsList->begin(); i != m_pBuffGoodsList->end();)
	{
		if (i->IsDead())
		{
			i = m_pBuffGoodsList->erase(i);//消除该Buff对象
		}
		else
		{
			++i;
		}
	}

}

void Controller::ResetHero()
{
	if (m_pHeroLife->GetLifeNum() > 0)
	{
		m_pHero->Reset();
		m_pHero->SetFireMode(m_pImages->hImgBullet, heroCurentDemage, 0);
		m_pHeroHealth->SetHp(m_pHero->GetHealth());//获取生命值
		m_pHeroLife->SetLifeNum(m_pHeroLife->GetLifeNum() - 1);					//初始设置生命数3
		this->state = 1;
	}
}

void Controller::DrawStartBackGround(HDC hdc)
{
	HBITMAP tmpHbmp;
	HDC hdcsrc;
	BITMAP bmp;
	//绘制背景图
	tmpHbmp = m_pImages->hImgStartBg;
	hdcsrc = CreateCompatibleDC(hdc);
	SelectObject(hdcsrc, tmpHbmp);
	GetObject(tmpHbmp, sizeof(bmp), &bmp);
	BitBlt(hdc, 0, 0, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0,SRCCOPY);
	DeleteDC(hdcsrc);

	//绘制Enter图
	tmpHbmp = m_pImages->hImgEnter;
	hdcsrc = CreateCompatibleDC(hdc);
	SelectObject(hdcsrc, tmpHbmp);
	GetObject(tmpHbmp, sizeof(bmp), &bmp);
	TransparentBlt(hdc, 580, 400, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0,bmp.bmWidth,bmp.bmHeight, RGB(255,255,255));
	DeleteDC(hdcsrc);
}
void Controller::DrawGameOver(HDC hdc)
{
	HBITMAP tmpHbmp = m_pImages->hImgGameOver;
	HDC hdcsrc = CreateCompatibleDC(hdc);
	SelectObject(hdcsrc, tmpHbmp);
	BITMAP bmp;
	GetObject(tmpHbmp, sizeof(bmp), &bmp);
	TransparentBlt(hdc, (800 - bmp.bmWidth) / 2, (600 - bmp.bmHeight) / 2, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(255,255,255));
	DeleteDC(hdcsrc);
}
void Controller::DrawGameContinue(HDC hdc)
{
	HBITMAP tmpHbmp = m_pImages->hImgContinue;
	HDC hdcsrc = CreateCompatibleDC(hdc);
	SelectObject(hdcsrc, tmpHbmp);
	BITMAP bmp;
	GetObject(tmpHbmp, sizeof(bmp), &bmp);
	TransparentBlt(hdc, (800 - bmp.bmWidth) / 2, (600 - bmp.bmHeight) / 2, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(0, 0, 255));
	DeleteDC(hdcsrc);
}

void Controller::DrawScore(HDC hdc)
{
	HBITMAP tmpHbmp;
	HDC hdcsrc;
	BITMAP bmp;

	tmpHbmp = m_pImages->hImgPanel;
	hdcsrc = CreateCompatibleDC(hdc);
	SelectObject(hdcsrc, tmpHbmp);
	GetObject(tmpHbmp, sizeof(bmp), &bmp);
	TransparentBlt(hdc, 5,5, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(0, 0, 255));

	int num[5] = { 0 };
	num[4] = allScore % 10;
	num[3] = (allScore / 10) % 10;
	num[2] = (allScore / 100) % 10;
	num[1] = (allScore / 1000) % 10;
	num[0] = (allScore / 10000) % 10;
	for (int i = 0; i < 5; i++)
	{
		tmpHbmp = m_pImages->hImgNum[num[i]];
		SelectObject(hdcsrc, tmpHbmp);
		GetObject(tmpHbmp, sizeof(bmp), &bmp);
		TransparentBlt(hdc, 65+12*i, 25, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(255, 255, 255));

	}

	DeleteDC(hdcsrc);
}

void Controller::DrawStore(HDC hdc)
{
	HBITMAP tmpHbmp = m_pImages->hImgStore;
	HDC hdcsrc = CreateCompatibleDC(hdc);
	SelectObject(hdcsrc, tmpHbmp);
	BITMAP bmp;
	GetObject(tmpHbmp, sizeof(bmp), &bmp);
	TransparentBlt(hdc, (800 - bmp.bmWidth) / 2, (600 - bmp.bmHeight) / 2, bmp.bmWidth, bmp.bmHeight, hdcsrc, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(255, 255, 255));
	DeleteDC(hdcsrc);
}
bool Controller::Buy(int goodType)
{
	if (isStoreOpen)
	{
		if (goodType == 1)//满血
		{
			if (!m_pHero->IsDead() && m_pHero->GetHealth() != 100 && this->allScore >= 1000)
			{
				allScore -= 1000;//积分减1000
				m_pHero->SetHealth(100);//血量设为100
				m_pHeroHealth->SetHp(m_pHero->GetHealth());
			}
		}
		else if (goodType == 2)//加1攻击力
		{
			if (!m_pHero->IsDead() && this->allScore >= 1000)
			{
				allScore -= 1000;//积分减1000
				this->heroCurentDemage += 1;				
			}
		}
		else if (goodType == 3)//加3攻击力
		{
			if (!m_pHero->IsDead() && this->allScore >= 2500)
			{
				allScore -= 2500;//积分减2500
				this->heroCurentDemage += 3;
			}
		}
		else if (goodType == 4)//加3攻击力
		{
			if (!m_pHero->IsDead() && this->allScore >= 3500)
			{
				allScore -= 3500;//积分减3500
				this->heroCurentDemage += 5;
			}
		}
		else if (goodType == 5)//加30%攻击力
		{
			if (!m_pHero->IsDead() && this->allScore >= 50000)
			{
				allScore -= 50000;//积分减50000
				this->heroCurentDemage = (int)(heroCurentDemage*1.3);
			}
		}
		else if (goodType == 6)//加50%攻击力
		{
			if (!m_pHero->IsDead() && this->allScore >= 99000)
			{
				allScore -= 99000;//积分减99000
				this->heroCurentDemage = (int)(heroCurentDemage*1.5);
			}
		}
		else if (goodType == 7)//加一条命
		{
			if (!m_pHero->IsDead() && this->allScore >= 10000)
			{				
				if (this->m_pHeroLife->GetLifeNum() < 4)
				{
					allScore -= 10000;//积分减10000
					this->m_pHeroLife->SetLifeNum(m_pHeroLife->GetLifeNum() + 1);
				}
				
			}
		}
		else if (goodType == 8)//加Boss1
		{
			if (!m_pHero->IsDead() && this->allScore >= 50000)
			{	
				allScore -= 50000;//积分减50000
				this->m_pEnemyList->push_back(Enemy(m_pImages->hImgBoss, this, 50000, 1));
			}
		}
		else if (goodType == 9)//加Boss2
		{
			if (!m_pHero->IsDead() && this->allScore >= 50000)
			{
				allScore -= 50000;//积分减50000
				this->m_pEnemyList->push_back(Enemy(m_pImages->hImgBoss, this, 100000, 2));
			}
		}
		else if (goodType == 0)//加Boss3
		{
			if (!m_pHero->IsDead() && this->allScore >= 50000)
			{
				allScore -=50000;//积分减50000
				this->m_pEnemyList->push_back(Enemy(m_pImages->hImgBoss, this, 150000, 3));
			}
		}
		else if (goodType == 10)//加Boss4
		{
			if (!m_pHero->IsDead() && this->allScore >= 50000)
			{
				allScore -= 50000;//积分减50000
				this->m_pEnemyList->push_back(Enemy(m_pImages->hImgBoss, this, 200000, 4));
			}
		}
		else if (goodType == 11)//能量弹
		{
			if (!m_pHero->IsDead() && this->isGotGoods1&&this->isGotGoods2&&this->isGotGoods3&&this->isGotGoods4)
			{
				this->SetGotGoods(-1, -1, -1, -1);
				this->heroCurentDemage *= 10;
				this->m_pHero->SetFireMode(m_pImages->hImgSuperBullet, this->heroCurentDemage, 4);
			}
		}

	}
	return false;	
}

void Controller::SetGotGoods(int g1, int g2, int g3, int g4)
{
	if (g1 == 1)
		this->isGotGoods1 = true;
	if (g2 == 1)
		this->isGotGoods2 = true;
	if (g3 == 1)
		this->isGotGoods3 = true;
	if (g4 == 1)
		this->isGotGoods4 = true;
	if (g1 == -1)
		this->isGotGoods1 = false;
	if (g2 == -1)
		this->isGotGoods2 = false;
	if (g3 == -1)
		this->isGotGoods3 = false;
	if (g4 == -1)
		this->isGotGoods4 = false;
}
void Controller::AddGoods(int goodsType)
{
	if (goodsType == 1)
		m_pBuffGoodsList->push_back(BuffGoods(m_pImages->hImgGoods[0], 6));
	if (goodsType == 2)
		m_pBuffGoodsList->push_back(BuffGoods(m_pImages->hImgGoods[1], 7));
	if (goodsType == 3)
		m_pBuffGoodsList->push_back(BuffGoods(m_pImages->hImgGoods[2], 8));
	if (goodsType == 4)
		m_pBuffGoodsList->push_back(BuffGoods(m_pImages->hImgGoods[3], 9));
}

void Controller::DrawAttribute(HDC hdc)
{
	//属性值面板
	int x = 450;
	int y = 520;

	static TCHAR atack[6] = {0};
	memset(atack, 0, sizeof(atack));
	sprintf_s(atack,sizeof(atack), "%d", this->heroCurentDemage);

	TextOut(hdc,x, y, "攻击力：", 8);
	TextOut(hdc, x+60, y, atack, strlen(atack));

	if (this->isGotGoods1)
		TextOut(hdc, x, y+30, "能量石：1", 9);
	else
		TextOut(hdc, x, y+30, "能量石：0", 9);
	if (this->isGotGoods2)
		TextOut(hdc, x, y + 60, "精魄石：1", 9);
	else
		TextOut(hdc, x, y + 60, "精魄石：0", 9);
	if (this->isGotGoods3)
		TextOut(hdc, x+80, y + 30, "黑  铁：1", 9);
	else
		TextOut(hdc, x+80, y + 30, "黑  铁：0", 9);
	if (this->isGotGoods4)
		TextOut(hdc, x+80, y + 60, "高能碳：1", 9);
	else
		TextOut(hdc, x+80, y + 60, "高能碳：0", 9);

}
