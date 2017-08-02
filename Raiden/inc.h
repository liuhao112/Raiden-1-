#ifndef _INC_H__
#define _INC_H__

#include <Windows.h>
#include <list>
#include <cmath>
#include <random>
#include <ctime>
#include <Digitalv.h>
#include <vfw.h>
#include <mmsystem.h>
#include <thread>

#include "resource1.h"

#pragma comment(lib,"Msimg32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"vfw32.lib")
using namespace std;

enum BulletDirection{ U, LUU, RUU, LU, LLU, RU, RRU, LD, LLD, RD, RRD, LDD, RDD, D, L, R };//子弹type


#endif
