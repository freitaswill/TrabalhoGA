#pragma once
#include "Personagem.h"
#include "Mago.h"
#include "Guerreiro.h"
#include "Thief.h"

class GenManager 
{
public:
	GenManager();
	~GenManager();

	void escolhePersonagem(int escolha);
	void trocaPersonagem();
	int getAtual();
	Personagem *getPersonagem();

private:

	void definePersonagem(Personagem *p);
	Personagem *personagem = new Personagem; //new personagem
	int atual;
};

