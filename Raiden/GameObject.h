#ifndef _GAMEOBJECT_H__
#define _GAMEOBJECT_H__

#include <Windows.h>
#include "Images.h"

class GameObject
{
public:
	GameObject(HBITMAP hbmp);			//���캯��
	virtual ~GameObject();				//����������
	float GetX();							//����x����
	void SetX(float x);					//����x����
	float GetY();							//����y����
	void SetY(float y);					//����y����
	float GetHeight();						//��������߶�
	void SetHeight(float height);			//��������߶�
	float GetWidth();						//����������
	void SetWidth(float width);			//����������
	void SetVisible(bool isVisible);	//��������ɼ���
	bool GetVisible();					//��������ɼ���
	void SetHBitMap(HBITMAP hbmp);		//����λͼ���
	HBITMAP GetHBitMap();				//����λͼ���
	bool IsCollision(GameObject *gobj);	//�ж����������Ƿ���ײ
	bool IsOutWindow();					//�ж������Ƿ���˴���
	virtual void DrawMe(HDC hdc) = 0;		//�麯������Ⱦ����
private:
	float x;			//����x����
	float y;			//����y����
	float height;		//����߶�
	float width;		//������
	bool isVisible;	//�Ƿ�ɼ�
	HBITMAP hbmp;	//λͼ���
};

#endif
