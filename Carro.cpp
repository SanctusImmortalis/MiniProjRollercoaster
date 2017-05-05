/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

 #include <iostream>
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
	std::cerr << "Esperando carro encher." << std::endl;

	while(this->nPassageiros < Carro::capacidade) ;

	this->estado = 1;

	std::cerr << "Carro cheio. Comecando volta." << std::endl;
}

void Carro::daUmaVolta() {
	std::cerr << "Dando uma volta" << std::endl;

	sleep(5);

	std::cerr << "A volta acabou" << std::endl;

	this->estado = 2;
}

void Carro::esperaEsvaziar() {
	std::cerr << "Esperando esvaziar" << std::endl;

	while(this->nPassageiros > 0) ;

	std::cerr << "Carro vazio. Esperando entrada." << std::endl;

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
