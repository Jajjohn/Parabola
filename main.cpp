#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <iostream>
#include <wingdi.h>
#include <cmath>

#define M_PI 3.14159265358979

using namespace std;

int main(void)
{
	SetConsoleTitle(L"counter");
	
	

	double start, stop, durationTime;
	start = clock();
	printf("初始速度");
	float v;
	float v1, v2;
	scanf_s("%f", &v);
	float t;
	
	float a;
	printf("加速度");
	scanf_s("%f", &a);
	float i;
	
	int  m , n;
	printf("初始X值");
	scanf_s("%d", &m);
	printf("初始Y值");
	scanf_s("%d", &n);


	printf("初始角度");
	scanf_s("%f", &i);
	double radians = i * M_PI/180;
	v1 = v * cos(radians);
	v2 = v * sin(radians);
	
	float x;
	float y;
		
		//HWND hWnd = ::FindWindow(TEXT("Windows.UI.Composition.DesktopWindowContentBridge"), TEXT("DesktopWindowXamlSource"));
		//HWND hWnd = GetConsoleWindow();
		//HDC hdc = ::GetDC(hWnd);
		//std::cout << hWnd << std::endl;

	HDC hdc = ::GetDC(NULL);

	for (t = 0; ;t+=0.02 )
	{
		v2 = v2 - a * t;
		y = -(v2 * t + ((a * t * t) / 2)) +n;
		x = v1 * t + m;
		
		SetPixel(hdc, x, y, RGB(255, 255, 255));
		SetPixel(hdc, x+1, y, RGB(255, 255, 255));
		SetPixel(hdc, x, y+1, RGB(255, 255, 255));
		SetPixel(hdc, x+1, y+1, RGB(255, 255, 255));

		Sleep(100);
	}
}
	
