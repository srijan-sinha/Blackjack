#ifndef MARKOV_H
#define MARKOV_H

#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

class Game {
	
	private:

		double p;
		int ** VMatrix;
		string ** actionMatrix;
		int **** transProb;

		initVMatrix();
		initActionMatrix();
		initTransProb();
		double calcTransProb(int stateInitial, string action, int stateFinal);
		int calcStandingReward(int state);

	public:

		Game();
		Game(double p);
		void fillVMatrix();
		void fillTransProb();
		
};

#endif