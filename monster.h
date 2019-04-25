#pragma once
#include "libUnicornio.h"
#include <time.h>

class monster
{
public:
	monster();
	~monster();

	Sprite spr;

	void desenhar();
	void sortearSpawn();
	void caminhar();
	void setSprite() { spr.setSpriteSheet("Monster"); }
	Sprite getSprite() { return spr; }
	int getX() { return x; }
	int getY() { return y; }

	bool getVivo() { return vivo; }
	void setVivo(bool Vivo) { vivo = Vivo; }
	bool getChegou() { return chegouNoFim; }
	void setChegou(bool Chegou) { chegouNoFim = Chegou; }

protected:
	bool vivo = false;
	int x, y;
	int sorteio, chegouNoFim = false;
};

