#include "monster.h"


monster::monster()
{
}


monster::~monster()
{
}

void monster::desenhar()
{
	spr.setAnimacao(2);
	spr.desenhar(x, y);
	if (x >= 850) {
		vivo = false;
		chegouNoFim = true;
	}
}

void monster::sortearSpawn()
{
	
	this->x = -50;
	sorteio = rand() % 600;
	this->y = sorteio;
}

void monster::caminhar()
{
	x++;
}
