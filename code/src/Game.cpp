#include "Markov.h"

Game::Game () {

}

Game::Game (double pFace) {
	
	p = pFace;

	initVMatrix();
	initActionMatrix();
	initTransProb();
	initStateProb();

}

void Game::initVMatrix () {

	int ** tempVMatrix  = new int*[38];

	for (int = 0; i < 38; i++) {
		tempVMatrix[i] = new int[10];
	}

	for (int i = 0; i < 38; i++) {
		for(int j = 0; j < 10; j++) {
			tempVMatrix[i][j] = std::numeric_limits<int>::min();
		}
	}

	VMatrix = tempVMatrix;

}

void Game::initActionMatrix () {

	int ** tempActionMatrix  = new int*[38];

	for (int = 0; i < 38; i++) {
		tempActionMatrix[i] = new int[10];
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			tempActionMatrix[i][j] = 0;
		}
	}

	actionMatrix = tempActionMatrix;

}

void Game::initTransProb () {
	
	double *** tempTransProb = new double**[38];

	for (int i = 0; i < 38; i++) {
		tempTransProb[i] = new double*[10];
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			tempTransProb[i][j] = new double[15];
		}
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			for (int k = 0; k < 15; k++) {
				tempTransProb[i][j][k] = 0;
			}
		}
	}

	transProb = tempTransProb;

}

void initStateProb () {

	int ** tempStateProb  = new int*[10];

	for (int = 0; i < 10; i++) {
		tempStateProb[i] = new int[38];
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 38; j++) {
			tempStateProb[i][j] = 0;
		}
	}

	dealerStateProb = tempStateProb;

}

double Game::calcTransProb (int stateInitial, int action, int stateFinal) {

	double prob = 0;

	if (action == 2)
		if (stateInitial == stateFinal)
			prob = 1;
		else
			prob = 0;
	else if (action == 4) {
		if (stateInitial < 23)
			prob = 0;
		else if (stateInitial == 23) {
			if (stateFinal < 7 || stateFinal == 15 || stateFinal == 23)
				prob = (1 - p)/9;
			else if (stateFinal == 7)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 24) {
			if (stateFinal == 0 || (stateFinal > 1 && stateFinal < 8) || stateFinal == 24 || stateFinal == 16)
				prob = (1 - p)/9;
			else if (stateFinal == 8)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 25) {
			if ((stateFinal > 0 && stateFinal < 3) || (stateFinal > 3 && stateFinal < 9) || stateFinal == 25 || stateFinal == 17)
				prob = (1 - p)/9;
			else if (stateFinal == 9)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 26) {
			if ((stateFinal > 1 && stateFinal < 5) || (stateFinal > 5 && stateFinal < 10) || stateFinal == 26 || stateFinal == 18)
				prob = (1 - p)/9;
			else if (stateFinal == 10)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 27) {
			if ((stateFinal > 2 && stateFinal < 7) || (stateFinal > 7 && stateFinal < 11) || stateFinal == 27 || stateFinal == 19)
				prob = (1 - p)/9;
			else if (stateFinal == 11)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 28) {
			if ((stateFinal > 3 && stateFinal < 9) || (stateFinal > 9 && stateFinal < 12) || stateFinal == 28 || stateFinal == 20)
				prob = (1 - p)/9;
			else if (stateFinal == 12)
				prob = p;
			else
				prob = 0;	
		}
		else if (stateInitial == 29) {
			if ((stateFinal > 4 && stateFinal < 11) || (stateFinal == 12) || stateFinal == 29 || stateFinal == 21)
				prob = (1 - p)/9;
			else if (stateFinal == 13)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 30) {
			if ((stateFinal > 5 && stateFinal < 13) || stateFinal == 30 || stateFinal == 22)
				prob = (1 - p)/9;
			else if (stateFinal == 14)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 31) {
			if ((stateFinal > 6 && stateFinal < 15) || stateFinal == 33)
				prob = (1 - p)/9;
			else if (stateFinal == 31)
				prob = p;
			else
				prob = 0;
		}
		else if (stateInitial == 32) {
			if ((stateFinal > 7 && stateFinal < 20) || stateFinal == 34 || stateFinal == 32)
				prob = (1 - p)/9;
			else if (stateFinal == 35)
				prob = p;
			else
				prob = 0;
		}	
	}
	else {
		if (stateInitial >= 0 && stateInitial <= 5) {

			if (stateFinal >= stateInitial + 2 && stateFinal <= stateInitial + 9)
				prob =  (1 - p)/9;
			else if (stateFinal == stateInitial + 10)
				prob = p;

			if (stateInitial != 5)
				if (stateFinal == stateInitial + 15)
					prob = (1 - p)/9;
			else
				if (stateFinal == 37)
					prob = (1 - p)/9;
		}
		else if (stateInitial >= 6 && stateInitial <= 14) {
			if (stateFinal >= stateInitial + 1 && stateFinal <= stateInitial + 9)
				if (stateFinal <= 14) 
					prob = (1 - p)/9;
			else if (stateFinal == 34)
				prob = (1 - p)/9;
			else if (stateFinal == 35)
				if (stateInitial == 6)
					prob = p;
				else
					prob = (1 - p)/9;
			else if (stateFinal == 36) {
				if (stateInitial == 7)
					prob = p;
				else
					prob = p + (9 - (16 - stateInitial))*(1 - p)/9;
			}

		}
		else if (stateInitial >= 15 && stateInitial <= 22) {
			if (stateFinal >= stateInitial + 1 && (stateFinal <= 22 || stateFinal == 37))
				prob = (1 - p)/9;
			else if (stateFinal >= 7 && stateFinal <=stateInitial - 8)
				prob = (1 - p)/9;
			else if (stateFinal == stateInitial - 7)
				if(stateInitial != 22)
					prob = p;
			else if (stateFinal == 34 && stateInitial == 22)
				prob = p;
		}
		else if (initialState == 23) {
			if (stateFinal == 10)
				prob = (1 - p)/9;
			else if (stateFinal >= 1 && stateFinal <= 8)
				prob = (1 - p)/9;
			else if (stateFinal == 9)
				prob = p;
		}
		else if (stateInitial >= 24 && stateInitial <= 30) {
			calcTransProb (2*(stateInitial - 21) - 5, action, stateFinal);
		}
		else if (initialState == 31) {
			if (stateFinal == 35)
				prob = (1 - p)/9;
			else if (stateFinal == 36)
				prob = 8*(1 - p)/9 + p;
		}
		else if (initialState == 32) {
			if (stateFinal >= 15 && stateFinal <= 22)
				prob = (1 - p)/9;
			else if (stateFinal == 37)
				prob = (1 - p)/9;
			else if (stateFinal == 7)
				prob = p;
		}
		else if (initialState == 33) {
			if (stateFinal == 35)
				prob = p;
			else if (stateFinal >= 7 && stateFinal <= 14)
				prob = (1 - p)/9;
			else if (stateFinal == 34)
				prob = (1 - p)/9;
		}
		else if (initialState == 34) {
			if (stateFinal == 35)
				prob = (1 - p)/9;
			else if (stateFinal == 36)
				prob = 8*(1 - p)/9 + p;
		}
		else if (initialState == 35) {
			if (stateFinal == 36)
				prob = 1;
		}
		else if (stateInitial == 36) {
			if (stateFinal == stateInital)
				prob = 1;
		}
		else if (stateInitial == 37) {
			if (stateFinal == 35)
				prob = p;
			else if (stateFinal >= 7 && stateFinal <= 14)
				prob = (1 - p)/9;
			else if (stateFinal == 34)
				prob = (1 - p)/9;
		}
		
	}

	return prob;

}

double Game::calcStateProb (int stateHidden, int stateShown) {

	double prob = 0;

	if (stateHidden < 8) { // up card 2-9
		if (stateShown >= stateHidden - 1 && stateShown != 2*stateHidden - 1 && stateShown < stateHidden + 7) // 2-9 and not the same card again and less than 9
			prob = (1 - p)/9;
		else if (stateShown == stateHidden + 7) //face card
			prob = p;
		else if (stateShown == stateHidden + 15 || stateShown == stateHidden + 23) // 15 for ace and 23 for pair
			prob = (1 - p)/9;
		else
			prob = 0;
	}
	else if (stateHidden == 8) { // up card 10
		if (stateShown >= stateHidden - 1 && stateShown != 2*stateHidden - 1 && stateShown < stateHidden + 7)
			prob = (1 - p)/9;
		else if (stateShown == 31) // pair
			prob = p;
		else if (stateShown == 33) // blackjack
			prob = (1 - p)/9;
		else
			prob = 0;
	}
	else if (stateHidden == 9) { // ace
		if (stateShown >= 15 && stateShown <= 22) // 2-9
			prob = (1 - p)/9;
		else if (stateShown == 32) // pair
			prob = (1 - p)/9;
		else if (satteShown == 33) // blackjack
			prob = p;
		else
			prob = 0;
	}

	return prob;

}

double Game::calcFinalState (int dealerStateInitial, int dealerStateFinal) {

	double prob = 0;

	if (valueHand(dealerStateInitial) >= 17) {
		if(dealerStateInitial == dealerStateFinal)
			prob = 1;
		else
			prob = 0;
	}
	else {
		if(valueHand(dealerStateFinal) < 17)
			prob = 0;
		else {
			//dealerStateInitial is less than 17 
		}
	}

}

double Game::calcFinalScore (int dealerStateInitial, int handValue) { //does not quite feel good as we can not represent dealer final state by the same state denotion system

	double prob = 0;

	if (handValue < 17)
		prob = 0;
	else if (handValue <= 19) {
		prob += calcFinalState (dealerStateInitial, handValue - 5);
		prob += calcFinalState (dealerStateInitial, handValue + 2);
		
		if (handValue == 18)
			prob += calcFinalState (dealerStateInitial, 30)
	
	}
	else if (handValue == 20) { // not right as 9 4 7
		prob += calcFinalState (dealerStateInitial, 34);
		prob += calcFinalState (dealerStateInitial, 22);
		prob += calcFinalState (dealerStateInitial, 31);
	}
	else if (handValue == 21) {
		prob += calcFinalState (dealerStateInitial, 33);
		prob += calcFinalState (dealerStateInitial, 35);
		prob += calcFinalState (dealerStateInitial, 37);
	}
	else if (handValue == 22) {
		prob += calcFinalState (dealerStateInitial, 36);
	}
	
	return prob;

}

double Game::probScore (int dealerStateHidden, int handValue) {

	double prob = 0;

	for(int i = 0; i < 38; i++) {
		prob += calcStateProb (dealerStateHidden, i) * calcFinalScore (i, handValue);
	}

	return prob;

}

int Game::calcStandingReward (int statePlayer, int stateDealer) {

	double reward = 0;

	int playerHand = valueHand(statePlayer);
	
	if (playerHand != 21) {
	
		for (int i = playerHand + 1; i <= 21; i++) {
			reward -= probScore(stateDealer, i);
		}

		for(int i = 0; i < playerHand; i++) {
			reward += probScore(stateDealer, i);
		}
	
	}

	else {

		if (statePlayer == 33) {

		}
		else {

		}

	}
}

int Game::valueHand (int state) {

	if (state <= 14)
		return state;
	else if (state <= 22)
		return state - 2;
	else if (state <= 31)
		return 2 * (state - 21);
	else if (state == 32)
		return 12;
	else if (state == 33)
		return 21;
	else if (state <= 35)
		return state - 14;
	else
		return 22;

}

void Game::fillTable () {

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			transProb[i][j][0] = calcTransProb (i, 1, j);
		}
	}

}

void Game::updateTable () {

	for (int step = 1; step < 14; step++) {
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 38; j++) {
				for (int k = 0; k < 38; k++) {
					if(valueHand(k) < 17) {
						transProb[i][j][step] += transProb[i][k][step-1] * calcTransProb(k, 1, j);
					}
				}
			}
		}
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			for (int k = 0; k < 14; k++) {
				transProb[i][j][14] += transProb[i][j][k];
			}
		}
	}

}

void Game::fillVMatrix () {

}

void Game::fillTransProb () {

}