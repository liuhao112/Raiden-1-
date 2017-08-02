#include "inc.h"
#include "BackGround.h"

BackGround::BackGround(HBITMAP hbmp) :GameObject(hbmp)
{
	
}


BackGround::~BackGround()
{

}

void BackGround::DrawMe( HDC hdc)		//Ðéº¯Êý£¬äÖÈ¾ÎïÌå
{
	if (this->GetVisible())
	{
		HDC hdcsrc = CreateCompatibleDC(hdc);
		SelectObject(hdcsrc, GetHBitMap());
		BitBlt(hdc, GetX(), GetY() - 600, GetWidth(), GetHeight(), hdcsrc, 0, 0, SRCCOPY);
		BitBlt(hdc, GetX(), GetY(), GetWidth(), GetHeight(), hdcsrc, 0, 0, SRCCOPY);

		DeleteDC(hdcsrc);
	}		
}

void BackGround::BackGroundRun()
{
	static int i = 0;
	this->SetY(++i % 600);
}