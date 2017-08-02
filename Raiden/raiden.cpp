#include "inc.h"
#include "Controller.h"

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void Init(HWND hWnd);
void Destroy();

//全局变量
Controller *g_pController;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR cmdLine, int iShow)
{
	srand(time(NULL));
	WNDCLASSEX wcs;
	HWND hWnd;
	MSG msg;
	TCHAR appName[40] = "Raiden";
	

	wcs.cbClsExtra = 0;
	wcs.cbSize = sizeof(WNDCLASSEX);
	wcs.cbWndExtra = 0;
	wcs.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcs.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcs.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcs.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcs.hInstance = hInst;
	wcs.lpfnWndProc = WndProc;
	wcs.lpszClassName = appName;
	wcs.lpszMenuName = NULL;
	wcs.style = CS_HREDRAW|CS_VREDRAW;

	if (!RegisterClassEx(&wcs))
	{
		MessageBox(NULL, "注册窗口类失败!", "错误", MB_OK);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_APPWINDOW, appName, appName, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME, CW_USEDEFAULT, CW_USEDEFAULT,
		810,638,GetDesktopWindow(),NULL,hInst,NULL);
	if (FAILED(hWnd))
	{
		MessageBox(NULL, "创建窗口失败!", "错误", MB_OK);
		return 0;
	}

	Init(hWnd);

	::ShowWindow(hWnd, SW_SHOWDEFAULT);
	::UpdateWindow(hWnd);

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (g_pController != nullptr)
			{
				g_pController->RenderScene();
				Sleep(10);
			}
		}
	}

	UnregisterClass(appName, wcs.hInstance);
	Destroy();
	return 0;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	case WM_KEYUP:
		if (g_pController != nullptr)
		{
			if (wParam == VK_UP)
				g_pController->SetGoingUp(false);
			if (wParam == VK_DOWN)
				g_pController->SetGoingDown(false);
			if (wParam == VK_LEFT)
				g_pController->SetGoingLeft(false);
			if (wParam == VK_RIGHT)
				g_pController->SetGoingRight(false);
			if (wParam == VK_SPACE)
				g_pController->SetHeroFire(false);
		}
		break;
	case WM_KEYDOWN:
		if (g_pController != nullptr)
		{
			if (wParam == VK_UP)
				g_pController->SetGoingUp(true);
			if (wParam == VK_DOWN)
				g_pController->SetGoingDown(true);
			if (wParam == VK_LEFT)
				g_pController->SetGoingLeft(true);
			if (wParam == VK_RIGHT)
				g_pController->SetGoingRight(true);
			if (wParam == VK_SPACE)
				g_pController->SetHeroFire(true);
			if (wParam == VK_ESCAPE)
				g_pController->GamePause();
			if (wParam == 'R')
				g_pController->ResetHero();
			if (wParam == 'P')
				g_pController->OpenStore();
			if (wParam == 48)
				g_pController->Buy(0);
			if (wParam == 49)
				g_pController->Buy(1);
			if (wParam == 50)
				g_pController->Buy(2);
			if (wParam == 51)
				g_pController->Buy(3);
			if (wParam == 52)
				g_pController->Buy(4);
			if (wParam == 53)
				g_pController->Buy(5);
			if (wParam == 54)
				g_pController->Buy(6);
			if (wParam == 55)
				g_pController->Buy(7);
			if (wParam == 56)
				g_pController->Buy(8);
			if (wParam == 57)
				g_pController->Buy(9);
			if (wParam == VK_OEM_MINUS)
				g_pController->Buy(10);
			if (wParam == VK_OEM_PLUS)
				g_pController->Buy(11);

			if (wParam == VK_RETURN)
				g_pController->GameStart();
		}		
		break;
	case MM_MCINOTIFY:

		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void Init(HWND hWnd)
{
	if (g_pController == nullptr)
	{
		g_pController = new Controller(hWnd);
	}
}

void Destroy()
{
	if (g_pController != nullptr)
	{
		delete g_pController;
		g_pController = nullptr;
	}
}