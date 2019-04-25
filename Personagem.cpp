#include "Personagem.h"



Personagem::Personagem()
{

}


Personagem::~Personagem()
{
}

void Personagem::mover()
{
	if (gTeclado.segurando[TECLA_W]) 
	{
		y -= 1 * vel;
	}

	if (gTeclado.segurando[TECLA_S]) 
	{
		y += 1 * vel;
	}

	if (gTeclado.segurando[TECLA_D])
	{
		x += 1 * vel;
	}

	if (gTeclado.segurando[TECLA_A])
	{
		x -= 1 * vel;
	}
}

void Personagem::anima()
{

	if (gTeclado.segurando[TECLA_W]) 
	{
		spriteSheet.setAnimacao(3);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 3;
	}

	if (gTeclado.segurando[TECLA_S])
	{
		spriteSheet.setAnimacao(0);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 1;
	}

	if (gTeclado.segurando[TECLA_D])
	{
		spriteSheet.setAnimacao(2);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 0;
	}

	if (gTeclado.segurando[TECLA_A])
	{
		spriteSheet.setAnimacao(1);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 2;
	}
}

void Personagem::setSpritesheet(string nome)
{
	spriteSheet.setSpriteSheet(nome);
}

void Personagem::desenhar()
{
	spriteSheet.desenhar(x,y);
}

void Personagem::inicializar(int xInicial, int yInicial)
{
	x = xInicial;
	y = yInicial;
}

void Personagem::ataqueEspecial()
{
	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		atacando = true;
	}

	if (atacando == true)
	{
		if (indiceRotacaoAux == 0)
		{
			xAtaque += 3;
		}
		else if (indiceRotacaoAux == 2)
		{
			xAtaque -= 3;
		}
		else if (indiceRotacaoAux == 1)
		{
			yAtaque += 3;
		}
		else if (indiceRotacaoAux == 3)
		{
			yAtaque -= 3;
		}
		ataque.desenhar(xAtaque, yAtaque, indiceRotacaoAux * 90);

		if (xAtaque > gJanela.getLargura() || xAtaque <= 0 || yAtaque > gJanela.getAltura() || yAtaque <= 0)
		{
			atacando = false;
		}
	}
	else
	{
		indiceRotacaoAux = indiceRotacao;
		xAtaque = x;
		yAtaque = y;
	}
}

Sprite Personagem::getSprite()
{
	return spriteSheet;
}

int Personagem::getX()
{
	return x;
}

int Personagem::getY()
{
	return y;
}






