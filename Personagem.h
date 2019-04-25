#pragma once
#include"libUnicornio.h"

class Personagem 
{
public:
	Personagem();
	~Personagem();
	void mover();
	void anima();
	void setSpritesheet(string nome);
	void desenhar();
	void inicializar(int xInicial, int yInicial);
	void ataqueEspecial();
	Sprite getSprite();
	Sprite getSpriteAtq() { return ataque; }
	Sprite ataque;
	Som som;
	int getX();
	int getY();
	int getXAtaque() { return xAtaque; }
	int getYAtaque() { return yAtaque; }
	bool getAtacando() { return atacando; }
	void setAtacando(bool Atacando) { atacando = Atacando; }


protected:
	bool atacando = false;
	int x, y, xAtaque, yAtaque,vel = 2;
	int indiceRotacao = 1, indiceRotacaoAux = 1, rotacao = 0;
	Sprite spriteSheet;
};

