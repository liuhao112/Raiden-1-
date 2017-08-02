#include "Explode.h"
#include "inc.h"

void MyPlaySound();

Explode::Explode(HBITMAP *hbmp, float x, float y, int num) :GameObject(hbmp[0])
{
	for (int i = 0; i < num; i++)
		this->explode[i] = hbmp[i];
	this->state = 0;
	this->SetX(x);
	this->SetY(y);
	this->isDead = false;
	thread t(MyPlaySound);//单独一个线程播放爆炸音效
	t.detach();
}


Explode::~Explode()
{
}
void Explode::DrawMe(HDC hdc)		//虚函数，渲染物体
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc,GetExplodeHBitMap());

		TransparentBlt(hdc, GetX(), GetY(), GetWidth(), GetHeight(), hdcsrc, 0, 0, GetWidth(), GetHeight(), RGB(255, 255, 255));
		DeleteDC(hdcsrc);
	}
	if (++state >= 20)
		this->isDead = true;
}
bool Explode::IsDead()
{
	return this->isDead;
}
HBITMAP Explode::GetExplodeHBitMap()
{
	BITMAP bmp;
	HBITMAP hbmp;
	if (state >= 0 && state <= 20)
	{
		hbmp= this->explode[state];
		GetObject(hbmp, sizeof(bmp), &bmp);
		this->SetWidth(bmp.bmWidth);
		this->SetHeight(bmp.bmHeight);
		return hbmp;
	}
	else
	{
		hbmp = this->explode[20];
		GetObject(hbmp, sizeof(bmp), &bmp);
		this->SetWidth(bmp.bmWidth);
		this->SetHeight(bmp.bmHeight);
		return hbmp;
	}
}

//播放音效函数
void MyPlaySound()
{
	MCI_DGV_OPEN_PARMS mciOpen;
	UINT wDeviceID;
	MCIERROR mciError;

	mciOpen.lpstrDeviceType = "avivideo"; //设备名
	mciOpen.lpstrElementName = "audio/explode.wav"; //设备元素

	mciError = mciSendCommand(0, MCI_OPEN,

		MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, //使用了设备元素

		(DWORD)&mciOpen);

	wDeviceID = mciOpen.wDeviceID; //保存设备ID

	MCI_DGV_PLAY_PARMS mciPlay;

	mciError = mciSendCommand(wDeviceID, MCI_PLAY,0,(DWORD)&mciPlay);
}