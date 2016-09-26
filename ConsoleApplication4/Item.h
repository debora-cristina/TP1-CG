#pragma once
// classes example
#include <GL/glut.h>
#include "Personagem.h"

class Item {
	float x, y;
	int fase;
	int tipo;

public:

	Item() {

	}

	void setX(float x) {
		x = this->x;
	}
	void setY(float yPos) {
		y = yPos;
	}

	void setFase(int fase) {
		fase = this->fase;
	}
	void setTipo(float tipo) {
		tipo = this->tipo;
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
	
};
