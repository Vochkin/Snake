#pragma once
#include "Extra.h"

void Snake::Draw_Snake(int a)
{
	int k1 = 0; int i = 0;
	
	glBegin(GL_QUADS);
	for (int j = 0;j < size;j++)
	{
		if (j == 0) glColor3f(1.0, 0.0, 0.0);
		else glColor3f(1.0, 0.3, 0.2);
		glVertex2f((*this).x[k1], (*this).y[k1]);k1++;
		glVertex2f((*this).x[k1], (*this).y[k1]);k1++;
		glVertex2f((*this).x[k1], (*this).y[k1]);k1++;
		glVertex2f((*this).x[k1], (*this).y[k1]);k1++;
		
		i += 20;
		
	}
	glEnd();

	
}

void Snake::Move_Snake(int a = 0)
{
	int k = 0, l = 0, siz = size;

	glColor3f(1.0, 0.3, 0.2);

	if (a == 0)
	{
		k = 0;
		glBegin(GL_QUADS);
		for (int i = 0;i < size;i++)
		{
			if (i == size - 1 && (*this).x[5] <= 0)//bump into side
			{
				exit( a = 2);
			}
			if (siz == 1)
			{
				(*this).x[k] = (*this).x[k] - N; (*this).y[k];k++;
				(*this).x[k] = (*this).x[k] - N; (*this).y[k];k++;
				(*this).x[k] = (*this).x[k] - N; (*this).y[k];k++;
				(*this).x[k] = (*this).x[k] - N; (*this).y[k];k++;
				continue;
			}
			l = siz * 4 - 4;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			siz--;
			
		}
		glEnd();
	}

	if (a == 1)
	{
		k = 0, siz = size;
		glBegin(GL_QUADS);
		for (int i = 0;i < size;i++)
		{
			if (i == size - 1 && (*this).y[5] >= h)//bump into side
			{
				exit(a = 3);
			}

			if (siz == 1)
			{
				(*this).x[k]; (*this).y[k] += M;k++;
				(*this).x[k]; (*this).y[k] += M;k++;
				(*this).x[k]; (*this).y[k] += M;k++;
				(*this).x[k]; (*this).y[k] += M;k++;
				continue;
			}

			l = siz * 4 - 4;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			siz--;
		}
		glEnd();

	}

	if (a == 2)
	{
		if ((*this).x[2] == w)
		{
			a = 0;
		}
		k = 0, siz = size;
		glBegin(GL_QUADS);
		for (int i = 0;i < size;i++)
		{
			if (i == size - 1 && (*this).x[6] >= w)//bump into side
			{
				exit(a = 0);
			}
			if (siz == 1)
			{
				(*this).x[k] = (*this).x[k] + N; (*this).y[k];k++;
				(*this).x[k] = (*this).x[k] + N; (*this).y[k];k++;
				(*this).x[k] = (*this).x[k] + N; (*this).y[k];k++;
				(*this).x[k] = (*this).x[k] + N; (*this).y[k];k++;
				continue;
			}
			l = siz * 4 - 4;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			siz--;
		}
		glEnd();
	}

	if (a == 3)
	{
		if ((*this).y[1] < 0)
		{
			a = 1;
		}
		k = 0, siz = size;
		glBegin(GL_QUADS);
		for (int i = 0;i < size;i++)
		{
			if (i == size - 1 && (*this).y[4] <= 0)//bump into side
			{
				exit(a = 1);
			}
			if (siz == 1)
			{
				(*this).x[k]; (*this).y[k] -= M;k++;
				(*this).x[k]; (*this).y[k] -= M;k++;
				(*this).x[k]; (*this).y[k] -= M;k++;
				(*this).x[k]; (*this).y[k] -= M;k++;
				continue;
			}

			l = siz * 4 - 4;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			(*this).x[l] = (*this).x[l - 4]; (*this).y[l] = (*this).y[l - 4];l++;
			siz--;
		}
		glEnd();
	}
	
}

void Apple::Draw_Apple()
{
	glColor3f(0.0, 1.0, 0.0);
	
	int i = 0;
		
	glBegin(GL_QUADS);

	glVertex2f((*this).x1[i], (*this).y1[i]);
	glVertex2f((*this).x1[i + 1], (*this).y1[i + 1]);
	glVertex2f((*this).x1[i + 2], (*this).y1[i + 2]);
	glVertex2f((*this).x1[i + 3], (*this).y1[i + 3]);
			
	glEnd();
	
}

void Apple::New()//generetion a random numbers
{
	int i = 0;
	(*this).x1[i] = (rand() % (h - N));
	if ((*this).x1[i] % Step)
	{
		if ((*this).x1[i] % Step < 10)
		{
			(*this).x1[i] -= ((*this).x1[i] % Step);
		}
		if ((*this).x1[i] % Step >= 10)
		{
			(*this).x1[i] += (Step - ((*this).x1[i] % Step));
		}
	}
	(*this).y1[i] = (rand() % (w - M));
	if ((*this).y1[i] % Step)
	{
		if ((*this).y1[i] % Step < 10)
		{
			(*this).y1[i] -= ((*this).y1[i] % Step);
		}
		if ((*this).y1[i] % Step >= 10)
		{
			(*this).y1[i] += (Step - ((*this).y1[i] % Step));
		}
	}

	(*this).x1[i + 1] = (*this).x1[i]; (*this).y1[i + 1] = (*this).y1[i] + M;
	(*this).x1[i + 2] = (*this).x1[i] + N, (*this).y1[i + 2] = (*this).y1[i] + M;
	(*this).x1[i + 3] = (*this).x1[i] + N, (*this).y1[i + 3] = (*this).y1[i];

	
}