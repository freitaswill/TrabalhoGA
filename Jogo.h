#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "GenManager.h"
#include "monster.h"


using namespace std;

enum Tela { tJogo, tMenu, tPersonagem, sair, tGameOver };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

protected:
	GenManager *manager = new GenManager();
	Tela telaAtual;
	Sprite fundoJogo, fundoJogo1, fundoJogo2, fundoMenu, fundoPersonagem, fundoGameOver;
	BotaoSprite bJogar, bSair, bMago, bGuerreiro, bLadrao;
	void telaJogo();
	void telaMenu();
	void telaGameOver();
	void telaPersonagem();
	Texto textoPontos, textoVidas;
	int pontos = 0;
	int nVidas = 3;

	int spawnar;
	monster monsters[9];
};

