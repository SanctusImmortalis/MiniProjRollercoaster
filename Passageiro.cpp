/*
 * Passageiro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

 #include <iostream>
 #include <unistd.h>

#include "include/Passageiro.h"
#include "include/Sincronizador.h"
#include <random>

#define MAX_NUM_VOLTAS 100

int Passageiro::currentTicket = 1;
int Passageiro::nextToEnter = 1; //Proximo a entrar no carro
int Passageiro::saidaDoParque = 1;
int Passageiro::nextToLeave = 1; //Proximo a sair do parque

Passageiro::Passageiro(Carro &c, int n) : carro(c), numero(n), ticket(0) {
}

Passageiro::~Passageiro() {
}

void Passageiro::entraNoCarro() {
	this->ticket = Sincronizador::FetchAndAdd(Passageiro::currentTicket, 1);

	while((ticket < Passageiro::nextToEnter) || (carro.getEstado()!=0) || (carro.getNumPassageiros() >= carro.getCapacidade())) ;

	std::cerr << "O passageiro de id " << this->numero << " entrou no carro com ficha " << this->ticket << std::endl;
	carro.entradaNoCarro();

	Passageiro::nextToEnter++;
}

void Passageiro::esperaVoltaAcabar() {
	while(carro.getEstado()!=2) ;

	std::cerr << "Passageiro " << numero << " espera a volta acabar." << std::endl;
}

void Passageiro::saiDoCarro() {
	carro.saidaDoCarro();

	std::cerr << "O passageiro " <<numero<< " saiu do carro." << std::endl;
}

void Passageiro::passeiaPeloParque() {
	int n = rand() % 30;

	std::cerr << "O passageiro de id " << this->numero << " vai passear por " << n << " segundos." << std::endl;

	sleep(n);
}

bool Passageiro::parqueFechado() {
	if (carro.getNVoltas() <= MAX_NUM_VOLTAS)
		return false;

	return true;
}

void Passageiro::run() {
	srand(this->numero);
	while (!parqueFechado()) {
		entraNoCarro(); // protocolo de entrada

		esperaVoltaAcabar();

		saiDoCarro(); // protocolo de saida

		passeiaPeloParque(); // secao nao critica
	}

	this->ticket = 0;

	this->ticket = Sincronizador::FetchAndAdd(Passageiro::saidaDoParque, 1);
	while(this->ticket > Passageiro::nextToLeave) ;

	carro.getParque().setNumPassageiros(carro.getParque().getNumPassageiros() - 1);

	Passageiro::nextToLeave++;

}
