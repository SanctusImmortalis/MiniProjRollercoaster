/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

 #include <cstdio>
 #include <unistd.h>

#include "include/Carro.h"

int Carro::capacidade = 0;

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

	this->estado = 1;

	fprintf(stderr, "Carro cheio. Comecando volta.\n");
}

void Carro::daUmaVolta() {
  fprintf(stderr, "Dando uma volta\n");
	//std::cerr << "Dando uma volta" << std::endl;

	sleep(2);
  fprintf(stderr, "A volta acabou\n");
	//std::cerr << "A volta acabou" << std::endl;

	this->estado = 2;
}

void Carro::esperaEsvaziar() {
  fprintf(stderr, "Esperando esvaziar\n");
	//std::cerr << "Esperando esvaziar" << std::endl;

	while(this->nPassageiros > 0) ;

  fprintf(stderr, "Carro vazio. Esperando entrada.\n");
	//std::cerr << "Carro vazio. Esperando entrada." << std::endl;

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

		daUmaVolta();

		esperaEsvaziar();

		voltas++;
	}
}
