#pragma once
#include "Extra.h"

int N = 20, M = 20;
int Step = 20;//weight square
int w = Step * N, h = Step * M;//weight and height
int d = 0;//keyboard's condition
int speed = 300;


Snake sn;
Apple ap[20];
	
void DrawField()
{
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0;i < w;i+=20)
	{
		glBegin(GL_LINES);
		glVertex2f(i, h);
		glVertex2f(i, 0);
		glEnd();
	}

	for (int i = 0;i < w;i += 20)
	{
		glBegin(GL_LINES);
		glVertex2f(0, i);
		glVertex2f(w, i);
		glEnd();
	}
}

void Game_Over()
{
	switch (d)
	{
	case 0:// bump by left side
		for (int i = 8;i < 1024;i++)
		{
			int c = 0;
			bool b = false;
			while (c < 1024)
			{
				if (i != c) b = false;
				else { b = true; break; }
				c += 4;
			}
			if (!b) continue;
			if (sn.x[0] == sn.x[i] && sn.y[0] == sn.y[i])

			{
				MessageBox(NULL, "Failure: ", "Game_Over", MB_ICONHAND | IDOK | MB_OKCANCEL);
				exit(0);
			}


		}
		break;
	case 1://bump by up side
		for (int i = 8;i < 1024;i++)
		{
			int c = 1;
			bool b = false;
			while (c < 1024)
			{
				if (i != c) b = false;
				else { b = true; break; }
				c += 4;
			}
			if (!b) continue;
			if (sn.x[1] == sn.x[i] && sn.y[1] == sn.y[i])

			{
				MessageBox(NULL, "Failure: ", "Game_Over", MB_ICONHAND | IDOK | MB_OKCANCEL);
				exit(0);
			}

		}

		break;
	case 2://bump by right side
		for (int i = 8;i < 1024;i++)
		{
			int c = 2;
			bool b = false;
			while (c < 1024)
			{
				if (i != c) b = false;
				else { b = true; break; }
				c += 4;
			}
			if (!b) continue;
			if (sn.x[2] == sn.x[i] && sn.y[2] == sn.y[i])

			{
				MessageBox(NULL, "Failure ", "Game_Over", MB_ICONHAND | IDOK | MB_OKCANCEL);
				exit(0);
			}
				
			
		}
		break;
	case 3:// bump by down side
		for (int i = 8;i < 1024;i++)
		{
			int c = 3;
			bool b = false;
			while (c < 1024)
			{
				if (i != c) b = false;
				else { b = true; break; }
				c += 4;
			}
			if (!b) continue;
			if (sn.x[3] == sn.x[i] && sn.y[3] == sn.y[i])
			{
				MessageBox(NULL, "Failure ", "Game_Over", MB_ICONHAND | IDOK | MB_OKCANCEL);
				exit(0);
			}
			
		}
		break;

	}
}

void keybords(int key, int x, int y)
{
	
	switch (key)
	{
	case GLUT_KEY_LEFT: if (d == 2) d = 2;
		else d = 0; break;//left
	case GLUT_KEY_UP: if (d == 3) d = 3;
		else d = 1; break;//up
	case GLUT_KEY_RIGHT: if (d == 0) d = 0;
		else d = 2; break;//right
	case GLUT_KEY_DOWN: if (d == 1) d = 1;
		else d = 3; break;//down
	}

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.3, 0.5, 0.5,0.0);
	
	for (int i = 0;i < 20;i++)
	{
		ap[i].Draw_Apple();
	
	}
	sn.Draw_Snake(d);
	DrawField();
	
	
		
	glFlush();
}

void timer(int = 0)
{
	for (int i = 0;i < 20;i++)//Add_apple
	{
		if (sn.x[0] == ap[i].x1[0] && sn.y[0] == ap[i].y1[0])
		{
			sn.size++; ap[i].New();
		}
	}
	
	sn.Move_Snake(d);
	Game_Over();
	display();
	switch (sn.size)
	{
	case 5: speed = 200; break;
	case 8: speed = 150; break;
	case 12: speed = 130;break;
	case 15: speed = 100;break;
	}

	glutTimerFunc(speed, timer, 0);
}


int main(int argc, char** argv)
{
	for (int i = 0;i < 20;i++)
	{
		ap[i].New();
	}
		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(500,0);

	glutCreateWindow("Snake");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glEnable(GL_TEXTURE_2D);

	
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(keybords);
	
	glutMainLoop();
	
	return 1;
}