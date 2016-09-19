#pragma once
// classes example
#include <GL/glut.h>

class Personagem {
	float x, y;
	float width, height;
	float caixaX, caixaY;
	int life;

public:

	Personagem() {
		x = 250;
		y = 10;
		width = 30;
		height = 30;
		caixaX = 30;
		caixaY = 30;
		life = 5;

	}

	void setX(float xPos) {
		x = xPos;
	}
	void setY(float yPos) {
		y = yPos;
	}
	void setWidth(float widthC) {
		width = widthC;
	}
	void setHeight(float heightC) {
		height = height;
	}
	void setCaixaX(float caixaPosX) {
		caixaX = caixaPosX;
	}
	void setCaixaY(float caixaPosY) {
		caixaY = height;
	}
	void setLife(int lifeX) {
		life = lifeX;
	}

	int getLife() {
		return life;
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
	float getCaixaX() {
		return caixaX;
	}
	float getCaixaY() {
		return caixaY;
	}


};