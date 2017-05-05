/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Carro.h"
#include <iostream>

int Carro::capacidade = 0;;

Carro::Carro(Parque &p) : parque(p), estado(0) {
	this->voltas = 0;
	Carro::capacidade = p.getNumPassageiros() / 2;
	this->nPassageiros = 0;
}

Carro::~Carro() {
}

void Carro::esperaEncher() {
	std::cerr << "Esperando carro encher.\n";

	while(this->nPassageiros < Carro::capacidade) continue;
	
	this->estado = 1;

	std::cerr << "Carro cheio. Começando volta.\n";
}

void Carro::daUmaVolta() {
	std::cerr << "Dando uma volta\n";

	sleep(5);

	std::cerr << "A volta acabou\n";

	this->estado = 2;
}

void Carro::esperaEsvaziar() {
	std::cerr << "Esperando esvaziar\n";

	th
}

int Carro::getNVoltas() {
	return voltas;
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
