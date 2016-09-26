#pragma once
// classes example
#include <GL/glut.h>
#include "Personagem.h"

class Item {
	float x, y;
	int fase;
	int tipo;
	int colide;
	float caixaX, caixaY;


public:

	Item() {
		x = 0;
		y = 0;
		tipo = 0;
		fase = 0;
		colide = 0;
		caixaX = 30;
		caixaY = 30;
	}


	float getCaixaX() {
		return caixaX;
	}
	float getCaixaY() {
		return caixaY;
	}


	void setCaixaX(float caixaPosX) {
		caixaX = caixaPosX;
	}
	void setCaixaY(float caixaPosY) {
		caixaY = caixaPosY;
	}

	void setX(float xPos) {
		x =	xPos;
	}
	void setY(float yPos) {
		y = yPos;
	}

	void setFase(int fasePos) {
		fase = fasePos;
	}
	void setTipo(float tipoPos) {
		tipo = tipoPos;
	}


	float getFase() {
		return fase;
	}
	float getTipo() {
		return tipo;
	}

	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	
	void setColide(float colideX) {
		colide = colideX;
	}

	int getColide() {
		return colide;
	}

	void colideTeste(Personagem p1)
	{
		//p1.getX()					x do personagem
		//p1.getY()					y do personagem
		//p1.getX()+p1.getCaixaX()  x max do personagem
		//p1.getY()+p1.getCaixaY()  y max do personagem
		//x							x do personagem
		//y							y do personagem
		//x+caixaX					x max do personagem
		//y+caixaY					y max do personagem



		if (p1.getX()>(getX() + getCaixaX()) || (p1.getX() + p1.getCaixaX()) < (getX()) || p1.getY()>(getY() + getCaixaY()) || (p1.getY() + p1.getCaixaY()) < (getY()))
		{
			setColide(0);
		}

		else {


			setColide(1);

		}

	}


};
