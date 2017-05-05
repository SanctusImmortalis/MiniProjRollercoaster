/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

 #include <iostream>
 #include <unistd.h>

#include "include/Carro.h"

int Carro::capacidade = 1;

Carro::Carro(Parque &p) : parque(p), estado(0) {
	this->voltas = 0;
	Carro::capacidade = p.getNumPassageiros() / 2;
	this->nPassageiros = 0;
}

Carro::~Carro() {
}

void Carro::esperaEncher() {
	fprintf(stderr, "Esperando carro encher.\n");

  while(this->nPassageiros < Carro::capacidade){
    if(parque.getNumPassageiros() < Carro::capacidade)
      Carro::capacidade = parque.getNumPassageiros();
  }

  	if(!Carro::capacidade) return;

	this->estado = 1;

	fprintf(stderr, "Carro cheio. Comecando volta.\n");
}

void Carro::daUmaVolta() {
	fprintf(stderr, "Dando uma volta\n");

	sleep(5);

	fprintf(stderr, "A volta acabou\n");

	this->estado = 2;
}

void Carro::esperaEsvaziar() {
	fprintf(stderr, "Esperando esvaziar\n");

	while(this->nPassageiros > 0) ;

	fprintf(stderr, "Carro vazio. Esperando entrada.\n");

	this->estado = 0;
}

int Carro::getNVoltas() {
	return voltas;
}

int Carro::getNumPassageiros() {
	return nPassageiros;
}

void Carro::entradaNoCarro() {
	nPassageiros++;
}

void Carro::saidaDoCarro() {
	nPassageiros--;
}

int Carro::getCapacidade() {
	return Carro::capacidade;
}

char Carro::getEstado() {
	return estado;
}

Parque &Carro::getParque() {
	return parque;
}

void Carro::run() {
	while (parque.getNumPassageiros() > 0) {
		esperaEncher();

		if(!Carro::capacidade) break;

		daUmaVolta();

		esperaEsvaziar();

		voltas++;
	}

  fprintf(stderr, "\nEl fin.\n\n");
}
