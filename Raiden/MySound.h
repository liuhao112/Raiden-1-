#ifndef _MySound_H__
#define _MySound_H__

#include <Windows.h>
#include <mmsystem.h>

class MySound
{
public:
	MySound();
	~MySound();
	DWORD Play(HWND hWnd,char* fileName);
	void Stop();
	void Replay();
private:
	UINT wDeviceID;//MCI…Ë±∏∫≈
	DWORD dwReturn;
	MCI_OPEN_PARMS mciOpenParms;
	MCI_PLAY_PARMS mciPlayParms;
	MCI_STATUS_PARMS mciStatusParms;
	MCI_SEQ_SET_PARMS mciSeqSetParms;

};

#endif

