#define GLUT_DISABLE_ATEXIT_HACK
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
#include<GL/glut.h>

#define COLUMNS 40
#define ROWS 40


void intro();
void display_game();
void reshape_window(int,int);
void unit(int x, int y);
void initGrid(int, int);
void drawGrid();
int gridX, gridY;

void init()
{
	glClearColor(0.0, 0.5, 0.0, 0.0);			//dark green color on first screen
	initGrid(COLUMNS, ROWS);
}


void grass()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	
	glVertex2f(1,1);
	glVertex2f(4,1);
	glVertex2f(2, 3);

	glEnd();
}


//game screen
void display_game()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);		//background colour of the game screen
	drawGrid();
	grass();
	glutSwapBuffers();
}

//initializing grid
void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

//function to draw grid
void drawGrid()
{
	for (int x = 5; x < gridX-5 ; x++)		//gridX = 40
	{
		for (int y = 5; y < gridY-5 ; y++)			//gridY = 40
		{
			unit(x, y);
		}
	}
}

void unit(int x, int y)
{
	if (x == 5 || y == 5 || x == gridX - 6 || y == gridY - 6)
	{
		glLineWidth(5.0);
		glColor3f(0.0, 0.0, 1.0);			//wall colour
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void reshape_window(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);		//covers whole area of the window 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);

}

//first screen - introduction
void intro()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(12, 35, 0);
	char msg1[] = "||  SLYTHERIN (snake game)  ||";
	for (int i = 0; i < strlen(msg1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);

	glRasterPos3f(6, 29, 0);
	char msg2[] = "SUBMITTED BY:    REVISHA SHAREEN VAS   (4SO18CS096)";
	for (int i = 0; i < strlen(msg2); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg2[i]);

	glRasterPos3f(6, 25, 0);
	char msg3[] = "AND:    RHEA BENEDICTA D'SOUZA   (4SO18CS097)";
	for (int i = 0; i < strlen(msg3); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg3[i]);
	/*glRasterPos3f(16, 25, 0);
	char msg4[] = "RHEA BENEDICTA D'SOUZA   (4SO18CS097)";
	for (int i = 0; i < strlen(msg4); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg4[i]);*/
	glRasterPos3f(6, 21, 0);
	char msg6[] = "UNDER THE GUIDANCE OF:    MR ROHAN DON SALINS";
	for (int i = 0; i < strlen(msg6); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg6[i]);


	glRasterPos3f(12, 12, 0);
	char msg5[] = "PRESS X TO START THE GAME ";
	for (int i = 0; i < strlen(msg5); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg5[i]);

	glutSwapBuffers();
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		glutDisplayFunc(display_game);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);			//initializing glut
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);			//initializing display mode
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("SNAKE GAME");
	glutDisplayFunc(intro);
	glutReshapeFunc(reshape_window);
	glutKeyboardFunc(keys);
	init();
	sndPlaySound(_T("breakout.wav"),SND_ASYNC);
	glutMainLoop();
	return 0;
}
