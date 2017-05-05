#include <iostream>
#include <unistd.h>

#include "include/Carro.h"
#include "include/Parque.h"
#include "include/Passageiro.h"
#include "include/Sincronizador.h"
#include "include/Thread.h"

#define NUM_THREADS 50

using namespace std;

int main() {

	Parque park(NUM_THREADS);

	Carro car(park);

	Passageiro * passengers[NUM_THREADS];

	for(int i = 0;i<NUM_THREADS;i++){
		passengers[i] = new Passageiro(car, i+1);
	}

	car.start();

	for(int i = 0;i<NUM_THREADS;i++){
		passengers[i]->start();
	}

	car.join();

	for(int i = 0;i<NUM_THREADS;i++){
		delete passengers[i];
	}


	return 0;
}
