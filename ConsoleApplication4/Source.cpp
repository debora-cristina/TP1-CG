#include <GL/glut.h>
#include <gl/glut.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Personagem.h"
#include "Caminhao.h"
#include "Madeira.h"
#include <vector>

using namespace std;

GLint FPS = 0;
//const int TIMERMSECS = 20;
//float animation_time = 0;
//const float  animation_step = .5;

Personagem p1;


GLint ClickON = 0;
GLint break1 = 0;
GLfloat timer2 = 3.3;

// Tamanho e posição inicial do FASE1
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
#define FASE1 1
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
#define GALINHA 12
#define FASE2 13
#define FASE3 14
#define FASE4 15
#define FASE5 16
#define VITORIA 17

char* estado;
enum GameStates { OPTIONS,PLAYING, WIN, GAMEOVER, WINGAME };
GameStates gameState = GameStates::OPTIONS;
int fase = 1;
char* nomeFase;





// Variáveis
char texto[30];
GLfloat win, r, g, b;
GLint view_w, view_h, primitiva;


void Desenha(void);
void DesenhaTexto(char *string, void *font, GLfloat xAux, GLfloat yAux);
void MoveMouse(int x, int y);
void MoveMouseBotaoPressionado(int x, int y);
/*void InicializaFase1(void);
void InicializaFase2(void);
void InicializaFase3(void);
void InicializaFase4(void);
void InicializaFase5(void);
*/

vector<Caminhao> caminhoes;
vector<Madeira> madeiras;


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

	if (primitiva == FASE1 || primitiva == FASE2 || primitiva == FASE3 || primitiva == FASE4 || primitiva == FASE5) {
		switch (c) {

		case 119:
			p1.setY(p1.getY() + 50);
			if (p1.getY() > 470)
			{
				p1.setY(470);
			}
			break;
		case 115:
			p1.setY(p1.getY() - 50);
			if (p1.getY() <0) p1.setY(10);
			break;
		case 97:
			p1.setX(p1.getX() - 50);
			if (p1.getX() < 0) p1.setX(10);
			break;
		case 100:
			p1.setX(p1.getX() + 50);
			if (p1.getX() >470) p1.setX(470);

			break;



		}
	}


	


	glutPostRedisplay();
}



void DesenhaGalinha() {


	p1.setLife(5);


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





	sprintf(texto, "TO MORTA");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
	// Executa os comandos OpenGL
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(timer2 * 1000);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	primitiva = MENU;

}
void DesenhaVitoria() {


	p1.setLife(5);


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


	sprintf(texto, "TÔ VIVA!!");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
	// Executa os comandos OpenGL
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(timer2 * 1000);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	primitiva = MENU;

}
void InicializaPersonagem()
{
	p1.setX(250);
	p1.setY(10);
}


void Timer(int value)
{

	for (int i = 0; i < caminhoes.size(); i++) {
		caminhoes[i].setX(caminhoes[i].getX() + caminhoes[i].getVelocidade());
	}

	for (int i = 0; i < madeiras.size(); i++) {
		madeiras[i].setX(madeiras[i].getX() + madeiras[i].getVelocidade());
	}

	if (p1.getY()>250 && p1.getY()<300)
	{

		if (p1.getColide() == 0)
		{
			p1.setX(p1.getX() + 0.5);
		}

	}
	if (p1.getY() > 300 && p1.getY() < 350) {
		if (p1.getColide() == 0)
		{
			p1.setX(p1.getX() + 0.8);
		}

	}

	if (p1.getY() > 350 && p1.getY() < 400)
	{
		if (p1.getColide() == 0)
		{
			p1.setX(p1.getX() + 0.6);
		}
	}

	if (p1.getY() > 400 && p1.getY() < 450)
	{
		if (p1.getColide() == 0)
		{
			p1.setX(p1.getX() + 0.5);
		}
	}


	if (p1.getX() > 470) p1.setX(470);

	// Redesenha o fase1 com as novas coordenadas 
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






		// Desenha um FASE1 preenchido com a cor corrente
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


int countlines(char *filename)
{

	FILE *file = fopen(filename, "r");
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


void lerArquivoFase(char* nomeArquivo)
{
	int i, j;
	int linhas = countlines(nomeArquivo);
	float value[10000][6];
	FILE *archivo;
	archivo = fopen(nomeArquivo, "r");
	if (archivo == NULL)
		exit(1);
	i = 0;
	while (feof(archivo) == 0)
	{
		fscanf(archivo, "%f %f %f %f %f %f", &value[i][0], &value[i][1], &value[i][2],
			&value[i][3], &value[i][4], &value[i][5]);
		i++;
	}
	printf("%d", linhas);

	printf("Your matrix:\n");
	bool verifica = true;
	for (int i = 0; i < linhas + 1; i++) {
		verifica = true;
		for (j = 0; j < 5; j++) {
			if (value[i][0] == 1 && verifica) {
				verifica = false;
				//printf("classe 1");
				Caminhao c1;
				c1.setX(value[i][1]);
				c1.setY(value[i][2]);
				c1.setHeight(value[i][3]);
				c1.setWidth(value[i][4]);
				c1.setVelocidade(value[i][5]);
				//cout << "X " << c1.getX() << " ";
				caminhoes.push_back(c1);
			}
			else if (value[i][0] == 2 && verifica) {
				verifica = false;
				Madeira m1;
				m1.setX(value[i][1]);
				m1.setY(value[i][2]);
				m1.setHeight(value[i][3]);
				m1.setWidth(value[i][4]);
				m1.setVelocidade(value[i][5]);
				madeiras.push_back(m1);
				//printf("classe 2");
			}

		}
	}
	fclose(archivo);



}

void InicializaFase() {

	switch (fase) {
	case 1:
		nomeFase = "fase1.txt";
		break;
	case 2:
		nomeFase = "fase2.txt";
		break;
	case 3:
		nomeFase = "fase3.txt";
		break;
	case 4:
		nomeFase = "fase4.txt";
		break;
	case 5:
		nomeFase = "fase5.txt";
		break;

	}

	lerArquivoFase(nomeFase);

}

// Inicializa parâmetros de rendering
void Inicializa(void)
{

	InicializaFase();




	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	win = 150.0f;
	if (fase == 1) {
		primitiva = ANIMACAO;
	}
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

// Função que desenha um FASE1

void DesenhaFase1(void)
{
	gameState = GameStates::PLAYING;


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






	for (int i = 0; i < caminhoes.size(); i++) {
		glBegin(GL_QUADS);
		glColor3f(0.4f, 0.4f, 0.4f);
		glVertex2i(GLint(caminhoes[i].getX()), GLint(caminhoes[i].getY() + caminhoes[i].getHeight()));
		glVertex2i(GLint(caminhoes[i].getX()), GLint(caminhoes[i].getY()));
		glVertex2i(GLint(caminhoes[i].getX() + caminhoes[i].getWidth()), GLint(caminhoes[i].getY()));
		glVertex2i(GLint(caminhoes[i].getX() + caminhoes[i].getWidth()), GLint(caminhoes[i].getY() + caminhoes[i].getHeight()));
		glEnd();

		if (caminhoes[i].getX() > 500 && caminhoes[i].getVelocidade()>0) {
			caminhoes[i].setX(-1650);
		} else if (caminhoes[i].getX() < -1650 && caminhoes[i].getVelocidade()<0) {
			caminhoes[i].setX(500);
		}
	}

	for (int i = 0; i < caminhoes.size(); i++) {

		caminhoes[i].colideTeste(p1);

		if (caminhoes[i].getColide() == 1) {
			p1.setX(250);
			p1.setY(10);
			caminhoes[i].setColide(0);
			p1.setLife(p1.getLife() - 1);
		}
	}



	for (int i = 0; i < madeiras.size(); i++) {

		glBegin(GL_QUADS);
		glColor3f(0.4f, 0.4f, 0.4f);
		glVertex2i(GLint(madeiras[i].getX()), GLint(madeiras[i].getY() + madeiras[i].getHeight()));
		glVertex2i(GLint(madeiras[i].getX()), GLint(madeiras[i].getY()));
		glVertex2i(GLint(madeiras[i].getX() + madeiras[i].getWidth()), GLint(madeiras[i].getY()));
		glVertex2i(GLint(madeiras[i].getX() + madeiras[i].getWidth()), GLint(madeiras[i].getY() + madeiras[i].getHeight()));
		glEnd();


		if (madeiras[i].getX() > 500 && madeiras[i].getVelocidade()>0)
		{
			madeiras[i].setX(-1650);
		} else if (madeiras[i].getX() < -1650 && madeiras[i].getVelocidade()<0) {
			madeiras[i].setX(500);
		}
	}
	int cont = 0;
	if (p1.getY() > 255 && p1.getY() < 450)
	{
		
		for (int i = 0; i < madeiras.size(); i++) {

			madeiras[i].colideTeste(p1);

			if (madeiras[i].getColide() == 1) {
				cont++;
			}
		}

		if (cont == 0) {
			p1.setX(250); p1.setY(10); 			p1.setLife(p1.getLife() - 1);
		} 
		

	}
	
	if (p1.getLife() == 0)
	{
		primitiva = GALINHA;
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


	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2i(GLint(p1.getX()), GLint(p1.getY() + p1.getHeight()));
	glVertex2i(GLint(p1.getX()), GLint(p1.getY()));
	glVertex2i(GLint(p1.getX() + p1.getWidth()), GLint(p1.getY()));
	glVertex2i(GLint(p1.getX() + p1.getWidth()), GLint(p1.getY() + p1.getHeight()));
	glEnd();



	if (p1.getY() > 450 && p1.getY() < 500)
	{
		p1.setLife(5);
		gameState = GameStates::WIN;
		if (gameState == GameStates::WIN && primitiva == FASE1) {
			gameState = GameStates::PLAYING;
			primitiva = FASE2;
			fase = 2;
			
		} 	else if (gameState == GameStates::WIN && primitiva == FASE2) {
			gameState = GameStates::PLAYING;
			primitiva = FASE3;
			fase = 3;

		}	else if (gameState == GameStates::WIN && primitiva == FASE3) {
			gameState = GameStates::PLAYING;
			primitiva = FASE4;
			fase = 4;

		}	else if (gameState == GameStates::WIN && primitiva == FASE4) {
			gameState = GameStates::PLAYING;
			primitiva = FASE5;
			fase = 5;

		}
		else if (gameState == GameStates::WIN && primitiva == FASE5) {
			gameState = GameStates::WINGAME;
			primitiva = VITORIA;
			fase = 1;
		}

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

		sprintf(texto, "PASSEI");

		DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
		// Executa os comandos OpenGL
		glutSwapBuffers();
		glutPostRedisplay();
		Sleep(timer2 * 1000);
		InicializaFase();

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		p1.setX(250);
		p1.setY(10);

	}


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
	case GALINHA:  DesenhaGalinha();
		break;
	case FASE1:  DesenhaFase1();
		break;
	case FASE2:  DesenhaFase1();
		break;
	case FASE3:  DesenhaFase1();
		break;
	case FASE4:  DesenhaFase1();
		break;
	case FASE5:  DesenhaFase1();
		break;
	case VITORIA:	DesenhaVitoria();
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

	if (primitiva == FASE1 || primitiva == FASE2 || primitiva == FASE3 || primitiva == FASE4 || primitiva == FASE5)
	{
		if (key == GLUT_KEY_UP) {
			p1.setY(p1.getY() + 50);
			if (p1.getY() > 470)
			{
				p1.setY(470);
			}

		}
		if (key == GLUT_KEY_DOWN) {
			p1.setY(p1.getY() - 50);
			if (p1.getY() < 10) p1.setY(10);
		}

		if (key == GLUT_KEY_LEFT) {
			p1.setX(p1.getX() - 50);
			if (p1.getX() < 0) p1.setX(0);
		}
		if (key == GLUT_KEY_RIGHT) {
			p1.setX(p1.getX() + 50);
			if (p1.getX() > 470) p1.setX(470);
		}
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
		primitiva = FASE1;
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
	glutAddMenuEntry("FASE1", 0);
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
						primitiva = FASE1;
						//DesenhaFase1();
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