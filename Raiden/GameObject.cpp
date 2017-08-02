#include "inc.h"
#include "GameObject.h"

GameObject::GameObject(HBITMAP hbmp)
{
	BITMAP bmp;
	this->hbmp = hbmp;
	GetObject(hbmp, sizeof(bmp), &bmp);
	this->x = 0;
	this->y = 0;
	this->width= bmp.bmWidth;
	this->height = bmp.bmHeight;
	this->SetVisible(true);
}


GameObject::~GameObject()
{

}

float GameObject::GetX()
{
	return this->x;
}

void GameObject::SetX(float x)
{
	this->x = x;
}

float GameObject::GetY()
{
	return this->y;
}

void GameObject::SetY(float y)
{
	this->y = y;
}

float GameObject::GetHeight()
{
	return this->height;
}

void GameObject::SetHeight(float height)
{
	this->height = height;
}

float GameObject::GetWidth()
{
	return this->width;
}

void GameObject::SetWidth(float width)
{
	this->width = width;
}

void GameObject::SetVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

bool GameObject::GetVisible()
{
	return this->isVisible;
}

void GameObject::SetHBitMap(HBITMAP hbmp)		//设置位图句柄
{
	this->hbmp = hbmp;
}
HBITMAP GameObject::GetHBitMap()				//返回位图句柄
{
	return hbmp;
}

bool GameObject::IsCollision(GameObject *gobj)				//判断两个物体是否相撞
{
	if (gobj == nullptr)
		return false;
	float h1, h2, w1, w2, r1, r2;
	h1 = this->GetHeight();
	h2 = gobj->GetHeight();
	w1 = this->GetWidth();
	w2 = gobj->GetWidth();

	r1 = sqrt(h1*h1 + w1*w1)/2;
	r2 = sqrt(h2*h2 + w2*w2)/2;
	float x1, y1, x2, y2;
	x1 = this->GetX() + this->GetWidth() / 2;
	y1 = this->GetY() + this->GetHeight() / 2;
	x2 = gobj->GetX() + gobj->GetWidth() / 2;
	y2 = gobj->GetY() + gobj->GetHeight() / 2;
	float distance;
	distance = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
	if (distance < r1 + r2)
		return true;
	else
		return false;
}

bool GameObject::IsOutWindow()				//判断物体是否出了窗口
{
	if (this->GetX() + this->GetWidth() <= 0)
		return true;
	if (this->GetX() >= 800)
		return true;
	if (this->GetY() + this->GetHeight() <= 0)
		return true;
	if (this->GetY() >= 600 )
		return true;
	return false;
}