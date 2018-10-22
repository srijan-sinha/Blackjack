#include "Markov.h"

Game::Game () {

}

Game::Game (double pFace) {
	
	p = pFace;

	initVMatrix();
	initActionMatrix();
	initTransProb();

}

void initVMatrix () {

	int ** tempVMatrix  = new int*[37];

	for (int = 0; i < 37; i++) {
		tempVMatrix[i] = new int[10];
	}

	for (int i = 0; i < 37; i++) {
		for(int j = 0; j < 10; j++) {
			tempVMatrix[i][j] = std::numeric_limits<int>::min();
		}
	}

	VMatrix = tempVMatrix;

}

void initActionMatrix () {

	int ** tempActionMatrix  = new int*[37];

	for (int = 0; i < 37; i++) {
		tempActionMatrix[i] = new int[10];
	}

	for (int i = 0; i < 37; i++) {
		for (int j = 0; j < 10; j++) {
			tempActionMatrix[i][j] = 0;
		}
	}

	actionMatrix = tempActionMatrix;

}

void initTransProb () {
	
	double *** tempTransProb = new double*[37];

	for (int i = 0; i < 37; i++) {
		tempTransProb[i] = new double**[10];
	}

	for (int i = 0; i < 37; i++) {
		for (int j = 0; j < 10; j++) {
			tempTransProb[i][j] = new double*[37];
		}
	}

	for (int i = 0; i < 37; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 37; k++) {
				tempTransProb[i][j][k] = 0;
			}
		}
	}

	transProb = tempTransProb;

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
		if (initialState == 0) {

		}
		else if (initialState == 1) {
			
		}
		else if (initialState == 2) {
			
		}
		else if (initialState == 3) {
			
		}
		else if (initialState == 4) {
			
		}
		else if (initialState == 5) {
			
		}
		else if (initialState == 6) {
			
		}
		else if (initialState == 7) {
			
		}
		else if (initialState == 8) {
			
		}
		else if (initialState == 9) {
			
		}
		else if (initialState == 10) {
			
		}
		else if (initialState == 11) {
			
		}
		else if (initialState == 12) {
			
		}
		else if (initialState == 13) {
			
		}
		else if (initialState == 14) {
			
		}
		else if (initialState == 15) {
			
		}
		else if (initialState == 16) {
			
		}
		else if (initialState == 17) {
			
		}
		else if (initialState == 18) {
			
		}
		else if (initialState == 19) {
			
		}
		else if (initialState == 20) {
			
		}
		else if (initialState == 21) {
			
		}
		else if (initialState == 22) {
			
		}
		else if (initialState == 23) {
			
		}
		else if (initialState == 24) {
			
		}
		else if (initialState == 25) {
			
		}
		else if (initialState == 26) {
			
		}
		else if (initialState == 27) {
			
		}
		else if (initialState == 28) {
			
		}
		else if (initialState == 29) {
			
		}
		else if (initialState == 30) {
			
		}
		else if (initialState == 31) {
			
		}
		else if (initialState == 32) {
			
		}
		else if (initialState == 33) {
			
		}
		else if (initialState == 34) {
			
		}
		else if (initialState == 35) {
			
		}
		else if (initialState == 36) {
			
		}
		
	}

}

int Game::calcStandingReward (int state) {

}

void Game::fillVMatrix () {

}

void Game::fillTransProb () {

}