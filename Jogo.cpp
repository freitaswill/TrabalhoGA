#include "Jogo.h"
#include <time.h>

Jogo::Jogo()
{
	
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	srand(time(0));

	uniInicializar(800, 600, false);
	
	gRecursos.carregarSpriteSheet("Mage", "assets/spritesheets/Mage.png", 4, 1);
	gRecursos.carregarSpriteSheet("Knight", "assets/spritesheets/Knight.png", 4, 1);
	gRecursos.carregarSpriteSheet("Thief", "assets/spritesheets/Thief.png", 4, 1);
	gRecursos.carregarSpriteSheet("Monster", "assets/spritesheets/Monster.png", 4, 1);
	gRecursos.carregarSpriteSheet("Path1", "assets/spritesheets/path1.png");
	gRecursos.carregarSpriteSheet("Knife", "assets/spritesheets/knife.png");
	gRecursos.carregarSpriteSheet("Spear", "assets/spritesheets/spear.png");
	gRecursos.carregarSpriteSheet("FireBall", "assets/spritesheets/Fire.png");

	//fundos
	gRecursos.carregarSpriteSheet("fundoMenu", "assets/fundos/fundoMenu.png");
	fundoMenu.setSpriteSheet("fundoMenu");
	gRecursos.carregarSpriteSheet("fundoPersonagens", "assets/fundos/fundoPersonagem.png");
	fundoPersonagem.setSpriteSheet("fundoPersonagens");
	gRecursos.carregarSpriteSheet("fundoJogo", "assets/spritesheets/path1.png");
	fundoJogo.setSpriteSheet("fundoJogo");
	gRecursos.carregarSpriteSheet("fundoJogo1", "assets/spritesheets/path2.png");
	fundoJogo1.setSpriteSheet("fundoJogo1");
	gRecursos.carregarSpriteSheet("fundoJogo2", "assets/spritesheets/path3.png");
	fundoJogo2.setSpriteSheet("fundoJogo2");
	gRecursos.carregarSpriteSheet("fundoGameOver", "assets/fundos/GameOver.png");
	fundoGameOver.setSpriteSheet("fundoGameOver");

	//botoes
	gRecursos.carregarSpriteSheet("botaoJogar", "assets/botoes/botaoJogar.png", 3);
	bJogar.setSpriteSheet("botaoJogar");
	bJogar.setPos(gJanela.getLargura() / 2, 360);
	
	gRecursos.carregarSpriteSheet("botaoSair", "assets/botoes/Sair.png", 3);
	bSair.setSpriteSheet("botaoSair");
	bSair.setPos(gJanela.getLargura() / 2, 440);

	gRecursos.carregarSpriteSheet("botaoGuerreiro", "assets/botoes/Guerreiro.png", 3);
	bGuerreiro.setSpriteSheet("botaoGuerreiro");
	bGuerreiro.setPos(150, 360);

	gRecursos.carregarSpriteSheet("botaoMago", "assets/botoes/botaoMago.png", 3);
	bMago.setSpriteSheet("botaoMago");
	bMago.setPos(gJanela.getLargura() / 2, 360);

	gRecursos.carregarSpriteSheet("botaoLadrao", "assets/botoes/botaoLadrao.png", 3);
	bLadrao.setSpriteSheet("botaoLadrao");
	bLadrao.setPos(650, 360);

	gRecursos.carregarFonte("PixelArt", "Fontes/pixelart.ttf", 18);
	textoPontos.setFonte("PixelArt");
	textoPontos.setCor(255, 255, 255);
	textoPontos.setAncora(0, 0.5);

	telaAtual = tMenu;

	for (int i = 0; i < 9; i++)
			monsters[i].setSprite();
	
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaAtual != sair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
		case tMenu: telaMenu();
			break;
		case tPersonagem: telaPersonagem();
			break;
		case tGameOver: telaGameOver();
			break;
		case tJogo: telaJogo();
		}		
		uniTerminarFrame();
	}
}

void Jogo::telaJogo()
{
	if (manager->getAtual() == 1)
	{
		fundoJogo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
	
	if (manager->getAtual() == 2)
	{
		fundoJogo1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}

	if (manager->getAtual() == 3)
	{
		fundoJogo2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		
	}

	manager->getPersonagem()->desenhar();
	manager->trocaPersonagem();
	manager->getPersonagem()->mover();
	manager->getPersonagem()->anima();
	manager->getPersonagem()->ataqueEspecial();

	for (int i = 0; i < 9; i++)
		if (monsters[i].getVivo() == false) 
		{
			spawnar = rand() % 300;
	if (spawnar == 30) {
		monsters[i].sortearSpawn();
		monsters[i].setVivo(true);
	}
		}

	for (int i = 0; i < 9; i++)
		if (monsters[i].getVivo())
			monsters[i].caminhar();

	for (int i = 0; i < 9; i++)
		if (monsters[i].getVivo())
		monsters[i].desenhar();

	for (int i = 0; i < 9; i++) {
		if (monsters[i].getChegou()) {
			monsters[i].setChegou(false);
			nVidas -= 1;
			if (nVidas <= 0)
				telaAtual = tGameOver;
		}
		if (uniTestarColisaoSpriteComSprite(monsters[i].getSprite(), monsters[i].getX(), monsters[i].getY(), 0, manager->getPersonagem()->getSpriteAtq(), manager->getPersonagem()->getXAtaque(), manager->getPersonagem()->getYAtaque(), 0) && manager->getPersonagem()->getAtacando()) {
			monsters[i].setVivo(false);
			manager->getPersonagem()->setAtacando(false);
			pontos += 5;
		}
	}

	textoPontos.setString("Pontos " + to_string(pontos));
	textoPontos.desenhar(50, 40);

	textoPontos.setString("Vidas " + to_string(nVidas));
	textoPontos.desenhar(250, 40);

}

void Jogo::telaMenu()
{
	gMouse.mostrarCursor();
	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	
	bJogar.atualizar();
	bJogar.desenhar();
	if (bJogar.estaClicado())
	{
		telaAtual = tPersonagem;
	}

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		telaAtual = sair;
	}
}

void Jogo::telaGameOver()
{
	gMouse.mostrarCursor();
	fundoGameOver.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		telaAtual = sair;
	}
}

void Jogo::telaPersonagem()
{
	gMouse.mostrarCursor();
	fundoPersonagem.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bMago.atualizar();
	bMago.desenhar();
	if (bMago.estaClicado())
	{
		telaAtual = tJogo;
		manager->escolhePersonagem(1);
		manager->getPersonagem()->inicializar(200, 200);
	}

	bGuerreiro.atualizar();
	bGuerreiro.desenhar();
	if (bGuerreiro.estaClicado())
	{
		telaAtual = tJogo;
		manager->escolhePersonagem(2);
		manager->getPersonagem()->inicializar(200, 200);
	}

	bLadrao.atualizar();
	bLadrao.desenhar();
	if (bLadrao.estaClicado())
	{
		telaAtual = tJogo;
		manager->escolhePersonagem(3);
		manager->getPersonagem()->inicializar(200, 200);
	}
}
