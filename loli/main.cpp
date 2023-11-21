#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define scale	0	
#define pic 839

#if	scale==1

#define element 194 * 54
char folder[10] = "ASC";

#else

#define element 124 * 40
char folder[10] = "ASC_small";

#endif 

void gotoxy(int x, int y);
void HideCursor();
void modeset(int w, int h);

char ptr[element + 5];
char name[50];

int main()
{
	if (scale == 1)
	{
		modeset(200, 55);//���ô��ڴ�С 
	}
	else
	{
		modeset(130, 45);//���ô��ڴ�С 
	}

	FILE* fp;
	HideCursor();//���ع�� 
	mciSendString(L"open loli.mp3", NULL, 0, NULL);
	mciSendString(L"play loli.mp3", NULL, 0, NULL);
	Sleep(300);

	for (int i = 1; i <= pic; i++)
	{
		sprintf(name, "./%s/ASCII-%d.txt", folder, i);
		fp = fopen(name, "r");
		fread(ptr, 1, element, fp);
		printf("%s", ptr);
		fclose(fp);
		gotoxy(0, 0);
		Sleep(38);
	}
	return 0;
}

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1;  //���û��ֵ�Ļ������ع����Ч
	curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}

void modeset(int w, int h) {
	//	�˺������ô��ڴ�СΪ w*h
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = { w * 2, h * 2 };
	SetConsoleScreenBufferSize(hOut, size);
	SMALL_RECT rc = { 1,1, w, h };
	SetConsoleWindowInfo(hOut, true, &rc);
	system("cls");
	return;
}

