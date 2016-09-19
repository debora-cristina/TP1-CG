#include <GL/glut.h>
#include <gl/glut.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Personagem.h"
#include "Caminhao.h"
#include "Madeira.h"
#include <stdlib.h>
#include <vector>

using namespace std;


GLint FPS = 0;
//const int TIMERMSECS = 20;
//float animation_time = 0;
//const float  animation_step = .5;

Personagem p1;
Caminhao c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20;
Madeira m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20;


GLint ClickON = 0;
GLint break1 = 0;
GLfloat timer2 = 3.3;

// Tamanho e posição inicial do quadrado
GLfloat x2 = 250.0f;
GLfloat y2 = 0.0f;
GLfloat x3 = 0.0f;
GLfloat y3 = 55.0f;
GLfloat x4 = -50.0f;
GLfloat y4 = 105.0f;
GLfloat x5 = -130.0f;
GLfloat y5 = 155.0f;
GLfloat x6 = 0.0f;
GLfloat y6 = 205.0f;
GLfloat x7 = 0.0f;
GLfloat y7 = 280.0f;
GLfloat x8 = 0.0f;
GLfloat y8 = 330.0f;
GLfloat x9 = 0.0f;
GLfloat y9 = 380.0f;
GLfloat x10 = 0.0f;
GLfloat y10 = 405.0f;



GLsizei rsize = 30;

// Tamanho do incremento nas direções x e y 
// (número de pixels para se mover a cada
// intervalo de tempo)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

/*#include <string>
include <iostream>
#include <stdlib.h>
#include <stdio.h>*/

// Constantes
#define QUADRADO 1
#define TRIANGULO 2
#define LOSANGO   3
#define MENU 4
#define ANIMACAO 5
#define SAIR 6
#define MENUPRESS1 7
#define MENUPRESS2 8
#define MENUPRESS3 9
#define MENUPRESS4 10
#define LERARQUIVO 11

// Variáveis
char texto[30];
GLfloat win, r, g, b;
GLint view_w, view_h, primitiva;
vector<Caminhao> caminhoes;
vector<Madeira> madeiras;


void Desenha(void);
void DesenhaTexto(char *string, void *font, GLfloat xAux, GLfloat yAux);
void MoveMouse(int x, int y);
void MoveMouseBotaoPressionado(int x, int y);

void GerenciaTeclado(unsigned char key, int x, int y)
{
	int c = key;

	switch (c) {

	case 13:
		primitiva = MENU;
		break1 = 1;
		break;
	case 114:
		primitiva = MENU;
		break;
	case 27:
		primitiva = SAIR;
		break;

	}

	if (primitiva == QUADRADO) {
		switch (c) {

		case 119:
			p1.setY(p1.getY() + 10);
			if (p1.getY() > 470)
			{
				p1.setY(470);
			}
			break;
		case 115:
			p1.setY(p1.getY() - 10);
			if (p1.getY() <0) p1.setY(0);
			break;
		case 97:
			p1.setX(p1.getX() - 10);
			if (p1.getX() < 0) p1.setX(0);
			break;
		case 100:
			p1.setX(p1.getX() + 10);
			if (p1.getX() >470) p1.setX(470);

			break;



		}
	}










	glutPostRedisplay();
}



/*void FPS1(void) {
static GLint frameCounter = 0;         // frames averaged over 1000mS
static GLuint currentClock;             // [milliSeconds]
static GLuint previousClock = 0; // [milliSeconds]
static GLuint nextClock = 0;     // [milliSeconds]

++frameCounter;
currentClock = glutGet(GLUT_ELAPSED_TIME); //has limited resolution, so average over 1000mS
if (currentClock < nextClock) return;

FPS = frameCounter / 1; // store the averaged number of frames per second

previousClock = currentClock;
nextClock = currentClock + 1000; // set the next clock to aim for as 1 second in the future (1000 ms)
frameCounter = 0;
}*/

/*void idle() {
static GLuint previousClock = glutGet(GLUT_ELAPSED_TIME);
static GLuint currentClock = glutGet(GLUT_ELAPSED_TIME);
static GLfloat deltaT;

currentClock = glutGet(GLUT_ELAPSED_TIME);
deltaT = currentClock - previousClock;
if (deltaT < 35) { return; }
else { previousClock = currentClock; }

// put your idle code here, and it will run at the designated fps (or as close as the machine can get

printf(".");
//end your idle code here

FPS1(); //only call once per frame loop
glutPostRedisplay();
}*/

/*void escreve(int width, int height, int x, int y, void *font, string texto)
{
float xxx = (float)x / width;
float yyy = (float)y / height;
//glColor3f (0,0,0);
glRasterPos2f(xxx, yyy);
for (int i = 0; i<texto.length(); i++)
glutBitmapCharacter(font, texto.at(i));
}*/


/*void Delay(int t) {
float time_elapsed = TIMERMSECS / 1000.0;
float current_step = animation_step* time_elapsed;
if (current_step < animation_step * 2)
animation_time += current_step;
glutPostRedisplay();
glutTimerFunc(TIMERMSECS, Delay, 0);
}*/

void InicializaPersonagem()
{
	p1.setX(250);
	p1.setY(0);
}


void Timer(int value)
{


	// Move o quadrado
	c1.setX(c1.getX() + 1);
	c2.setX(c2.getX() + 1.3);
	c3.setX(c3.getX() + 1.6);
	c4.setX(c4.getX() + 1);
	c5.setX(c5.getX() + 1.3);
	c6.setX(c6.getX() + 1.6);
	c7.setX(c7.getX() + 1);
	c8.setX(c8.getX() + 1.3);
	c9.setX(c9.getX() + 1.6);
	c10.setX(c10.getX() + 1);
	c11.setX(c11.getX() + 1.3);
	c12.setX(c12.getX() + 1.6);
	c13.setX(c13.getX() + 1);
	c14.setX(c14.getX() + 1.3);
	c15.setX(c15.getX() + 1.6);
	c16.setX(c16.getX() + 1);
	c17.setX(c17.getX() + 1.3);
	c18.setX(c18.getX() + 1.6);


	m1.setX(m1.getX() + 0.5);
	m2.setX(m2.getX() + 0.8);
	m3.setX(m3.getX() + 0.6);
	m4.setX(m4.getX() + 0.5);
	m5.setX(m5.getX() + 0.8);
	m6.setX(m6.getX() + 0.6);
	m7.setX(m7.getX() + 0.5);
	m8.setX(m8.getX() + 0.8);
	m9.setX(m9.getX() + 0.6);
	m10.setX(m10.getX() + 0.5);
	m11.setX(m11.getX() + 0.8);
	m12.setX(m12.getX() + 0.6);
	m13.setX(m13.getX() + 0.5);
	m14.setX(m14.getX() + 0.8);
	m15.setX(m15.getX() + 0.6);
	m16.setX(m16.getX() + 0.5);
	m17.setX(m17.getX() + 0.8);
	m18.setX(m18.getX() + 0.6);



	// Redesenha o quadrado com as novas coordenadas 
	glutPostRedisplay();
	glutTimerFunc(3.3, Timer, 1);

}

void DesenhaAnimacao() {


	glutKeyboardFunc(GerenciaTeclado);
	glutKeyboardUpFunc(GerenciaTeclado);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica que a cor corrente é vermelha
	//         R     G     B
	glColor3f(1.0f, 1.0f, 0.0f);

	for (int i = 0; i < 500; i++) {
		glutKeyboardFunc(GerenciaTeclado);
		glutKeyboardUpFunc(GerenciaTeclado);

		//break1 = getch();

		if (break1 != 0)
		{
			break1 = 0;
			break;
		};


		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0.0f, 0.0f, 0.0f);

		glBegin(GL_QUADS);

		glColor3f(0.7f, 0.4f, 0.3f);
		glVertex2i(0, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 50);
		glVertex2i(0, 50);
		glEnd();


		glBegin(GL_QUADS);

		glColor3f(0.7f, 0.4f, 0.3f);
		glVertex2i(0, 275);
		glVertex2i(500, 275);
		glVertex2i(500, 225);
		glVertex2i(0, 225);
		glEnd();


		glBegin(GL_QUADS);
		glColor3f(0.7f, 0.4f, 0.3f);
		glVertex2i(0, 430);
		glVertex2i(500, 430);
		glVertex2i(500, 500);
		glVertex2i(0, 500);
		glEnd();



		glBegin(GL_QUADS);

		glColor3f(0.0f, 0.4f, 0.8f);
		glVertex2i(0, 275);
		glVertex2i(500, 275);
		glVertex2i(500, 430);
		glVertex2i(0, 430);
		glEnd();



		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 0.1f);
		glVertex2i(50, 145);
		glVertex2i(150, 145);
		glVertex2i(150, 125);
		glVertex2i(50, 125);
		glEnd();


		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 0.1f);
		glVertex2i(250, 145);
		glVertex2i(350, 145);
		glVertex2i(350, 125);
		glVertex2i(250, 125);
		glEnd();


		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 0.1f);
		glVertex2i(450, 145);
		glVertex2i(550, 145);
		glVertex2i(550, 125);
		glVertex2i(450, 125);
		glEnd();





		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x3), GLint(y3 + 40));
		glVertex2i(GLint(x3), GLint(y3));
		glVertex2i(GLint(x3 + 100), GLint(y3));
		glVertex2i(GLint(x3 + 100), GLint(y3 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x4), GLint(y4 + 40));
		glVertex2i(GLint(x4), GLint(y4));
		glVertex2i(GLint(x4 + 100), GLint(y4));
		glVertex2i(GLint(x4 + 100), GLint(y4 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x5 - 30), GLint(y5 + 40));
		glVertex2i(GLint(x5 - 30), GLint(y5));
		glVertex2i(GLint(x5 + 100), GLint(y5));
		glVertex2i(GLint(x5 + 100), GLint(y5 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x7 + -80), GLint(y7 + 40));
		glVertex2i(GLint(x7 + -80), GLint(y7));
		glVertex2i(GLint(x7 + 70), GLint(y7));
		glVertex2i(GLint(x7 + 70), GLint(y7 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x8 - 190), GLint(y8 + 40));
		glVertex2i(GLint(x8 - 190), GLint(y8));
		glVertex2i(GLint(x8 - 30), GLint(y8));
		glVertex2i(GLint(x8 - 30), GLint(y8 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x9 - 240), GLint(y9 + 40));
		glVertex2i(GLint(x9 - 240), GLint(y9));
		glVertex2i(GLint(x9 - 60), GLint(y9));
		glVertex2i(GLint(x9 - 60), GLint(y9 + 40));
		glEnd();






		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x3 + 400), GLint(y3 + 40));
		glVertex2i(GLint(x3 + 400), GLint(y3));
		glVertex2i(GLint(x3 + 500), GLint(y3));
		glVertex2i(GLint(x3 + 500), GLint(y3 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x4 + 440), GLint(y4 + 40));
		glVertex2i(GLint(x4 + 440), GLint(y4));
		glVertex2i(GLint(x4 + 520), GLint(y4));
		glVertex2i(GLint(x4 + 520), GLint(y4 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x5 + 330), GLint(y5 + 40));
		glVertex2i(GLint(x5 + 330), GLint(y5));
		glVertex2i(GLint(x5 + 400), GLint(y5));
		glVertex2i(GLint(x5 + 400), GLint(y5 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x7 + 380), GLint(y7 + 40));
		glVertex2i(GLint(x7 + 380), GLint(y7));
		glVertex2i(GLint(x7 + 470), GLint(y7));
		glVertex2i(GLint(x7 + 470), GLint(y7 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x8 + 390), GLint(y8 + 40));
		glVertex2i(GLint(x8 + 390), GLint(y8));
		glVertex2i(GLint(x8 + 530), GLint(y8));
		glVertex2i(GLint(x8 + 530), GLint(y8 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x9 + 360), GLint(y9 + 40));
		glVertex2i(GLint(x9 + 360), GLint(y9));
		glVertex2i(GLint(x9 + 460), GLint(y9));
		glVertex2i(GLint(x9 + 460), GLint(y9 + 40));
		glEnd();






		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x3 - 300), GLint(y3 + 40));
		glVertex2i(GLint(x3 - 300), GLint(y3));
		glVertex2i(GLint(x3 - 400), GLint(y3));
		glVertex2i(GLint(x3 - 400), GLint(y3 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x4 - 270), GLint(y4 + 40));
		glVertex2i(GLint(x4 - 270), GLint(y4));
		glVertex2i(GLint(x4 - 430), GLint(y4));
		glVertex2i(GLint(x4 - 430), GLint(y4 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2i(GLint(x5 - 230), GLint(y5 + 40));
		glVertex2i(GLint(x5 - 230), GLint(y5));
		glVertex2i(GLint(x5 - 300), GLint(y5));
		glVertex2i(GLint(x5 - 300), GLint(y5 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x7 - 280), GLint(y7 + 40));
		glVertex2i(GLint(x7 - 280), GLint(y7));
		glVertex2i(GLint(x7 - 370), GLint(y7));
		glVertex2i(GLint(x7 - 370), GLint(y7 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x8 - 390), GLint(y8 + 40));
		glVertex2i(GLint(x8 - 390), GLint(y8));
		glVertex2i(GLint(x8 - 530), GLint(y8));
		glVertex2i(GLint(x8 - 530), GLint(y8 + 40));
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(x9 - 640), GLint(y9 + 40));
		glVertex2i(GLint(x9 - 640), GLint(y9));
		glVertex2i(GLint(x9 - 760), GLint(y9));
		glVertex2i(GLint(x9 - 760), GLint(y9 + 40));
		glEnd();






		// Desenha um quadrado preenchido com a cor corrente
		glBegin(GL_QUADS);
		glColor3f(0.9f, 0.9f, 0.9f);
		glVertex2i(GLint(x2), GLint(y2 + rsize));
		glVertex2i(GLint(x2), GLint(y2));
		glVertex2i(GLint(x2 + rsize), GLint(y2));
		glVertex2i(GLint(x2 + rsize), GLint(y2 + rsize));
		glEnd();


		// Executa os comandos OpenGL
		glutSwapBuffers();
		y2 = y2 + 1;
		x3 = x3 + 1;
		x4 = x4 + 1;
		x5 = x5 + 1;
		x7 = x7 + 1;
		x8 = x8 + 1;
		x9 = x9 + 1;

		//glutTimerFunc(33, Delay, 1);
		//Delay(30);
		Sleep(timer2);
		glutKeyboardFunc(GerenciaTeclado);
		glutKeyboardUpFunc(GerenciaTeclado);
		//glutTimerFunc(33, Timer, 1);

	}


	for (int i = 0; i < 500; i++) {
		glutKeyboardFunc(GerenciaTeclado);
		glutKeyboardUpFunc(GerenciaTeclado);

		glBegin(GL_QUADS);
		glColor3f(0.9f, 0.9f, 0.9f);
		glVertex2i(GLint(x2 - i), GLint(y2 + rsize + i));
		glVertex2i(GLint(x2 - i), GLint(y2 - i));
		glVertex2i(GLint(x2 + rsize + i), GLint(y2 - i));
		glVertex2i(GLint(x2 + rsize + i), GLint(y2 + rsize + i));
		glEnd();


		// Executa os comandos OpenGL
		glutSwapBuffers();

		Sleep(timer2);
		glutKeyboardFunc(GerenciaTeclado);
	}




	for (int i = 0; i < 500; i++) {

		glutKeyboardFunc(GerenciaTeclado);
		glutKeyboardUpFunc(GerenciaTeclado);

		glLineWidth(5.0f);
		glBegin(GL_LINES);


		glColor3f(1.0f, 0.5f, 0.0f);


		glVertex2i(225, 220);
		glVertex2i(225, 190);

		glVertex2i(275, 220);
		glVertex2i(275, 190);


		glVertex2i(217, 190);
		glVertex2i(233, 190);

		glVertex2i(267, 190);
		glVertex2i(283, 190);




		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(207, 220);
		glVertex2i(292, 220);
		glVertex2i(290, 220);
		glVertex2i(290, 300);
		glVertex2i(292, 300);
		glVertex2i(207, 300);
		glVertex2i(210, 300);
		glVertex2i(210, 220);


		glVertex2i(223, 300);
		glVertex2i(276, 300);
		glVertex2i(223, 350);
		glVertex2i(276, 350);
		glVertex2i(275, 300);
		glVertex2i(275, 350);
		glVertex2i(225, 300);
		glVertex2i(225, 350);



		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2i(237, 324);
		glVertex2i(263, 324);

		glVertex2i(263, 314);
		glVertex2i(237, 314);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.8f, 0.1f, 0.1f);
		glVertex2i(245, 314);
		glVertex2i(255, 314);

		glVertex2i(255, 309);
		glVertex2i(245, 309);
		glEnd();


		glLineWidth(8.0f);

		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);

		glVertex2i(240, 335);
		glVertex2i(240, 327);

		glVertex2i(260, 335);
		glVertex2i(260, 327);

		glColor3f(1.0f, 0.0f, 0.5f);
		glVertex2i(240, 327);
		glVertex2i(240, 325);

		glVertex2i(260, 327);
		glVertex2i(260, 325);



		glColor3f(0.9f, 0.5f, 0.3f);

		glVertex2i(290, 340);
		glVertex2i(310, 360);




		glEnd();





		/*
		glLineWidth(5.0f);
		glBegin(GL_LINES);


		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2i(175, 330);
		glVertex2i(155, 320);
		glVertex2i(155, 320);
		glVertex2i(175, 310);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(197,200);
		glVertex2i(302,200);
		glVertex2i(300,200);
		glVertex2i(300,300);
		glVertex2i(302, 300);
		glVertex2i(197,300);
		glVertex2i(200, 300);
		glVertex2i(200, 200);


		glVertex2i(223, 300);
		glVertex2i(176, 300);
		glVertex2i(223, 350);
		glVertex2i(176, 350);
		glVertex2i(175, 300);
		glVertex2i(175, 350);
		glVertex2i(225, 300);
		glVertex2i(225, 350);

		glVertex2i(185, 340);
		glVertex2i(185, 330);


		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2i(260, 200);
		glVertex2i(260, 170);

		glVertex2i(260, 172);
		glVertex2i(245, 172);

		glEnd();*/

		sprintf(texto, "TO MORTA");
		DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
		// Executa os comandos OpenGL
		glutSwapBuffers();
		Sleep(timer2);
		glutKeyboardFunc(GerenciaTeclado);
		glutKeyboardUpFunc(GerenciaTeclado);
	}



	primitiva = MENU;
}



void DesenhaMenu(void)
{
	//DesenhaTexto("TEXTO TESTE");

	/*escreve(80 , 40 , -110, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Spider Killer");
	escreve(80 , 40 ,-40, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Sair - ESC");
	escreve(80, 40, 30, -50,  GLUT_BITMAP_TIMES_ROMAN_24, "Iniciar - ENTER");
	escreve(80, 40, 100, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Opcoes - O");*/





	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 380.0f);
	glVertex2f(100.0f, 320.0f);
	glVertex2f(400.0f, 320.0f);
	glVertex2f(400.0f, 380.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 280.0f);
	glVertex2f(100.0f, 220.0f);
	glVertex2f(400.0f, 220.0f);
	glVertex2f(400.0f, 280.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 180.0f);
	glVertex2f(100.0f, 120.0f);
	glVertex2f(400.0f, 120.0f);
	glVertex2f(400.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 480.0f);
	glVertex2f(100.0f, 420.0f);
	glVertex2f(400.0f, 420.0f);
	glVertex2f(400.0f, 480.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);
	sprintf(texto, "INICIAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 440);
	sprintf(texto, "OPCOES");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 340);
	sprintf(texto, "CREDITOS");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 240);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 140);


}


void DesenhaMenuPress1(void)
{

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 380.0f);
	glVertex2f(100.0f, 320.0f);
	glVertex2f(400.0f, 320.0f);
	glVertex2f(400.0f, 380.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 280.0f);
	glVertex2f(100.0f, 220.0f);
	glVertex2f(400.0f, 220.0f);
	glVertex2f(400.0f, 280.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 180.0f);
	glVertex2f(100.0f, 120.0f);
	glVertex2f(400.0f, 120.0f);
	glVertex2f(400.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 480.0f);
	glVertex2f(100.0f, 420.0f);
	glVertex2f(400.0f, 420.0f);
	glVertex2f(400.0f, 480.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);
	sprintf(texto, "INICIAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 440);
	sprintf(texto, "OPCOES");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 340);
	sprintf(texto, "CREDITOS");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 240);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 140);


	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 480);
	glVertex2i(110, 430);


	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(100, 420);
	glVertex2i(100, 480);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 430);
	glVertex2i(400, 430);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(400, 420);
	glVertex2i(100, 420);
	glEnd();




}


void DesenhaMenuPress2(void)
{
	//DesenhaTexto("TEXTO TESTE");

	/*escreve(80 , 40 , -110, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Spider Killer");
	escreve(80 , 40 ,-40, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Sair - ESC");
	escreve(80, 40, 30, -50,  GLUT_BITMAP_TIMES_ROMAN_24, "Iniciar - ENTER");
	escreve(80, 40, 100, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Opcoes - O");*/





	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 380.0f);
	glVertex2f(100.0f, 320.0f);
	glVertex2f(400.0f, 320.0f);
	glVertex2f(400.0f, 380.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 280.0f);
	glVertex2f(100.0f, 220.0f);
	glVertex2f(400.0f, 220.0f);
	glVertex2f(400.0f, 280.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 180.0f);
	glVertex2f(100.0f, 120.0f);
	glVertex2f(400.0f, 120.0f);
	glVertex2f(400.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 480.0f);
	glVertex2f(100.0f, 420.0f);
	glVertex2f(400.0f, 420.0f);
	glVertex2f(400.0f, 480.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);
	sprintf(texto, "INICIAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 440);
	sprintf(texto, "OPCOES");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 340);
	sprintf(texto, "CREDITOS");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 240);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 140);



	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 380);
	glVertex2i(110, 330);


	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(100, 320);
	glVertex2i(100, 380);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 330);
	glVertex2i(400, 330);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(400, 320);
	glVertex2i(100, 320);
	glEnd();


}


void DesenhaMenuPress3(void)
{
	//DesenhaTexto("TEXTO TESTE");

	/*escreve(80 , 40 , -110, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Spider Killer");
	escreve(80 , 40 ,-40, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Sair - ESC");
	escreve(80, 40, 30, -50,  GLUT_BITMAP_TIMES_ROMAN_24, "Iniciar - ENTER");
	escreve(80, 40, 100, -50, GLUT_BITMAP_TIMES_ROMAN_24, "Opcoes - O");*/





	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 380.0f);
	glVertex2f(100.0f, 320.0f);
	glVertex2f(400.0f, 320.0f);
	glVertex2f(400.0f, 380.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 280.0f);
	glVertex2f(100.0f, 220.0f);
	glVertex2f(400.0f, 220.0f);
	glVertex2f(400.0f, 280.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 180.0f);
	glVertex2f(100.0f, 120.0f);
	glVertex2f(400.0f, 120.0f);
	glVertex2f(400.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 480.0f);
	glVertex2f(100.0f, 420.0f);
	glVertex2f(400.0f, 420.0f);
	glVertex2f(400.0f, 480.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);
	sprintf(texto, "INICIAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 440);
	sprintf(texto, "OPCOES");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 340);
	sprintf(texto, "CREDITOS");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 240);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 140);


	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 280);
	glVertex2i(110, 230);


	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(100, 220);
	glVertex2i(100, 280);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 230);
	glVertex2i(400, 230);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(400, 220);
	glVertex2i(100, 220);
	glEnd();


}


void DesenhaMenuPress4(void)
{

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 380.0f);
	glVertex2f(100.0f, 320.0f);
	glVertex2f(400.0f, 320.0f);
	glVertex2f(400.0f, 380.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 280.0f);
	glVertex2f(100.0f, 220.0f);
	glVertex2f(400.0f, 220.0f);
	glVertex2f(400.0f, 280.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 180.0f);
	glVertex2f(100.0f, 120.0f);
	glVertex2f(400.0f, 120.0f);
	glVertex2f(400.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 480.0f);
	glVertex2f(100.0f, 420.0f);
	glVertex2f(400.0f, 420.0f);
	glVertex2f(400.0f, 480.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);
	sprintf(texto, "INICIAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 440);
	sprintf(texto, "OPCOES");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 340);
	sprintf(texto, "CREDITOS");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 240);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 140);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 180);
	glVertex2i(110, 130);


	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(100, 120);
	glVertex2i(100, 180);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2i(110, 130);
	glVertex2i(400, 130);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2i(400, 120);
	glVertex2i(100, 120);
	glEnd();


}


/*void InicializaCaminhao() {

c1.setX(0);
c1.setY(55);
c1.setHeight(40);
c1.setWidth(130);

c2.setX(-50);
c2.setY(105);
c2.setHeight(40);
c2.setWidth(100);

c3.setX(-203);
c3.setY(205);
c3.setHeight(40);
c3.setWidth(70);


c4.setX(-500);
c4.setY(55);
c4.setHeight(40);
c4.setWidth(110);

c5.setX(-530);
c5.setY(105);
c5.setHeight(40);
c5.setWidth(60);

c6.setX(-780);
c6.setY(205);
c6.setHeight(40);
c6.setWidth(70);


primitiva = QUADRADO;

}*/

// Função que desenha um quadrado

void DesenhaQuadrado(void)
{


	glClear(GL_COLOR_BUFFER_BIT);

	GLint viewport[4]; //var to hold the viewport info
	GLdouble modelview[16]; //var to hold the modelview info
	GLdouble projection[16]; //var to hold the projection matrix info
	GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
	GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
	glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
	glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

	winX = (float)p1.getX();
	winY = (float)viewport[3] - (float)p1.getY();
	winZ = 0;

	//get the world coordinates from the screen coordinates
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);


	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7f, 0.4f, 0.3f);
	glVertex2i(0, 0);
	glVertex2i(500, 0);
	glVertex2i(500, 50);
	glVertex2i(0, 50);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.4f, 0.3f);
	glVertex2i(0, 450);
	glVertex2i(500, 450);
	glVertex2i(500, 500);
	glVertex2i(0, 500);
	glEnd();



	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.4f, 0.8f);
	glVertex2i(0, 250);
	glVertex2i(500, 250);
	glVertex2i(500, 450);
	glVertex2i(0, 450);
	glEnd();


	glBegin(GL_QUADS);

	glColor3f(0.7f, 0.4f, 0.3f);
	glVertex2i(0, 200);
	glVertex2i(500, 200);
	glVertex2i(500, 250);
	glVertex2i(0, 250);
	glEnd();



	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 0.1f);
	glVertex2i(50, 135);
	glVertex2i(150, 135);
	glVertex2i(150, 115);
	glVertex2i(50, 115);
	glEnd();


	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 0.1f);
	glVertex2i(250, 135);
	glVertex2i(350, 135);
	glVertex2i(350, 115);
	glVertex2i(250, 115);
	glEnd();


	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 0.1f);
	glVertex2i(450, 135);
	glVertex2i(550, 135);
	glVertex2i(550, 115);
	glVertex2i(450, 115);
	glEnd();









	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c1.getX()), GLint(c1.getY() + c1.getHeight()));
	glVertex2i(GLint(c1.getX()), GLint(c1.getY()));
	glVertex2i(GLint(c1.getX() + c1.getWidth()), GLint(c1.getY()));
	glVertex2i(GLint(c1.getX() + c1.getWidth()), GLint(c1.getY() + c1.getHeight()));
	glEnd();

	if (c1.getX() > 500)
	{
		c1.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c2.getX()), GLint(c2.getY() + c2.getHeight()));
	glVertex2i(GLint(c2.getX()), GLint(c2.getY()));
	glVertex2i(GLint(c2.getX() + c2.getWidth()), GLint(c2.getY()));
	glVertex2i(GLint(c2.getX() + c2.getWidth()), GLint(c2.getY() + c2.getHeight()));
	glEnd();
	if (c2.getX() > 500)
	{
		c2.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c3.getX()), GLint(c3.getY() + c3.getHeight()));
	glVertex2i(GLint(c3.getX()), GLint(c3.getY()));
	glVertex2i(GLint(c3.getX() + c3.getWidth()), GLint(c3.getY()));
	glVertex2i(GLint(c3.getX() + c3.getWidth()), GLint(c3.getY() + c3.getHeight()));
	glEnd();
	if (c3.getX() > 500)
	{
		c3.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c4.getX()), GLint(c4.getY() + c4.getHeight()));
	glVertex2i(GLint(c4.getX()), GLint(c4.getY()));
	glVertex2i(GLint(c4.getX() + c4.getWidth()), GLint(c4.getY()));
	glVertex2i(GLint(c4.getX() + c4.getWidth()), GLint(c4.getY() + c4.getHeight()));
	glEnd();
	if (c4.getX() > 500)
	{
		c4.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c5.getX()), GLint(c5.getY() + c5.getHeight()));
	glVertex2i(GLint(c5.getX()), GLint(c5.getY()));
	glVertex2i(GLint(c5.getX() + c5.getWidth()), GLint(c5.getY()));
	glVertex2i(GLint(c5.getX() + c5.getWidth()), GLint(c5.getY() + c5.getHeight()));
	glEnd();
	if (c5.getX() > 500)
	{
		c5.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c6.getX()), GLint(c6.getY() + c6.getHeight()));
	glVertex2i(GLint(c6.getX()), GLint(c6.getY()));
	glVertex2i(GLint(c6.getX() + c6.getWidth()), GLint(c6.getY()));
	glVertex2i(GLint(c6.getX() + c6.getWidth()), GLint(c6.getY() + c6.getHeight()));
	glEnd();
	if (c6.getX() > 500)
	{
		c6.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c7.getX()), GLint(c7.getY() + c7.getHeight()));
	glVertex2i(GLint(c7.getX()), GLint(c7.getY()));
	glVertex2i(GLint(c7.getX() + c7.getWidth()), GLint(c7.getY()));
	glVertex2i(GLint(c7.getX() + c7.getWidth()), GLint(c7.getY() + c7.getHeight()));
	glEnd();
	if (c7.getX() > 500)
	{
		c7.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c8.getX()), GLint(c8.getY() + c8.getHeight()));
	glVertex2i(GLint(c8.getX()), GLint(c8.getY()));
	glVertex2i(GLint(c8.getX() + c8.getWidth()), GLint(c8.getY()));
	glVertex2i(GLint(c8.getX() + c8.getWidth()), GLint(c8.getY() + c8.getHeight()));
	glEnd();
	if (c8.getX() > 500)
	{
		c8.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c9.getX()), GLint(c9.getY() + c9.getHeight()));
	glVertex2i(GLint(c9.getX()), GLint(c9.getY()));
	glVertex2i(GLint(c9.getX() + c9.getWidth()), GLint(c9.getY()));
	glVertex2i(GLint(c9.getX() + c9.getWidth()), GLint(c9.getY() + c9.getHeight()));
	glEnd();
	if (c9.getX() > 500)
	{
		c9.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c10.getX()), GLint(c10.getY() + c10.getHeight()));
	glVertex2i(GLint(c10.getX()), GLint(c10.getY()));
	glVertex2i(GLint(c10.getX() + c10.getWidth()), GLint(c10.getY()));
	glVertex2i(GLint(c10.getX() + c10.getWidth()), GLint(c10.getY() + c10.getHeight()));
	glEnd();
	if (c10.getX() > 500)
	{
		c10.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c11.getX()), GLint(c11.getY() + c11.getHeight()));
	glVertex2i(GLint(c11.getX()), GLint(c11.getY()));
	glVertex2i(GLint(c11.getX() + c11.getWidth()), GLint(c11.getY()));
	glVertex2i(GLint(c11.getX() + c11.getWidth()), GLint(c11.getY() + c11.getHeight()));
	glEnd();
	if (c11.getX() > 500)
	{
		c11.setX(-1650);
	}


	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c12.getX()), GLint(c12.getY() + c12.getHeight()));
	glVertex2i(GLint(c12.getX()), GLint(c12.getY()));
	glVertex2i(GLint(c12.getX() + c12.getWidth()), GLint(c12.getY()));
	glVertex2i(GLint(c12.getX() + c12.getWidth()), GLint(c12.getY() + c12.getHeight()));
	glEnd();
	if (c12.getX() > 500)
	{
		c12.setX(-1650);
	}



	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c13.getX()), GLint(c13.getY() + c13.getHeight()));
	glVertex2i(GLint(c13.getX()), GLint(c13.getY()));
	glVertex2i(GLint(c13.getX() + c13.getWidth()), GLint(c13.getY()));
	glVertex2i(GLint(c13.getX() + c13.getWidth()), GLint(c13.getY() + c13.getHeight()));
	glEnd();

	if (c13.getX() > 500)
	{
		c13.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c14.getX()), GLint(c14.getY() + c14.getHeight()));
	glVertex2i(GLint(c14.getX()), GLint(c14.getY()));
	glVertex2i(GLint(c14.getX() + c14.getWidth()), GLint(c14.getY()));
	glVertex2i(GLint(c14.getX() + c14.getWidth()), GLint(c14.getY() + c14.getHeight()));
	glEnd();
	if (c14.getX() > 500)
	{
		c14.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c15.getX()), GLint(c15.getY() + c15.getHeight()));
	glVertex2i(GLint(c15.getX()), GLint(c15.getY()));
	glVertex2i(GLint(c15.getX() + c15.getWidth()), GLint(c15.getY()));
	glVertex2i(GLint(c15.getX() + c15.getWidth()), GLint(c15.getY() + c15.getHeight()));
	glEnd();
	if (c15.getX() > 500)
	{
		c15.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c16.getX()), GLint(c16.getY() + c16.getHeight()));
	glVertex2i(GLint(c16.getX()), GLint(c16.getY()));
	glVertex2i(GLint(c16.getX() + c16.getWidth()), GLint(c16.getY()));
	glVertex2i(GLint(c16.getX() + c16.getWidth()), GLint(c16.getY() + c16.getHeight()));
	glEnd();
	if (c16.getX() > 500)
	{
		c16.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c17.getX()), GLint(c17.getY() + c17.getHeight()));
	glVertex2i(GLint(c17.getX()), GLint(c17.getY()));
	glVertex2i(GLint(c17.getX() + c17.getWidth()), GLint(c17.getY()));
	glVertex2i(GLint(c17.getX() + c17.getWidth()), GLint(c17.getY() + c17.getHeight()));
	glEnd();
	if (c17.getX() > 500)
	{
		c17.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(c18.getX()), GLint(c18.getY() + c18.getHeight()));
	glVertex2i(GLint(c18.getX()), GLint(c18.getY()));
	glVertex2i(GLint(c18.getX() + c18.getWidth()), GLint(c18.getY()));
	glVertex2i(GLint(c18.getX() + c18.getWidth()), GLint(c18.getY() + c18.getHeight()));
	glEnd();
	if (c18.getX() > 500)
	{
		c18.setX(-1650);
	}





	c1.colideTeste(p1);
	c2.colideTeste(p1);
	c3.colideTeste(p1);
	c4.colideTeste(p1);
	c5.colideTeste(p1);
	c6.colideTeste(p1);
	c7.colideTeste(p1);
	c8.colideTeste(p1);
	c9.colideTeste(p1);
	c10.colideTeste(p1);
	c11.colideTeste(p1);
	c12.colideTeste(p1);
	c13.colideTeste(p1);
	c14.colideTeste(p1);
	c15.colideTeste(p1);
	c16.colideTeste(p1);
	c17.colideTeste(p1);
	c18.colideTeste(p1);


	if (c1.getColide() == 1) {
		p1.setX(250); p1.setY(10); c1.setColide(0); 			p1.setLife(p1.getLife() - 1);
	}
	if (c2.getColide() == 1) {
		p1.setX(250); p1.setY(10); c2.setColide(0); 			p1.setLife(p1.getLife() - 1);
	}
	if (c3.getColide() == 1) {
		p1.setX(250); p1.setY(10); c3.setColide(0); 			p1.setLife(p1.getLife() - 1);
	}
	if (c4.getColide() == 1) {
		p1.setX(250); p1.setY(10); c4.setColide(0); 			p1.setLife(p1.getLife() - 1);
	}
	if (c5.getColide() == 1) {
		p1.setX(250); p1.setY(10); c5.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c6.getColide() == 1) {
		p1.setX(250); p1.setY(10); c6.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c7.getColide() == 1) {
		p1.setX(250); p1.setY(10); c7.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c8.getColide() == 1) {
		p1.setX(250); p1.setY(10); c8.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c9.getColide() == 1) {
		p1.setX(250); p1.setY(10); c9.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c10.getColide() == 1) {
		p1.setX(250); p1.setY(10); c10.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c11.getColide() == 1) {
		p1.setX(250); p1.setY(10); c11.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c12.getColide() == 1) {
		p1.setX(250); p1.setY(10); c12.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c13.getColide() == 1) {
		p1.setX(250); p1.setY(10); c13.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c14.getColide() == 1) {
		p1.setX(250); p1.setY(10); c14.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c15.getColide() == 1) {
		p1.setX(250); p1.setY(10); c15.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c16.getColide() == 1) {
		p1.setX(250); p1.setY(10); c16.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c17.getColide() == 1) {
		p1.setX(250); p1.setY(10); c17.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	if (c18.getColide() == 1) {
		p1.setX(250); p1.setY(10); c18.setColide(0);			p1.setLife(p1.getLife() - 1);
	}
	//glutTimerFunc(33,Timer,1);











	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m1.getX()), GLint(m1.getY() + m1.getHeight()));
	glVertex2i(GLint(m1.getX()), GLint(m1.getY()));
	glVertex2i(GLint(m1.getX() + m1.getWidth()), GLint(m1.getY()));
	glVertex2i(GLint(m1.getX() + m1.getWidth()), GLint(m1.getY() + m1.getHeight()));
	glEnd();

	if (m1.getX() > 500)
	{
		m1.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m2.getX()), GLint(m2.getY() + m2.getHeight()));
	glVertex2i(GLint(m2.getX()), GLint(m2.getY()));
	glVertex2i(GLint(m2.getX() + m2.getWidth()), GLint(m2.getY()));
	glVertex2i(GLint(m2.getX() + m2.getWidth()), GLint(m2.getY() + m2.getHeight()));
	glEnd();
	if (m2.getX() > 500)
	{
		m2.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m3.getX()), GLint(m3.getY() + m3.getHeight()));
	glVertex2i(GLint(m3.getX()), GLint(m3.getY()));
	glVertex2i(GLint(m3.getX() + m3.getWidth()), GLint(m3.getY()));
	glVertex2i(GLint(m3.getX() + m3.getWidth()), GLint(m3.getY() + m3.getHeight()));
	glEnd();
	if (m3.getX() > 500)
	{
		m3.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m4.getX()), GLint(m4.getY() + m4.getHeight()));
	glVertex2i(GLint(m4.getX()), GLint(m4.getY()));
	glVertex2i(GLint(m4.getX() + m4.getWidth()), GLint(m4.getY()));
	glVertex2i(GLint(m4.getX() + m4.getWidth()), GLint(m4.getY() + m4.getHeight()));
	glEnd();
	if (m4.getX() > 500)
	{
		m4.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m5.getX()), GLint(m5.getY() + m5.getHeight()));
	glVertex2i(GLint(m5.getX()), GLint(m5.getY()));
	glVertex2i(GLint(m5.getX() + m5.getWidth()), GLint(m5.getY()));
	glVertex2i(GLint(m5.getX() + m5.getWidth()), GLint(m5.getY() + m5.getHeight()));
	glEnd();
	if (m5.getX() > 500)
	{
		m5.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m6.getX()), GLint(m6.getY() + m6.getHeight()));
	glVertex2i(GLint(m6.getX()), GLint(m6.getY()));
	glVertex2i(GLint(m6.getX() + m6.getWidth()), GLint(m6.getY()));
	glVertex2i(GLint(m6.getX() + m6.getWidth()), GLint(m6.getY() + m6.getHeight()));
	glEnd();
	if (m6.getX() > 500)
	{
		m6.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m7.getX()), GLint(m7.getY() + m7.getHeight()));
	glVertex2i(GLint(m7.getX()), GLint(m7.getY()));
	glVertex2i(GLint(m7.getX() + m7.getWidth()), GLint(m7.getY()));
	glVertex2i(GLint(m7.getX() + m7.getWidth()), GLint(m7.getY() + m7.getHeight()));
	glEnd();
	if (m7.getX() > 500)
	{
		m7.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m8.getX()), GLint(m8.getY() + m8.getHeight()));
	glVertex2i(GLint(m8.getX()), GLint(m8.getY()));
	glVertex2i(GLint(m8.getX() + m8.getWidth()), GLint(m8.getY()));
	glVertex2i(GLint(m8.getX() + m8.getWidth()), GLint(m8.getY() + m8.getHeight()));
	glEnd();
	if (m8.getX() > 500)
	{
		m8.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m9.getX()), GLint(m9.getY() + m9.getHeight()));
	glVertex2i(GLint(m9.getX()), GLint(m9.getY()));
	glVertex2i(GLint(m9.getX() + m9.getWidth()), GLint(m9.getY()));
	glVertex2i(GLint(m9.getX() + m9.getWidth()), GLint(m9.getY() + m9.getHeight()));
	glEnd();
	if (m9.getX() > 500)
	{
		m9.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m10.getX()), GLint(m10.getY() + m10.getHeight()));
	glVertex2i(GLint(m10.getX()), GLint(m10.getY()));
	glVertex2i(GLint(m10.getX() + m10.getWidth()), GLint(m10.getY()));
	glVertex2i(GLint(m10.getX() + m10.getWidth()), GLint(m10.getY() + m10.getHeight()));
	glEnd();
	if (m10.getX() > 500)
	{
		m10.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m11.getX()), GLint(m11.getY() + m11.getHeight()));
	glVertex2i(GLint(m11.getX()), GLint(m11.getY()));
	glVertex2i(GLint(m11.getX() + m11.getWidth()), GLint(m11.getY()));
	glVertex2i(GLint(m11.getX() + m11.getWidth()), GLint(m11.getY() + m11.getHeight()));
	glEnd();
	if (m11.getX() > 500)
	{
		m11.setX(-1650);
	}


	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m12.getX()), GLint(m12.getY() + m12.getHeight()));
	glVertex2i(GLint(m12.getX()), GLint(m12.getY()));
	glVertex2i(GLint(m12.getX() + m12.getWidth()), GLint(m12.getY()));
	glVertex2i(GLint(m12.getX() + m12.getWidth()), GLint(m12.getY() + m12.getHeight()));
	glEnd();
	if (m12.getX() > 500)
	{
		m12.setX(-1650);
	}



	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m13.getX()), GLint(m13.getY() + m13.getHeight()));
	glVertex2i(GLint(m13.getX()), GLint(m13.getY()));
	glVertex2i(GLint(m13.getX() + m13.getWidth()), GLint(m13.getY()));
	glVertex2i(GLint(m13.getX() + m13.getWidth()), GLint(m13.getY() + m13.getHeight()));
	glEnd();

	if (m13.getX() > 500)
	{
		m13.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m14.getX()), GLint(m14.getY() + m14.getHeight()));
	glVertex2i(GLint(m14.getX()), GLint(m14.getY()));
	glVertex2i(GLint(m14.getX() + m14.getWidth()), GLint(m14.getY()));
	glVertex2i(GLint(m14.getX() + m14.getWidth()), GLint(m14.getY() + m14.getHeight()));
	glEnd();
	if (m14.getX() > 500)
	{
		m14.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m15.getX()), GLint(m15.getY() + m15.getHeight()));
	glVertex2i(GLint(m15.getX()), GLint(m15.getY()));
	glVertex2i(GLint(m15.getX() + m15.getWidth()), GLint(m15.getY()));
	glVertex2i(GLint(m15.getX() + m15.getWidth()), GLint(m15.getY() + m15.getHeight()));
	glEnd();
	if (m15.getX() > 500)
	{
		m15.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m16.getX()), GLint(m16.getY() + m16.getHeight()));
	glVertex2i(GLint(m16.getX()), GLint(m16.getY()));
	glVertex2i(GLint(m16.getX() + m16.getWidth()), GLint(m16.getY()));
	glVertex2i(GLint(m16.getX() + m16.getWidth()), GLint(m16.getY() + m16.getHeight()));
	glEnd();
	if (m16.getX() > 500)
	{
		m16.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m17.getX()), GLint(m17.getY() + m17.getHeight()));
	glVertex2i(GLint(m17.getX()), GLint(m17.getY()));
	glVertex2i(GLint(m17.getX() + m17.getWidth()), GLint(m17.getY()));
	glVertex2i(GLint(m17.getX() + m17.getWidth()), GLint(m17.getY() + m17.getHeight()));
	glEnd();
	if (m17.getX() > 500)
	{
		m17.setX(-1650);
	}

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2i(GLint(m18.getX()), GLint(m18.getY() + m18.getHeight()));
	glVertex2i(GLint(m18.getX()), GLint(m18.getY()));
	glVertex2i(GLint(m18.getX() + m18.getWidth()), GLint(m18.getY()));
	glVertex2i(GLint(m18.getX() + m18.getWidth()), GLint(m18.getY() + m18.getHeight()));
	glEnd();
	if (m18.getX() > 500)
	{
		m18.setX(-1650);
	}






	if (p1.getY() > 255 && p1.getY() < 450)
	{
		m1.colideTeste(p1);
		m2.colideTeste(p1);
		m3.colideTeste(p1);
		m4.colideTeste(p1);
		m5.colideTeste(p1);
		m6.colideTeste(p1);
		m7.colideTeste(p1);
		m8.colideTeste(p1);
		m9.colideTeste(p1);
		m10.colideTeste(p1);
		m11.colideTeste(p1);
		m12.colideTeste(p1);
		m13.colideTeste(p1);
		m14.colideTeste(p1);
		m15.colideTeste(p1);
		m16.colideTeste(p1);
		m17.colideTeste(p1);
		m18.colideTeste(p1);


		if (m1.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m1.setColide(0); 			p1.setLife(p1.getLife() - 1);
		}
		else if (m2.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m2.setColide(0); 			p1.setLife(p1.getLife() - 1);
		}
		else if (m3.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m3.setColide(0); 			p1.setLife(p1.getLife() - 1);
		}
		else if (m4.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m4.setColide(0); 			p1.setLife(p1.getLife() - 1);
		}
		else if (m5.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m5.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m6.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m6.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m7.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m7.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m8.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m8.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m9.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m9.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m10.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m10.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m11.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m11.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m12.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m12.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m13.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m13.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m14.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m14.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m15.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m15.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m16.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m16.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m17.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m17.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else if (m18.getColide() == 1) {
			//p1.setX(250); p1.setY(10); m18.setColide(0);			p1.setLife(p1.getLife() - 1);
		}
		else
		{
			p1.setX(250); p1.setY(10); 			p1.setLife(p1.getLife() - 1);

			m1.setColide(0);
			m2.setColide(0);
			m3.setColide(0);
			m4.setColide(0);
			m5.setColide(0);
			m6.setColide(0);
			m7.setColide(0);
			m8.setColide(0);
			m9.setColide(0);
			m10.setColide(0);
			m11.setColide(0);
			m12.setColide(0);
			m13.setColide(0);
			m14.setColide(0);
			m15.setColide(0);
			m16.setColide(0);
			m17.setColide(0);
			m18.setColide(0);

		}
	}











	if (p1.getLife() == 0)
	{


		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glutKeyboardFunc(GerenciaTeclado);
		glutKeyboardUpFunc(GerenciaTeclado);

		glLineWidth(5.0f);
		glBegin(GL_LINES);


		glColor3f(1.0f, 0.5f, 0.0f);


		glVertex2i(225, 220);
		glVertex2i(225, 190);

		glVertex2i(275, 220);
		glVertex2i(275, 190);


		glVertex2i(217, 190);
		glVertex2i(233, 190);

		glVertex2i(267, 190);
		glVertex2i(283, 190);




		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(207, 220);
		glVertex2i(292, 220);
		glVertex2i(290, 220);
		glVertex2i(290, 300);
		glVertex2i(292, 300);
		glVertex2i(207, 300);
		glVertex2i(210, 300);
		glVertex2i(210, 220);


		glVertex2i(223, 300);
		glVertex2i(276, 300);
		glVertex2i(223, 350);
		glVertex2i(276, 350);
		glVertex2i(275, 300);
		glVertex2i(275, 350);
		glVertex2i(225, 300);
		glVertex2i(225, 350);



		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2i(237, 324);
		glVertex2i(263, 324);

		glVertex2i(263, 314);
		glVertex2i(237, 314);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.8f, 0.1f, 0.1f);
		glVertex2i(245, 314);
		glVertex2i(255, 314);

		glVertex2i(255, 309);
		glVertex2i(245, 309);
		glEnd();


		glLineWidth(8.0f);

		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);

		glVertex2i(240, 335);
		glVertex2i(240, 327);

		glVertex2i(260, 335);
		glVertex2i(260, 327);

		glColor3f(1.0f, 0.0f, 0.5f);
		glVertex2i(240, 327);
		glVertex2i(240, 325);

		glVertex2i(260, 327);
		glVertex2i(260, 325);



		glColor3f(0.9f, 0.5f, 0.3f);

		glVertex2i(290, 340);
		glVertex2i(310, 360);




		glEnd();





		/*
		glLineWidth(5.0f);
		glBegin(GL_LINES);


		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2i(175, 330);
		glVertex2i(155, 320);
		glVertex2i(155, 320);
		glVertex2i(175, 310);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(197,200);
		glVertex2i(302,200);
		glVertex2i(300,200);
		glVertex2i(300,300);
		glVertex2i(302, 300);
		glVertex2i(197,300);
		glVertex2i(200, 300);
		glVertex2i(200, 200);


		glVertex2i(223, 300);
		glVertex2i(176, 300);
		glVertex2i(223, 350);
		glVertex2i(176, 350);
		glVertex2i(175, 300);
		glVertex2i(175, 350);
		glVertex2i(225, 300);
		glVertex2i(225, 350);

		glVertex2i(185, 340);
		glVertex2i(185, 330);


		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2i(260, 200);
		glVertex2i(260, 170);

		glVertex2i(260, 172);
		glVertex2i(245, 172);

		glEnd();*/

		sprintf(texto, "TO MORTA");
		DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
		// Executa os comandos OpenGL
		glutSwapBuffers();
		glutPostRedisplay();
		Sleep(timer2 * 1000);
		p1.setLife(5);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		primitiva = MENU;
	}

	if (p1.getLife() == 1)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(450, 470);
		glVertex2i(450, 490);
		glVertex2i(470, 490);
		glVertex2i(470, 470);
		glEnd();

	}
	if (p1.getLife() == 2)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(450, 470);
		glVertex2i(450, 490);
		glVertex2i(470, 490);
		glVertex2i(470, 470);
		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(410, 470);
		glVertex2i(410, 490);
		glVertex2i(430, 490);
		glVertex2i(430, 470);
		glEnd();
	}
	if (p1.getLife() == 3)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(450, 470);
		glVertex2i(450, 490);
		glVertex2i(470, 490);
		glVertex2i(470, 470);
		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(410, 470);
		glVertex2i(410, 490);
		glVertex2i(430, 490);
		glVertex2i(430, 470);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(370, 470);
		glVertex2i(370, 490);
		glVertex2i(390, 490);
		glVertex2i(390, 470);
		glEnd();

	}
	if (p1.getLife() == 4)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(450, 470);
		glVertex2i(450, 490);
		glVertex2i(470, 490);
		glVertex2i(470, 470);
		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(410, 470);
		glVertex2i(410, 490);
		glVertex2i(430, 490);
		glVertex2i(430, 470);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(370, 470);
		glVertex2i(370, 490);
		glVertex2i(390, 490);
		glVertex2i(390, 470);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(330, 470);
		glVertex2i(330, 490);
		glVertex2i(350, 490);
		glVertex2i(350, 470);
		glEnd();
	}
	if (p1.getLife() == 5)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(450, 470);
		glVertex2i(450, 490);
		glVertex2i(470, 490);
		glVertex2i(470, 470);
		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(410, 470);
		glVertex2i(410, 490);
		glVertex2i(430, 490);
		glVertex2i(430, 470);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(370, 470);
		glVertex2i(370, 490);
		glVertex2i(390, 490);
		glVertex2i(390, 470);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(330, 470);
		glVertex2i(330, 490);
		glVertex2i(350, 490);
		glVertex2i(350, 470);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(290, 470);
		glVertex2i(290, 490);
		glVertex2i(310, 490);
		glVertex2i(310, 470);
		glEnd();


	}


	//Caminhao c1;



	/*	if (worldY <= 275)
	{
	if (p1.getX <= )
	p1.getX
	}*/
	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(GLint(p1.getX()), GLint(p1.getY() + p1.getHeight()));
	glVertex2i(GLint(p1.getX()), GLint(p1.getY()));
	glVertex2i(GLint(p1.getX() + p1.getWidth()), GLint(p1.getY()));
	glVertex2i(GLint(p1.getX() + p1.getWidth()), GLint(p1.getY() + p1.getHeight()));
	glEnd();


	glutPostRedisplay();

}



// Função que desenha um triângulo
void DesenhaTriangulo(void)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f, 200.0f);
	glVertex2f(200.0f, 300.0f);
	glVertex2f(300.0f, 300.0f);
	glEnd();
}

// Função que desenha um losango
void DesenhaLosango(void)
{
	glBegin(GL_POLYGON);
	glVertex2f(200.0f, 250.0f);
	glVertex2f(250.0f, 300.0f);
	glVertex2f(300.0f, 250.0f);
	glVertex2f(250.0f, 200.0f);
	glEnd();
}

void sair() { exit(0); }





// Desenha um texto na janela GLUT
void DesenhaTexto(char *string, void *font, GLfloat xAux, GLfloat yAux)
{
	glPushMatrix();
	// Posição no universo onde o texto será colocado          
	glRasterPos2f(xAux, yAux);

	//glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(font, *string++);
	glPopMatrix();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor corrente
	glColor3f(r, g, b);

	// Desenha uma primitiva     
	switch (primitiva) {

	case ANIMACAO: DesenhaAnimacao();
		break;
	case MENU: DesenhaMenu();
		break;
		//case LERARQUIVO:  InicializaCaminhao();
		//	break;
	case QUADRADO:  DesenhaQuadrado();
		break;
	case TRIANGULO: DesenhaTriangulo();
		break;
	case LOSANGO:   DesenhaLosango();
		break;
	case SAIR: sair();
		break;
	case MENUPRESS1: DesenhaMenuPress1();
		break;
	case MENUPRESS2: DesenhaMenuPress2();
		break;
	case MENUPRESS3: DesenhaMenuPress3();
		break;
	case MENUPRESS4: DesenhaMenuPress4();
		break;


	}

	// Exibe a posição do mouse na janela
	//glutPassiveMotionFunc(MoveMouse);
	//glutMotionFunc(MoveMouseBotaoPressionado);
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_10, 10, 460);
	glutPostRedisplay();
	glutSwapBuffers();

}


int countlines(char *filename)
{

	FILE *file = fopen("teste.txt", "r");
	int integers[100];

	int i = 0;
	int ch = 0;
	while (!feof(file))
	{
		ch = fgetc(file);
		if (ch == '\n')
		{
			i++;
		}
	}
	fclose(file);

	return i;
}


void teste()
{

	FILE *myFile;
	myFile = fopen("teste.txt", "r");
	int cnt = countlines("teste.txt");

	//read file into array
	int numberArray[16];
	int i;

	if (myFile == NULL)
	{
		printf("Error Reading File\n");
	}


	for(i = 0; i < 5; i++){
		for (j = 0; j < cnt; j++)
		{
			fscanf(myFile, "%d,", &numberArray[i]);

		}
	}

	for (i = 0; i < 16; i++)
	{
		printf("Number is: %d\n\n", numberArray[i]);
	}



	printf("Linhas %d", cnt);
	

	fclose(myFile);

}




// Inicializa parâmetros de rendering
void Inicializa(void)
{
	teste();
	c1.setX(0);
	c1.setY(55);
	c1.setHeight(40);
	c1.setWidth(130);

	c2.setX(-50);
	c2.setY(105);
	c2.setHeight(40);
	c2.setWidth(100);

	c3.setX(-203);
	c3.setY(155);
	c3.setHeight(40);
	c3.setWidth(70);


	c4.setX(-500);
	c4.setY(55);
	c4.setHeight(40);
	c4.setWidth(110);

	c5.setX(-530);
	c5.setY(105);
	c5.setHeight(40);
	c5.setWidth(60);

	c6.setX(-780);
	c6.setY(155);
	c6.setHeight(40);
	c6.setWidth(70);

	c7.setX(-700);
	c7.setY(55);
	c7.setHeight(40);
	c7.setWidth(100);

	c8.setX(-900);
	c8.setY(105);
	c8.setHeight(40);
	c8.setWidth(160);

	c9.setX(-930);
	c9.setY(155);
	c9.setHeight(40);
	c9.setWidth(50);


	c10.setX(-1200);
	c10.setY(55);
	c10.setHeight(40);
	c10.setWidth(110);

	c11.setX(-1350);
	c11.setY(105);
	c11.setHeight(40);
	c11.setWidth(60);

	c12.setX(-1350);
	c12.setY(155);
	c12.setHeight(40);
	c12.setWidth(160);

	c13.setX(-1600);
	c13.setY(55);
	c13.setHeight(40);
	c13.setWidth(130);

	c14.setX(-1650);
	c14.setY(105);
	c14.setHeight(40);
	c14.setWidth(100);

	c15.setX(-1705);
	c15.setY(155);
	c15.setHeight(40);
	c15.setWidth(70);


	c16.setX(-1700);
	c16.setY(55);
	c16.setHeight(40);
	c16.setWidth(110);

	c17.setX(-1830);
	c17.setY(105);
	c17.setHeight(40);
	c17.setWidth(60);

	c18.setX(-1880);
	c18.setY(155);
	c18.setHeight(40);
	c18.setWidth(70);


	m1.setX(0);
	m1.setY(255);
	m1.setHeight(40);
	m1.setWidth(130);

	m2.setX(-50);
	m2.setY(305);
	m2.setHeight(40);
	m2.setWidth(100);

	m3.setX(-203);
	m3.setY(355);
	m3.setHeight(40);
	m3.setWidth(70);


	m4.setX(-500);
	m4.setY(255);
	m4.setHeight(40);
	m4.setWidth(110);

	m5.setX(-530);
	m5.setY(305);
	m5.setHeight(40);
	m5.setWidth(60);

	m6.setX(-780);
	m6.setY(355);
	m6.setHeight(40);
	m6.setWidth(70);

	m7.setX(-700);
	m7.setY(255);
	m7.setHeight(40);
	m7.setWidth(100);

	m8.setX(-900);
	m8.setY(305);
	m8.setHeight(40);
	m8.setWidth(160);

	m9.setX(-930);
	m9.setY(355);
	m9.setHeight(40);
	m9.setWidth(50);


	m10.setX(-1200);
	m10.setY(255);
	m10.setHeight(40);
	m10.setWidth(110);

	m11.setX(-1350);
	m11.setY(305);
	m11.setHeight(40);
	m11.setWidth(60);

	m12.setX(-1350);
	m12.setY(355);
	m12.setHeight(40);
	m12.setWidth(160);

	m13.setX(-1600);
	m13.setY(255);
	m13.setHeight(40);
	m13.setWidth(130);

	m14.setX(-1650);
	m14.setY(305);
	m14.setHeight(40);
	m14.setWidth(100);

	m15.setX(-1705);
	m15.setY(355);
	m15.setHeight(40);
	m15.setWidth(70);


	m16.setX(-1700);
	m16.setY(255);
	m16.setHeight(40);
	m16.setWidth(110);

	m17.setX(-1830);
	m17.setY(305);
	m17.setHeight(40);
	m17.setWidth(60);

	m18.setX(-1880);
	m18.setY(355);
	m18.setHeight(40);
	m18.setWidth(70);














	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	win = 150.0f;
	primitiva = ANIMACAO;
	r = 0.0f;
	g = 0.0f;
	b = 1.0f;
	strcpy(texto, "(0,0)");
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Especifica as dimensões da Viewport
	// Evita a divisao por zero
	if (h == 0) h = 1;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
		gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f*h / w);
	else
		gluOrtho2D(0.0f, 500.0f*w / h, 0.0f, 500.0f);
}

// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT com um botão pressionado
void MoveMouseBotaoPressionado(int x, int y)
{
	//int vet[3];

	//mouseClick(x, y);

	glColor3f(1.0f, 1.0f, 1.0f);

	GLint viewport[4]; //var to hold the viewport info
	GLdouble modelview[16]; //var to hold the modelview info
	GLdouble projection[16]; //var to hold the projection matrix info
	GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
	GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
	glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
	glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	winZ = 0;

	//get the world coordinates from the screen coordinates
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

	//mouseClick(x, y);



	if (primitiva == MENU || primitiva == MENUPRESS1 || primitiva == MENUPRESS2 || primitiva == MENUPRESS3 || primitiva == MENUPRESS4)
	{
		if (ClickON == 1)
		{
			if (worldX > 100 && worldX < 400) {

				if (worldY > 420 && worldY < 480)
				{
					primitiva = MENUPRESS1;
				}
				else if (worldY > 320 && worldY < 380)
				{
					primitiva = MENUPRESS2;
				}
				else if (worldY > 220 && worldY < 280)
				{
					primitiva = MENUPRESS3;
				}
				else if (worldY > 120 && worldY < 180)
				{
					primitiva = MENUPRESS4;
				}
				else { primitiva = MENU; }
			}
			else { primitiva = MENU; }
		}

		if (ClickON == 0)
		{
			primitiva = MENU;
		}
	}






	//sprintf(texto, "Botao pressionado (%d,%d)", x, y);


	sprintf(texto, "Botao pressionado (%d,%d)", x, y);


	glutPostRedisplay();
}

// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT 
void MoveMouse(int x, int y)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	sprintf(texto, "(%d,%d)", x, y);
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_10, 10, 460);
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{


	if (key == GLUT_KEY_UP) {
		p1.setY(p1.getY() + 50);
		if (p1.getY() >470)
		{
			p1.setY(470);
		}

	}
	if (key == GLUT_KEY_DOWN) {
		p1.setY(p1.getY() - 50);
		if (p1.getY() <0) p1.setY(0);
	}

	if (key == GLUT_KEY_LEFT) {
		p1.setX(p1.getX() - 50);
		if (p1.getX() < 0) p1.setX(0);
	}
	if (key == GLUT_KEY_RIGHT) {
		p1.setX(p1.getX() + 50);
		if (p1.getX() >470) p1.setX(470);
	}

	glutPostRedisplay();
}

// Gerenciamento do menu com as opções de cores           
void MenuCor(int op)
{
	switch (op) {
	case 0:
		r = 1.0f;
		g = 0.0f;
		b = 0.0f;
		break;
	case 1:
		r = 0.0f;
		g = 1.0f;
		b = 0.0f;
		break;
	case 2:
		r = 0.0f;
		g = 0.0f;
		b = 1.0f;
		break;

	}
	glutPostRedisplay();
}

// Gerenciamento do menu com as opções de cores           
void MenuPrimitiva(int op)
{
	switch (op) {
	case 0:
		primitiva = QUADRADO;
		break;
	case 1:
		primitiva = TRIANGULO;
		break;
	case 2:
		primitiva = LOSANGO;
		break;
	case 3:
		primitiva = MENU;
		break;
	case 4:
		primitiva = ANIMACAO;
		break;
	}
	glutPostRedisplay();
}

// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
}

// Criacao do Menu
void CriaMenu()
{
	int menu, submenu1, submenu2;

	submenu1 = glutCreateMenu(MenuCor);
	glutAddMenuEntry("Vermelho", 0);
	glutAddMenuEntry("Verde", 1);
	glutAddMenuEntry("Azul", 2);


	submenu2 = glutCreateMenu(MenuPrimitiva);
	glutAddMenuEntry("Quadrado", 0);
	glutAddMenuEntry("Triângulo", 1);
	glutAddMenuEntry("Losango", 2);
	glutAddMenuEntry("Menu", 3);

	menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Cor", submenu1);
	glutAddSubMenu("Primitivas", submenu2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}





// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	GLint viewport[4]; //var to hold the viewport info
	GLdouble modelview[16]; //var to hold the modelview info
	GLdouble projection[16]; //var to hold the projection matrix info
	GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
	GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
	glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
	glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	winZ = 0;

	//get the world coordinates from the screen coordinates
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

	//mouseClick(x, y);


	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN) { ClickON = 1; }
	}
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP) { ClickON = 0; }
	}




	//sprintf(texto, "Botao pressionado (%d,%d)", x, y);


	if (primitiva == MENU || primitiva == MENUPRESS1 || primitiva == MENUPRESS2 || primitiva == MENUPRESS3 || primitiva == MENUPRESS4)
	{
		if (ClickON == 1)
		{
			if (worldX > 100 && worldX < 400) {

				if (worldY > 420 && worldY < 480)
				{
					primitiva = MENUPRESS1;
				}
				if (worldY > 320 && worldY < 380)
				{
					primitiva = MENUPRESS2;
				}
				if (worldY > 220 && worldY < 280)
				{
					primitiva = MENUPRESS3;
				}
				if (worldY > 120 && worldY < 180)
				{
					primitiva = MENUPRESS4;
				}

			}
			else { primitiva = MENU; }

		}

		if (ClickON == 0)
		{
			primitiva = MENU;
		}
	}

	if (primitiva == MENU)
	{
		if (button == GLUT_LEFT_BUTTON)
		{



			if (state == GLUT_UP)
			{
				if (worldX > 100 && worldX < 400) {

					if (worldY > 420 && worldY < 480)
					{
						primitiva = QUADRADO;
						//DesenhaQuadrado();
					}
					if (worldY > 320 && worldY < 380)
					{
						primitiva = LOSANGO;

						//DesenhaLosango();

					}
					if (worldY > 220 && worldY < 280)
					{
						primitiva = TRIANGULO;
					}
					if (worldY > 120 && worldY < 180)
					{
						primitiva = SAIR;
					}
				}
			}
		}

	}



	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN)
			CriaMenu();
	glutPostRedisplay();
}

// Programa Principal 
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Exemplo de Menu e Exibição de Caracteres");

	//glutIdleFunc(idle);
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);


	glutMotionFunc(MoveMouseBotaoPressionado);
	glutPassiveMotionFunc(MoveMouse);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(GerenciaTeclado);
	glutTimerFunc(17, Timer, 1);
	Inicializa();
	glutMainLoop();
}