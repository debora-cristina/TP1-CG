#pragma once
// classes example
#include <GL/glut.h>
#include "Personagem.h"

class Escopo {
	float x, y;
	float width, height;
	float caixaX, caixaY;
	int colide;
	float velocidade;

public:

	Escopo() {
		
	}

	void setX(float xPos) {
		x = xPos;
	}
	void setY(float yPos) {
		y = yPos;
	}

	void setColide(int colideX) {
		colide = colideX;
	}

	void setWidth(float widthC) {
		width = widthC;
		caixaX = widthC;
	}
	void setHeight(float heightC) {
		height = heightC;
		caixaY = heightC;

	}
	
	void setCaixaX(float caixaPosX) {
		caixaX = caixaPosX;
	}
	void setCaixaY(float caixaPosY) {
		caixaY = caixaPosY;
	}

	void setVelocidade(float velocidadePos) {
		velocidade = velocidadePos;
	}

	float getCaixaX() {
		return caixaX;
	}
	float getCaixaY() {
		return caixaY;
	}

	int getColide() {
		return colide;
	}

	float getVelocidade() {
		return velocidade;
	}

	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getWidth() {
		return width;
	}
	float getHeight() {
		return height;
	}

	void colideTeste(Personagem p1)	{

	}
	


};