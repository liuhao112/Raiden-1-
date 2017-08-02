#include "MySound.h"


MySound::MySound()
{
}


MySound::~MySound()
{
}

DWORD MySound::Play(HWND hWnd, char* fileName)
{
	//开启Midi硬体装置
	this->mciOpenParms.lpstrDeviceType = "sequencer";
	//待播放文件
	this->mciOpenParms.lpstrElementName = fileName;
	//使用Command方式
	if (dwReturn = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpenParms))
		return (dwReturn);
	//设备打开成功，获取设备ID
	wDeviceID = mciOpenParms.wDeviceID;
	//检查输出端口是MIDI mapper
	mciStatusParms.dwItem = MCI_SEQ_STATUS_PORT;
	if (dwReturn = mciSendCommand(wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return dwReturn;
	}

	//重复播放需要让程序接收到MM_MCINOTIFY消息
	mciPlayParms.dwCallback = (DWORD)hWnd;

	if (dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlayParms))
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return dwReturn;
	}
	return 0;
}
void MySound::Stop()
{
	mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
}
void MySound::Replay()
{
	mciSendCommand(wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlayParms);
}