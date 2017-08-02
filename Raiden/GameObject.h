#ifndef _GAMEOBJECT_H__
#define _GAMEOBJECT_H__

#include <Windows.h>
#include "Images.h"

class GameObject
{
public:
	GameObject(HBITMAP hbmp);			//构造函数
	virtual ~GameObject();				//虚析构函数
	float GetX();							//返回x坐标
	void SetX(float x);					//设置x坐标
	float GetY();							//返回y坐标
	void SetY(float y);					//设置y坐标
	float GetHeight();						//返回物体高度
	void SetHeight(float height);			//设置物体高度
	float GetWidth();						//返回物体宽度
	void SetWidth(float width);			//设置物体宽度
	void SetVisible(bool isVisible);	//设置物体可见性
	bool GetVisible();					//返回物体可见性
	void SetHBitMap(HBITMAP hbmp);		//设置位图句柄
	HBITMAP GetHBitMap();				//返回位图句柄
	bool IsCollision(GameObject *gobj);	//判断两个物体是否相撞
	bool IsOutWindow();					//判断物体是否出了窗口
	virtual void DrawMe(HDC hdc) = 0;		//虚函数，渲染物体
private:
	float x;			//物体x坐标
	float y;			//物体y坐标
	float height;		//物体高度
	float width;		//物体宽度
	bool isVisible;	//是否可见
	HBITMAP hbmp;	//位图句柄
};

#endif
