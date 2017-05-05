/*
 * Passageiro.h
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#ifndef PASSAGEIRO_H_
#define PASSAGEIRO_H_

#include "Thread.h"
#include "Carro.h"

class Passageiro: public Thread {
public:
	Passageiro(Carro &c, int n);
	virtual ~Passageiro();
	void entraNoCarro();
	void esperaVoltaAcabar();
	void saiDoCarro();
	void passeiaPeloParque();
	bool parqueFechado();

	void run();
private:
	Carro &carro;
	int numero;
	int ticket;

	static int currentTicket;
	static int nextToEnter;
	static int saidaDoParque;
	static int nextToLeave;
};

#endif /* PASSAGEIRO_H_ */
