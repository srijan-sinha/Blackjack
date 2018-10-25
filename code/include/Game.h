#ifndef MARKOV_H
#define MARKOV_H

#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Game {
	
	public:

		double p;					// Probability of a face card taken as input.
		int ** VMatrix;				// Calculated reward for the state corresponding to the action in actionMatrix.
		int ** actionMatrix;		// Action to be taken in a state represented as: 1 -> Hit 2 -> Stand 3 -> Double 4 -> Split.
		double *** transProb;		// Probability of transition between two states.
		double ** dealerStateProb;	// Probability matrix which gives the probability of the dealer ending up in one of the 37 states given the initial state (out of the 10 possible).

		void initVMatrix();			//checked
		void initActionMatrix();	//checked
		void initTransProb();		//checked
		void initStateProb();		//checked
		double calcTransProb(int stateInitial, int action, int stateFinal);		//nocheck			// Transition probability from one state to another based on the action carried out.
		double calcStateProb(int stateHidden, int stateShown);					//checked			// Probability that dealer gets the mentioned full state (both cards known) from the partial state (only one card known).
		double calcFinalState(int dealerStateInitial, int dealerStateFinal);	//nocheck			// Probability that after dealer stands he reaches the dealerStateFinal from dealerStateInitial (both cards known).
		double calcFinalScore(int dealerStateInitial, int handValue);			//nocheck			// Probability that dealer starting in given fully know state ends up with given hand value.
		double probScore(int dealerStateHidden, int handValue);					//nocheck			// Probability that dealer starting in given partially hidden state ends up with given hand value.
		double calcStandingReward(int statePlayer, int stateDealer);			//nocheck			// Expected reward obtained by the player if he stands in a given stand.
		int valueHand(int state);												//nocheck			// Value of the current hand.
		void fillTable();														//nocheck			// 
		void updateTable();														//nocheck			//
		void printTable();														//checked			//

	// public:

		Game();
		Game(double pFace);
		void fillVMatrix();														//nocheck
		void updateVMatrix();													//nocheck
		void valueIteration(int times);											//nocheck
		string numToAction(int action);											//checked
		void printAction();														//checked

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
37		-> A10 Non Blackjack
*/	

/**
dealer states
0-8		-> 2-10
9 		-> A
*/