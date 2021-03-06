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
#include "Item.h"
#include <random>
#include <time.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;

GLint FPS = 0;

Personagem p1;


GLint ClickON = 0;
GLint break1 = 0;
GLfloat timer2 = 3.3;
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
GLint MAX;
GLint MIN;
GLfloat xiStep = 0.7f;
GLfloat yiStep = 0.7f;
GLfloat xjStep = 0.7f;
GLfloat yjStep = 0.7f;


GLsizei rsize = 30;

// Tamanho do incremento nas dire��es x e y 
// (n�mero de pixels para se mover a cada
// intervalo de tempo)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

bool itemColetadoFase = false;


// Constantes
#define FASE1 1
#define CREDITOS 2
#define Opcoes   3
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
enum GameStates { OPTIONS, PLAYING, WIN, GAMEOVER, WINGAME };
GameStates gameState = GameStates::OPTIONS;
int fase = 1;
int tempo = 0;
int tempoColisaoItem = 0;
int tempoColisao;
char* nomeFase;
bool reducaoVelocidade = false;

bool fullScreen = false;

// Vari�veis
char texto[30];
GLfloat win, r, g, b;
GLint view_w, view_h, primitiva;

vector<Caminhao> caminhoes;
vector<Madeira> madeiras;
vector<Item> itens;


void Desenha(void);
void DesenhaTexto(char *string, void *font, GLfloat xAux, GLfloat yAux);
void MoveMouse(int x, int y);
void MoveMouseBotaoPressionado(int x, int y);
void Timer(int value);
void lerArquivoItem(char* nomeArquivo);


void GerenciaTeclado(unsigned char key, int x, int y)
{
	int c = key;

	switch (c) {

	case 13:
		primitiva = FASE1;
		break1 = 1;
		break;
	case 8:
		if (primitiva == Opcoes||primitiva==CREDITOS)
		{
			primitiva = MENU;
		}
		break;
	case 114:
		primitiva = MENU;
		break;
	case 27:
		primitiva = SAIR;
		break;
	case 'f': case'F':
		cout << "teste";
		if (fullScreen == false) {
			glutFullScreen();
			fullScreen = true;
		}
		else {
			fullScreen = false;
			glutReshapeWindow(500, 500);
		}
		break;

	case 111:
		primitiva = Opcoes;
		break;

	}

	if (primitiva == FASE1 || primitiva == FASE2 || primitiva == FASE3 || primitiva == FASE4 || primitiva == FASE5) {
		switch (c) {

		case 119:
			PlaySound(TEXT("sons\\passo.wav"), NULL, SND_ASYNC);
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


	nomeFase = "fase1.txt";
	fase = 1;
	lerArquivoItem(nomeFase);

	p1.setLife(5);


	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

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
	PlaySound(TEXT("sons\\To morta.wav"), NULL, SND_ASYNC);
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
	// Executa os comandos OpenGL
	glutSwapBuffers();
	glutPostRedisplay();
	Sleep(timer2 * 1000);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	primitiva = MENU;
	PlaySound(TEXT("sons\\Ultraje a Rigor - Marylou.wav"), NULL, SND_ASYNC);

}
void DesenhaVitoria() {


	p1.setLife(5);


	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glutKeyboardFunc(GerenciaTeclado);

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


	sprintf(texto, "TO VIVA!!");
	PlaySound(TEXT("sons\\To viva.wav"), NULL, SND_ASYNC);
	lerArquivoItem(nomeFase);
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
void controlarVelocidade() {

	for (int i = 0; i < caminhoes.size(); i++) {
		if (reducaoVelocidade) {
			caminhoes[i].setX(caminhoes[i].getX() + (caminhoes[i].getVelocidade() / 3));
		}
		else {
			caminhoes[i].setX(caminhoes[i].getX() + caminhoes[i].getVelocidade());
		}
	}

	for (int i = 0; i < madeiras.size(); i++) {
		if (reducaoVelocidade) {
			madeiras[i].setX(madeiras[i].getX() + (madeiras[i].getVelocidade() / 3));
		}
		else {
			madeiras[i].setX(madeiras[i].getX() + madeiras[i].getVelocidade());
		}
	}
}

void controlarItens() {
	for (int i = 0; i < itens.size(); i++)
	{

		// Muda a dire��o quando chega na borda esquerda ou direita
		if (itens[i].getFase() == 1 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.7;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.7;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -0.7;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 0.7;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}


		else if (itens[i].getFase() == 2 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.4;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.4;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -1.2;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 1.2;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		else if (itens[i].getFase() == 3 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.7;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.9;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -1.2;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 1.7;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		else if (itens[i].getFase() == 4 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.5;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.5;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -0.9;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 0.9;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		else if (itens[i].getFase() == 5 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -1.7;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 1.7;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -1.3;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 1.3;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}


		// Muda a dire��o quando chega na borda esquerda ou direita
		if (itens[i].getFase() == 1 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470){
				xiStep = -0.7;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.7;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -0.7;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 0.7;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}


		else if (itens[i].getFase() == 2 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.4;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.4;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -1.2;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 1.2;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		else if (itens[i].getFase() == 3 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.7;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.9;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -1.2;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 1.7;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		else if (itens[i].getFase() == 4 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -0.5;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 0.5;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -0.9;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 0.9;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		else if (itens[i].getFase() == 5 && itens[i].getTipo() == 1)
		{

			if (itens[i].getX() > 470)
			{
				xiStep = -1.7;
			}

			if (itens[i].getX() < 0)
			{
				xiStep = 1.7;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yiStep = -1.3;
			}

			if (itens[i].getY() < 50)
			{

				yiStep = 1.3;
			}

			itens[i].setX(itens[i].getX() + xiStep);
			itens[i].setY(itens[i].getY() + yiStep);
		}

		if (itens[i].getFase() == 1 && itens[i].getTipo() == 2)
		{

			if (itens[i].getX() > 470)
			{
				xjStep = -0.3;
			}

			if (itens[i].getX() < 0)
			{
				xjStep = 0.4;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yjStep = -0.6;
			}

			if (itens[i].getY() < 50)
			{

				yjStep = 0.9;
			}

			itens[i].setX(itens[i].getX() + xjStep);
			itens[i].setY(itens[i].getY() + yjStep);
		}


		else if (itens[i].getFase() == 2 && itens[i].getTipo() == 2)
		{

			if (itens[i].getX() > 470)
			{
				xjStep = -0.5;
			}

			if (itens[i].getX() < 0)
			{
				xjStep = 0.8;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yjStep = -1.1;
			}

			if (itens[i].getY() < 50)
			{

				yjStep = 1.0;
			}

			itens[i].setX(itens[i].getX() + xjStep);
			itens[i].setY(itens[i].getY() + yjStep);
		}

		else if (itens[i].getFase() == 3 && itens[i].getTipo() == 2)
		{

			if (itens[i].getX() > 470)
			{
				xjStep = -0.4;
			}

			if (itens[i].getX() < 0)
			{
				xjStep = 0.9;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yjStep = -0.6;
			}

			if (itens[i].getY() < 50)
			{

				yjStep = 1.7;
			}

			itens[i].setX(itens[i].getX() + xjStep);
			itens[i].setY(itens[i].getY() + yjStep);
		}

		else if (itens[i].getFase() == 4 && itens[i].getTipo() == 2)
		{

			if (itens[i].getX() > 470)
			{
				xjStep = -0.3;
			}

			if (itens[i].getX() < 0)
			{
				xjStep = 1.5;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yjStep = -0.9;
			}

			if (itens[i].getY() < 50)
			{

				yjStep = 1.9;
			}

			itens[i].setX(itens[i].getX() + xjStep);
			itens[i].setY(itens[i].getY() + yjStep);
		}

		else if (itens[i].getFase() == 5 && itens[i].getTipo() == 2)
		{

			if (itens[i].getX() > 470)
			{
				xjStep = -1.7;
			}

			if (itens[i].getX() < 0)
			{
				xjStep = 1.3;
			}
			// Muda a dire��o quando chega na borda superior ou inferior
			if (itens[i].getY() > 470)
			{
				yjStep = -1.9;
			}

			if (itens[i].getY() < 50)
			{

				yjStep = 2.3;
			}

			itens[i].setX(itens[i].getX() + xjStep);
			itens[i].setY(itens[i].getY() + yjStep);
		}


	}



}

void Timer(int value)
{


	controlarVelocidade();
	controlarItens();


	if (primitiva == FASE1)
	{

		if (p1.getY() > 250 && p1.getY() < 300)
		{

			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.5);
			}

		}
		if (p1.getY() > 300 && p1.getY() < 350) {
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.7);
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
				p1.setX(p1.getX() + 0.3);
			}
		}
	}


	if (primitiva == FASE2)
	{
		if (p1.getY() > 250 && p1.getY() < 300)
		{

			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.6);
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
				p1.setX(p1.getX() + 0.5);
			}
		}

		if (p1.getY() > 400 && p1.getY() < 450)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.4);
			}
		}
	}


	if (primitiva == FASE3)
	{
		if (p1.getY() > 250 && p1.getY() < 300)
		{

			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.7);
			}

		}
		if (p1.getY() > 300 && p1.getY() < 350) {
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + -0.8);
			}

		}

		if (p1.getY() > 350 && p1.getY() < 400)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() - 0.4);
			}
		}

		if (p1.getY() > 400 && p1.getY() < 450)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.6);
			}
		}
	}


	if (primitiva == FASE4)
	{
		if (p1.getY() > 250 && p1.getY() < 300)
		{

			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.8);
			}

		}
		if (p1.getY() > 300 && p1.getY() < 350) {
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + -1.0);
			}

		}

		if (p1.getY() > 350 && p1.getY() < 400)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.5);
			}
		}

		if (p1.getY() > 400 && p1.getY() < 450)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() - 0.7);
			}
		}
	}


	if (primitiva == FASE5)
	{
		if (p1.getY() > 250 && p1.getY() < 300)
		{

			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() - 0.9);
			}

		}
		if (p1.getY() > 300 && p1.getY() < 350) {
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 1.3);
			}

		}

		if (p1.getY() > 350 && p1.getY() < 400)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() - 0.9);
			}
		}

		if (p1.getY() > 400 && p1.getY() < 450)
		{
			if (p1.getColide() == 0)
			{
				p1.setX(p1.getX() + 0.6);
			}
		}
	}



	if (p1.getX() > 470) p1.setX(470);
	if (p1.getX() < 0) p1.setX(0);
	
	glutPostRedisplay();
	glutTimerFunc(3.3, Timer, 1);

}



void DesenhaAnimacao() {


	glutKeyboardFunc(GerenciaTeclado);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Limpa a janela de visualiza��o com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica que a cor corrente � vermelha
	//         R     G     B
	glColor3f(1.0f, 1.0f, 0.0f);

	for (int i = 0; i < 500; i++) {
		glutKeyboardFunc(GerenciaTeclado);

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
		//glutTimerFunc(33, Timer, 1);

	}


	for (int i = 0; i < 500; i++) {
		glutKeyboardFunc(GerenciaTeclado);


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
		Sleep(timer2);
		glutKeyboardFunc(GerenciaTeclado);

	}



	primitiva = MENU;
}



void DesenhaMenu(void)
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

	caminhoes.clear();
	madeiras.clear();


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

void lerArquivoItem(char* nomeArquivo)
{
	int i, j;
	int linhas = countlines(nomeArquivo);
	float value[10000][4];

	itens.clear();
	FILE *archivo;
	archivo = fopen(nomeArquivo, "r");
	if (archivo == NULL)
		exit(1);
	i = 0;
	while (feof(archivo) == 0)
	{
		fscanf(archivo, "%f %f %f %f", &value[i][0], &value[i][1], &value[i][2],
			&value[i][3]);
		i++;
	}
	printf("%d", linhas);

	printf("Your matrix:\n");
	bool verifica = true;
	for (int i = 0; i < linhas + 1; i++) {
		verifica = true;
		for (j = 0; j < 4; j++) {
			if (verifica) {
				Item item;
				item.setTipo(value[i][0]);
				item.setFase(value[i][1]);
				item.setX(value[i][2]);
				item.setY(value[i][3]);
				itens.push_back(item);
				verifica = false;
			}
		}
	}



	fclose(archivo);


}



void InicializaFase(int fase) {

	PlaySound(TEXT("sons\\Ultraje a Rigor - Marylou.wav"), NULL, SND_ASYNC);

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
	lerArquivoItem("itens.txt");

}

// Inicializa par�metros de rendering
void Inicializa(void)
{

	InicializaFase(1);


	// Define a cor de fundo da janela de visualiza��o como preta
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

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Especifica as dimens�es da Viewport
	// Evita a divisao por zero
	if (h == 0) h = 1;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (left, right, bottom, top)
	if (w <= h)
		gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f*h / w);
	else
		gluOrtho2D(0.0f, 500.0f*w / h, 0.0f, 500.0f);
}



void desenhaItem1(float x, float y) {
	glBegin(GL_QUADS);
	glVertex2i(x, y + 20);
	glVertex2i(x, y + 10);
	glVertex2i(x + 30, y + 10);
	glVertex2i(x + 30, y + 20);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(x + 10, y + 30);
	glVertex2i(x + 10, y);
	glVertex2i(x + 20, y);
	glVertex2i(x + 20, y + 30);
	glEnd();
}

void desenhaItem2(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2i(x, y + 20);
	glVertex2i(x, y + 10);
	glVertex2i(x + 10, y);
	glVertex2i(x + 20, y);
	glVertex2i(x + 30, y + 10);
	glVertex2i(x + 30, y + 20);
	glVertex2i(x + 20, y + 30);
	glVertex2i(x + 10, y + 30);
	glVertex2i(x, y + 20);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.9f, 0.9f);

	glVertex2i(x + 3, y + 20);
	glVertex2i(x + 3, y + 10);
	glVertex2i(x + 10, y + 3);
	glVertex2i(x + 20, y + 3);
	glVertex2i(x + 27, y + 10);
	glVertex2i(x + 27, y + 20);
	glVertex2i(x + 20, y + 27);
	glVertex2i(x + 10, y + 27);
	glVertex2i(x + 3, y + 20);
	glEnd();


	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2i(x + 13, y + 13);
	glVertex2i(x + 13, y + 23);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2i(x + 12, y + 13);
	glVertex2i(x + 23, y + 13);
	glEnd();

}

void desenharCenario() {
	if (primitiva == FASE1)
	{

		glBegin(GL_QUADS);

		glColor3f(0.7f, 0.4f, 0.3f);
		glVertex2i(0, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 50);
		glVertex2i(0, 50);
		glEnd();



		glBegin(GL_QUADS);
		glColor3f(0.2f, 0.1f, 0.1f);
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

	}
	else if (primitiva == FASE2)
	{
		glBegin(GL_QUADS);

		glColor3f(0.2f, 0.1f, 0.1f);
		glVertex2i(0, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 50);
		glVertex2i(0, 50);
		glEnd();



		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.5f, 0.2f);
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

	}

	else if (primitiva == FASE3)
	{
		glBegin(GL_QUADS);

		glColor3f(1.0f, 0.5f, 0.2f);
		glVertex2i(0, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 50);
		glVertex2i(0, 50);
		glEnd();



		glBegin(GL_QUADS);
		glColor3f(0.1f, 0.3f, 0.8f);
		glVertex2i(0, 450);
		glVertex2i(500, 450);
		glVertex2i(500, 500);
		glVertex2i(0, 500);
		glEnd();



		glBegin(GL_QUADS);

		glColor3f(0.4f, 0.5f, 0.1f);
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

	}
	else if (primitiva == FASE4)
	{
		glBegin(GL_QUADS);

		glColor3f(0.1f, 0.3f, 0.8f);
		glVertex2i(0, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 50);
		glVertex2i(0, 50);
		glEnd();



		glBegin(GL_QUADS);
		glColor3f(0.2f, 0.0f, 0.0f);
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

	}
	else if (primitiva == FASE5)
	{
		glBegin(GL_QUADS);

		glColor3f(0.2f, 0.0f, 0.0f);
		glVertex2i(0, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 50);
		glVertex2i(0, 50);
		glEnd();



		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.9f);
		glVertex2i(0, 450);
		glVertex2i(500, 450);
		glVertex2i(500, 500);
		glVertex2i(0, 500);
		glEnd();



		glBegin(GL_QUADS);

		glColor3f(1.0f, 0.1f, 0.1f);
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

	}


}

void verificarColisaoCaminhao() {
	for (int i = 0; i < caminhoes.size(); i++) {

		caminhoes[i].colideTeste(p1);

		if (caminhoes[i].getColide() == 1) {
			p1.setX(250);
			p1.setY(10);
			caminhoes[i].setColide(0);
			p1.setLife(p1.getLife() - 1);
		}
	}
}

void movimentarCaminhao() {
	
	for (int i = 0; i < caminhoes.size(); i++) {
		glBegin(GL_QUADS);
		glColor3f(0.4f, 0.4f, 0.4f);
		glVertex2i(GLint(caminhoes[i].getX()), GLint(caminhoes[i].getY() + caminhoes[i].getHeight()));
		glVertex2i(GLint(caminhoes[i].getX()), GLint(caminhoes[i].getY()));
		glVertex2i(GLint(caminhoes[i].getX() + caminhoes[i].getWidth()), GLint(caminhoes[i].getY()));
		glVertex2i(GLint(caminhoes[i].getX() + caminhoes[i].getWidth()), GLint(caminhoes[i].getY() + caminhoes[i].getHeight()));
		glEnd();

		if (caminhoes[i].getX() > 500 && caminhoes[i].getVelocidade() > 0) {
			caminhoes[i].setX(-1650);
		}
		else if (caminhoes[i].getX() < -1650 && caminhoes[i].getVelocidade() < 0) {
			caminhoes[i].setX(500);
		}
	}

	verificarColisaoCaminhao();

}

void verificarColisaoMadeira() {
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
}

void movimentarMadeiras(){
	for (int i = 0; i < madeiras.size(); i++) {

		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.2f, 0.1f);
		glVertex2i(GLint(madeiras[i].getX()), GLint(madeiras[i].getY() + madeiras[i].getHeight()));
		glVertex2i(GLint(madeiras[i].getX()), GLint(madeiras[i].getY()));
		glVertex2i(GLint(madeiras[i].getX() + madeiras[i].getWidth()), GLint(madeiras[i].getY()));
		glVertex2i(GLint(madeiras[i].getX() + madeiras[i].getWidth()), GLint(madeiras[i].getY() + madeiras[i].getHeight()));
		glEnd();


		if (madeiras[i].getX() > 500 && madeiras[i].getVelocidade() > 0)
		{
			madeiras[i].setX(-1650);
		}
		else if (madeiras[i].getX() < -1650 && madeiras[i].getVelocidade() < 0) {
			madeiras[i].setX(500);
		}
	}
	
	verificarColisaoMadeira();
}


void verificaColisaoItem() {
	if (!itemColetadoFase) {

		for (int i = 0; i < itens.size(); i++) {

			glColor3f(0.8f, 0.1f, 0.1f);


			if (itens[i].getFase() == 1 && itens[i].getTipo() == 1 && primitiva == FASE1)
			{
				desenhaItem1(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 2 && itens[i].getTipo() == 1 && primitiva == FASE2) {
				desenhaItem1(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 3 && itens[i].getTipo() == 1 && primitiva == FASE3) {
				desenhaItem1(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 4 && itens[i].getTipo() == 1 && primitiva == FASE4) {
				desenhaItem1(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 5 && itens[i].getTipo() == 1 && primitiva == FASE5) {
				desenhaItem1(itens[i].getX(), itens[i].getY());
			}



			glColor3f(0.3f, 0.7f, 0.9f);


			if (itens[i].getFase() == 1 && itens[i].getTipo() == 2 && primitiva == FASE1)
			{
				desenhaItem2(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 2 && itens[i].getTipo() == 2 && primitiva == FASE2) {
				desenhaItem2(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 3 && itens[i].getTipo() == 2 && primitiva == FASE3) {
				desenhaItem2(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 4 && itens[i].getTipo() == 2 && primitiva == FASE4) {
				desenhaItem2(itens[i].getX(), itens[i].getY());
			}
			else if (itens[i].getFase() == 5 && itens[i].getTipo() == 2 && primitiva == FASE5) {
				desenhaItem2(itens[i].getX(), itens[i].getY());
			}



		}
		tempo = tempo + 1;


		int itemColetado = 0;
		for (int i = 0; i < itens.size(); i++) {

			itens[i].colideTeste(p1);
			if (itens[i].getFase() == 1 && itens[i].getTipo() == 1 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				p1.setLife(p1.getLife() + 1);
				//PlaySound(TEXT("sons\\Ambulancia besta.wav"), NULL, SND_ASYNC);
				//PlaySound(TEXT("sons\\Ultraje a Rigor - Marylou.wav"), NULL, SND_LOOP | SND_ASYNC);
				break;

			}
			else if (itens[i].getFase() == 2 && itens[i].getTipo() == 1 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				p1.setLife(p1.getLife() + 1);
				break;

			}
			else if (itens[i].getFase() == 3 && itens[i].getTipo() == 1 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				p1.setLife(p1.getLife() + 1);

				break;

			}
			else if (itens[i].getFase() == 4 && itens[i].getTipo() == 1 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				p1.setLife(p1.getLife() + 1);

				break;

			}
			else if (itens[i].getFase() == 5 && itens[i].getTipo() == 1 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				p1.setLife(p1.getLife() + 1);

				break;

			}

			if (itens[i].getFase() == 1 && itens[i].getTipo() == 2 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				reducaoVelocidade = true;
				tempoColisaoItem = tempo;
				//PlaySound(TEXT("sons\\Relogio.wav"), NULL, SND_ASYNC);
				//PlaySound(TEXT("sons\\Ultraje a Rigor - Marylou.wav"), NULL, SND_LOOP | SND_ASYNC);
				break;

			}
			else if (itens[i].getFase() == 2 && itens[i].getTipo() == 2 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				break;

			}
			else if (itens[i].getFase() == 3 && itens[i].getTipo() == 2 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				break;


			}
			else if (itens[i].getFase() == 4 && itens[i].getTipo() == 2 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				break;

			}
			else if (itens[i].getFase() == 5 && itens[i].getTipo() == 2 && itens[i].getColide() == 1) {
				itemColetado = i;
				itens[i].setTipo(6);
				itens[i].setColide(0);
				break;
			}

		}


	}

	p1.vidaMax();
	if (reducaoVelocidade) {
		tempoColisao = tempoColisaoItem + 2000;
		if (tempo <= tempoColisao) {

		}
		else {
			reducaoVelocidade = false;
		}
	}


}

void controlarVidas() {
	if (p1.getLife() == 0)
	{
		gameState = GameStates::GAMEOVER;
		madeiras.clear();
		caminhoes.clear();
		nomeFase = "fase1.txt";
		InicializaFase(1);
		fase = 1;
		itemColetadoFase = false;
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



	if (p1.getY() > 450 && p1.getY() < 500 && gameState == GameStates::PLAYING)
	{
		p1.setLife(5);
		gameState = GameStates::WIN;
		if (gameState == GameStates::WIN && primitiva == FASE1) {
			gameState = GameStates::PLAYING;
			primitiva = FASE2;
			InicializaFase(2);
			fase = 2;

		}
		else if (gameState == GameStates::WIN && primitiva == FASE2) {
			gameState = GameStates::PLAYING;
			primitiva = FASE3;
			InicializaFase(3);
			fase = 3;

		}
		else if (gameState == GameStates::WIN && primitiva == FASE3) {
			gameState = GameStates::PLAYING;
			primitiva = FASE4;
			fase = 4;
			InicializaFase(4);

		}
		else if (gameState == GameStates::WIN && primitiva == FASE4) {
			gameState = GameStates::PLAYING;
			primitiva = FASE5;
			fase = 5;
			InicializaFase(5);

		}
		else if (gameState == GameStates::WIN && primitiva == FASE5) {
			gameState = GameStates::WINGAME;
			primitiva = VITORIA;
			fase = 1;
			InicializaFase(1);
		}

		itemColetadoFase = false;


		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glutKeyboardFunc(GerenciaTeclado);

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
		PlaySound(TEXT("sons\\Venci.wav"), NULL, SND_ASYNC);

		DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 280, 380);
		// Executa os comandos OpenGL
		glutSwapBuffers();
		glutPostRedisplay();
		Sleep(timer2 * 1000);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		p1.setX(250);
		p1.setY(10);

	}

}
// Fun��o que desenha um FASE1

void desenhaFase(void)
{
	gameState = GameStates::PLAYING;

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex2i(237, 324);
	glVertex2i(263, 324);

	glVertex2i(263, 314);
	glVertex2i(237, 314);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(250, 250);
	glVertex2i(300, 250);
	glVertex2i(250, 300);
	glVertex2i(300, 300);
	glEnd();


	glClear(GL_COLOR_BUFFER_BIT);
	desenharCenario();
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


	desenharCenario();
	movimentarCaminhao();
	movimentarMadeiras();
	verificaColisaoItem();
	controlarVidas();

	



	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(500, 0);
	glVertex2i(2500, 0);
	glVertex2i(2500, 2500);
	glVertex2i(500, 2500);
	glEnd();

	glutPostRedisplay();




}



// Fun��o que desenha um tri�ngulo
void desenhaCreditos(void)
{

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 80.0f);
	glVertex2f(100.0f, 20.0f);
	glVertex2f(400.0f, 20.0f);
	glVertex2f(400.0f, 80.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 160.0f);
	glVertex2f(100.0f, 100.0f);
	glVertex2f(400.0f, 100.0f);
	glVertex2f(400.0f, 160.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);

	sprintf(texto, "VOLTAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 120);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 40);


	glColor3f(1.0f, 1.0f, 1.0f);

	sprintf(texto, "Augusto Castro");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 470);
	sprintf(texto, "D�bora cristina");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 435);
	sprintf(texto, "Rafael Cesario");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 400);
	sprintf(texto, "Rainara Araujo");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 365);
	sprintf(texto, "Matheus Assuncao");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 330);
	sprintf(texto, "Walace Andrade");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 300);








}

// Fun��o que desenha um Opcoes
void DesenhaOpcoes(void)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 80.0f);
	glVertex2f(100.0f, 20.0f);
	glVertex2f(400.0f, 20.0f);
	glVertex2f(400.0f, 80.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100.0f, 160.0f);
	glVertex2f(100.0f, 100.0f);
	glVertex2f(400.0f, 100.0f);
	glVertex2f(400.0f, 160.0f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(50.0f, 250.0f);
	glVertex2f(50.0f, 310.0f);
	glVertex2f(110.0f, 310.0f);
	glVertex2f(110.0f, 250.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(120.0f, 250.0f);
	glVertex2f(120.0f, 310.0f);
	glVertex2f(180.0f, 310.0f);
	glVertex2f(180.0f, 250.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(190.0f, 250.0f);
	glVertex2f(190.0f, 310.0f);
	glVertex2f(250.0f, 310.0f);
	glVertex2f(250.0f, 250.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(120.0f, 320.0f);
	glVertex2f(120.0f, 380.0f);
	glVertex2f(180.0f, 380.0f);
	glVertex2f(180.0f, 320.0f);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(150.0f, 280.0f);
	glVertex2f(160.0f, 270.0f);
	glVertex2f(160.0f, 270.0f);
	glVertex2f(170.0f, 280.0f);
	glVertex2f(160.0f, 270.0f);
	glVertex2f(160.0f, 290.0f);

	glEnd();



	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(155.0f, 345.0f);
	glVertex2f(165.0f, 355.0f);
	glVertex2f(165.0f, 355.0f);
	glVertex2f(175.0f, 345.0f);
	glVertex2f(165.0f, 335.0f);
	glVertex2f(165.0f, 355.0f);

	glEnd();
	

	glColor3f(0.0f, 0.0f, 0.0f);
	sprintf(texto, "a/<-");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 60, 270);
	sprintf(texto, "s/");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 130, 270);
	sprintf(texto, "d/->");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 200, 270);
	sprintf(texto, "w/");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 130, 340);


	sprintf(texto, "VOLTAR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 120);
	sprintf(texto, "SAIR");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 180, 40);


	glColor3f(1.0f, 1.0f, 1.0f);

	sprintf(texto, "Porque a galinha atravessou a rua?");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 470);
	sprintf(texto, "Porque a galinha atravessou o rio?");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 435);
	sprintf(texto, "Controle a galinha e descubra");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 50, 400);


	sprintf(texto, "W, A , S e D movem o personagem para");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 20, 225);
	sprintf(texto, "Cima, Esquerda, Baixo e Direita");
	DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_24, 20, 195);







}

void sair() { exit(0); }





// Desenha um texto na janela GLUT
void DesenhaTexto(char *string, void *font, GLfloat xAux, GLfloat yAux)
{
	glPushMatrix();
	// Posi��o no universo onde o texto ser� colocado          
	glRasterPos2f(xAux, yAux);

	//glRasterPos2f(-win, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(font, *string++);
	glPopMatrix();
}

// Fun��o callback chamada para fazer o desenho
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
	case FASE1:  desenhaFase();
		break;
	case FASE2:  desenhaFase();
		break;
	case FASE3:  desenhaFase();
		break;
	case FASE4:  desenhaFase();
		break;
	case FASE5:  desenhaFase();
		break;
	case VITORIA:	DesenhaVitoria();
		break;
	case CREDITOS: desenhaCreditos();
		break;
	case Opcoes:   DesenhaOpcoes();
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

	// Exibe a posi��o do mouse na janela
	//glutPassiveMotionFunc(MoveMouse);
	//glutMotionFunc(MoveMouseBotaoPressionado);
	//DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_10, 10, 460);
	glutPostRedisplay();
	glutSwapBuffers();

}


// Fun��o callback chamada sempre que o mouse � movimentado
// sobre a janela GLUT com um bot�o pressionado
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


	glutPostRedisplay();
}

// Fun��o callback chamada sempre que o mouse � movimentado
// sobre a janela GLUT 
void MoveMouse(int x, int y)
{
	//glColor3f(1.0f, 1.0f, 0.0f);
	//sprintf(texto, "(%d,%d)", x, y);
	//DesenhaTexto(texto, GLUT_BITMAP_TIMES_ROMAN_10, 10, 460);
	glutPostRedisplay();
}

// Fun��o callback chamada para gerenciar eventos do teclado   
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

// Gerenciamento do menu com as op��es de cores           
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

// Gerenciamento do menu com as op��es de cores           
void MenuPrimitiva(int op)
{
	switch (op) {
	case 0:
		primitiva = FASE1;
		break;
	case 1:
		primitiva = CREDITOS;
		break;
	case 2:
		primitiva = Opcoes;
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
	glutAddMenuEntry("Tri�ngulo", 1);
	glutAddMenuEntry("Opcoes", 2);
	glutAddMenuEntry("Menu", 3);

	menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Cor", submenu1);
	glutAddSubMenu("Primitivas", submenu2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}





// Fun��o callback chamada para gerenciar eventos do mouse
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

						//desenhaFase();
					}
					if (worldY > 320 && worldY < 380)
					{
						primitiva = Opcoes;

						//DesenhaOpcoes();

					}
					if (worldY > 220 && worldY < 280)
					{
						primitiva = CREDITOS;
					}
					if (worldY > 120 && worldY < 180)
					{
						primitiva = SAIR;
					}
				}
			}
		}

	}


	if (primitiva == Opcoes || primitiva == CREDITOS)
	{
		if (button == GLUT_LEFT_BUTTON)
		{



			if (state == GLUT_UP)
			{
				if (worldX > 100 && worldX < 400) {

					if (worldY > 20 && worldY < 80)
					{
						primitiva = SAIR;
						//desenhaFase();
					}
					if (worldY > 120 && worldY < 180)
					{
						primitiva = MENU;

						//DesenhaOpcoes();

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
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TO MORTA");

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