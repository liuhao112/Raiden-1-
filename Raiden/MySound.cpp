#include "MySound.h"


MySound::MySound()
{
}


MySound::~MySound()
{
}

DWORD MySound::Play(HWND hWnd, char* fileName)
{
	//����MidiӲ��װ��
	this->mciOpenParms.lpstrDeviceType = "sequencer";
	//�������ļ�
	this->mciOpenParms.lpstrElementName = fileName;
	//ʹ��Command��ʽ
	if (dwReturn = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpenParms))
		return (dwReturn);
	//�豸�򿪳ɹ�����ȡ�豸ID
	wDeviceID = mciOpenParms.wDeviceID;
	//�������˿���MIDI mapper
	mciStatusParms.dwItem = MCI_SEQ_STATUS_PORT;
	if (dwReturn = mciSendCommand(wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return dwReturn;
	}

	//�ظ�������Ҫ�ó�����յ�MM_MCINOTIFY��Ϣ
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