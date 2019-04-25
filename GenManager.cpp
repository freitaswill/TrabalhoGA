#include "GenManager.h"



GenManager::GenManager()
{
}


GenManager::~GenManager()
{
}

void GenManager::escolhePersonagem(int escolha)
{
	if (escolha == 1)
	{
		definePersonagem(new Mago);
		getPersonagem()->setSpritesheet("Mage");
		atual = 1;
	}
	
	if (escolha == 2)
	{
		definePersonagem(new Guerreiro);
		getPersonagem()->setSpritesheet("Knight");
		atual = 2;
	}

	if (escolha == 3)
	{
		definePersonagem(new Thief);
		getPersonagem()->setSpritesheet("Thief");
		atual = 3; 
	}
}

void GenManager::trocaPersonagem()
{
	if (atual != 1 && gTeclado.pressionou[TECLA_1])
	{
		definePersonagem(new Mago);
		getPersonagem()->setSpritesheet("Mage");
		getPersonagem()->inicializar(300, 300);
		atual = 1;
	}

	if (atual != 2 && gTeclado.pressionou[TECLA_2])
	{
		definePersonagem(new Guerreiro);
		getPersonagem()->setSpritesheet("Knight");
		getPersonagem()->inicializar(300, 300);
		atual = 2;
	}

	if (atual != 3 && gTeclado.pressionou[TECLA_3])
	{
		definePersonagem(new Thief);
		getPersonagem()->setSpritesheet("Thief");
		getPersonagem()->inicializar(300, 300);
		atual = 3;
	}

}


int GenManager::getAtual()
{
	return this->atual;
}

Personagem * GenManager::getPersonagem()
{
	return this->personagem;
}


void GenManager::definePersonagem(Personagem * p)
{
	this->personagem = p;
}
