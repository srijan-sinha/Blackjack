#ifndef MARKOV_H
#define MARKOV_H

#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Game {
	
	private:

		double p;					// Probability of a face card taken as input
		int ** VMatrix;				// Calculated reward for the state corresponding to the action in actionMatrix
		int ** actionMatrix;		// Action to be taken in a state represented as: 1 -> Hit 2 -> Stand 3 -> Double 4 -> Split
		double *** transProb;		// Probability of transition between two states.

		void initVMatrix();
		void initActionMatrix();
		void initTransProb();
		double calcTransProb(int stateInitial, int action, int stateFinal);
		int calcStandingReward(int state);

	public:

		Game();
		Game(double pFace);
		void fillVMatrix();
		void fillTransProb();

};

#endif

/**
states
0-14  	-> 	5-19
15-22 	-> 	A2-A9
23-30	->	22-99
31 		->	10-10
32		->	A-A
33		->	A10 = Blackjack
34		->	20
35		->	21
36		-> 	Busted	
**/	