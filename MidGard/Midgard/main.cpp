#include <iostream>
#include "BitVector.h"
#include "Population.h"
#include "Evolution.h"
using namespace std;

int main() {

	Population* myPop = new Population(50, true);

	Evolution* evolution = new Evolution();

	// Evolve our population until we reach an optimum solution
	int generationCount = 0;
	while (generationCount < 300)
	{
		generationCount++;
		cout << "Generation: " << generationCount << " Fittest: " << myPop->getFittest().getFitness() << endl;
		*myPop = evolution->evolvePopulation(*myPop);

	}
	cout << "Solution found!" << endl;
	cout << "Generation: " << generationCount << endl;
	cout << "Genes:" << endl;
	cout << myPop->getFittest().getFitness() << endl;

	return 0;

}

