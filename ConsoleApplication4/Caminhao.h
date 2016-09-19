#pragma once
// classes example
#include <GL/glut.h>
#include "Escopo.h"
#include "Personagem.h"


class Caminhao : public Escopo{
	

public:

	Caminhao() {
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

		/*if (p1.getX()<(x+caixaX) && p1.getY()<(y + caixaY))
		{

		colide = 1;
		}
		else if (p1.getX()<(x + caixaX) && (p1.getY() + p1.getCaixaY())>y)
		{
		colide = 1;
		}
		else if ((p1.getX() + p1.getCaixaX())  > x	 && p1.getY()<(y + caixaY))
		{
		colide = 1;
		}
		else if ((p1.getX() + p1.getCaixaX()) > x && (p1.getY() + p1.getCaixaY())>y)
		{
		colide = 1;
		}

		else colide = 0;*/



		//if (p1.getX()<(x + caixaX) && (p1.getX() + p1.getCaixaX())>(x+caixaX) && p1.getY()<(y + caixaY) && (p1.getY() + p1.getCaixaY())>(y + caixaY))
		//{

		//	colide = 1;
		//	}
		/*
		else if (p1.getX()<(x + caixaX) && (p1.getY() + p1.getCaixaY())>y)
		{
		colide = 1;
		}
		else if ((p1.getX() + p1.getCaixaX())  > x	 && p1.getY()<(y + caixaY))
		{
		colide = 1;
		}
		else if ((p1.getX() + p1.getCaixaX()) > x && (p1.getY() + p1.getCaixaY())>y)
		{
		colide = 1;
		}*/

		//else colide = 0;

	}

	

};