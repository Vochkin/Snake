#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <gl\glut.h>
#include <gl\GL.h>
#include <random>
#include <time.h>


using namespace std;

extern  int M, N, Step, d, d2, w, h;

class Snake
{
public:
	int x[1024];
	int y[1024];
	int size = 3;//amount quard at the begin


	Snake() {
		int k1 = 0; int i = 0;
		for (int j = 0;j < size;j++)
		
		{
			(*this).x[k1] = (w / 2 + i - N); (*this).y[k1] = h / 2;k1++;
			(*this).x[k1] = w / 2 + i - N; (*this).y[k1] = h / 2 + M;k1++;
			(*this).x[k1] = w / 2 + i; (*this).y[k1] = h / 2 + M;k1++;
			(*this).x[k1] = w / 2 + i; (*this).y[k1] = h / 2;k1++;	

			i += 20;

		}
		
	}
	void Draw_Snake(int);
	void Move_Snake(int);
};

class Apple
{
public:
	
	int x1[16];
	int y1[16];

	void New();
	void Draw_Apple();
	
};

