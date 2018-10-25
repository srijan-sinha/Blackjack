#include "Game.h"

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

	double ** tempVMatrix  = new double*[38];

	for (int i= 0; i < 38; i++) {
		tempVMatrix[i] = new double[10];
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			tempVMatrix[i][j] = -10000;
		}
	}

	VMatrix = tempVMatrix;

}

void Game::initActionMatrix () {

	int ** tempActionMatrix  = new int*[38];

	for (int i= 0; i < 38; i++) {
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
		tempTransProb[i] = new double*[38];
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			tempTransProb[i][j] = new double[16];
		}
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			for (int k = 0; k < 16; k++) {
				tempTransProb[i][j][k] = 0;
			}
		}
	}

	transProb = tempTransProb;

}

void Game::initStateProb () {

	double ** tempStateProb  = new double*[10];

	for (int i= 0; i < 10; i++) {
		tempStateProb[i] = new double[38];
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

	if (action == 2) {
		if (stateInitial == stateFinal)
			prob = 1;
		else
			prob = 0;
	}
	else if (action == 4) {
		if (stateInitial < 23) {
			prob = 0;
		}
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
			if ((stateFinal > 14 && stateFinal < 23) || stateFinal == 32)
				prob = (1 - p)/9;
			else if (stateFinal == 37)
				prob = p;
			else
				prob = 0;
		}	
	}
	else {
		if (stateInitial >= 0 && stateInitial <= 5) {

			if (stateFinal >= stateInitial + 2 && stateFinal <= stateInitial + 9) {
				prob =  (1 - p)/9;
			}
			else if (stateFinal == stateInitial + 10) {
				if (stateInitial <= 4)
					prob = p;
			}
			else if (stateFinal == 34 && stateInitial == 5) {
				prob = p;
			}

			if (stateInitial != 5) {
				if (stateFinal == stateInitial + 18)
					prob = (1 - p)/9;
			}
			else {
				if (stateFinal == 37)
					prob = (1 - p)/9;
			}
		}
		else if (stateInitial >= 6 && stateInitial <= 14) {
			if (stateFinal >= stateInitial + 1 && stateFinal <= stateInitial + 9) {
				if (stateFinal <= 14) 
					prob = (1 - p)/9;
			}
			else if (stateFinal == 34)
				prob = (1 - p)/9;
			else if (stateFinal == 35) {
				if (stateInitial == 6)
					prob = p;
				else
					prob = (1 - p)/9;
			}
			else if (stateFinal == 36) {
				if (stateInitial == 7)
					prob = p;
				else if (stateInitial >= 7)
					prob = p + (9 - (16 - stateInitial))*(1 - p)/9;
			}

		}
		else if (stateInitial >= 15 && stateInitial <= 22) {
			if (stateFinal >= stateInitial + 1 && (stateFinal <= 22 || stateFinal == 37))
				prob = (1 - p)/9;
			else if (stateFinal >= 7 && stateFinal <=stateInitial - 8)
				prob = (1 - p)/9;
			else if (stateFinal == stateInitial - 7) {
				if(stateInitial != 22)
					prob = p;
			}
			else if (stateFinal == 34 && stateInitial == 22)
				prob = p;
		}
		else if (stateInitial == 23) {
			if (stateFinal == 17)
				prob = (1 - p)/9;
			else if (stateFinal >= 1 && stateFinal <= 8)
				prob = (1 - p)/9;
			else if (stateFinal == 9)
				prob = p;
		}
		else if (stateInitial >= 24 && stateInitial <= 30) {
			prob = calcTransProb (2*(stateInitial - 21) - 5, action, stateFinal);
		}
		else if (stateInitial == 31) {
			if (stateFinal == 35)
				prob = (1 - p)/9;
			else if (stateFinal == 36)
				prob = 8*(1 - p)/9 + p;
		}
		else if (stateInitial == 32) {
			if (stateFinal >= 15 && stateFinal <= 22)
				prob = (1 - p)/9;
			else if (stateFinal == 37)
				prob = (1 - p)/9;
			else if (stateFinal == 7)
				prob = p;
		}
		else if (stateInitial == 33) {
			if (stateFinal == 35)
				prob = p;
			else if (stateFinal >= 7 && stateFinal <= 14)
				prob = (1 - p)/9;
			else if (stateFinal == 34)
				prob = (1 - p)/9;
		}
		else if (stateInitial == 34) {
			if (stateFinal == 35)
				prob = (1 - p)/9;
			else if (stateFinal == 36)
				prob = 8*(1 - p)/9 + p;
		}
		else if (stateInitial == 35) {
			if (stateFinal == 36)
				prob = 1;
		}
		else if (stateInitial == 36) {
			if (stateFinal == stateInitial)
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
		// cout << "In if" << endl;
		if (stateShown >= stateHidden - 1 && stateShown != 2*stateHidden - 1 && stateShown < stateHidden + 7) { // 2-9 and not the same card again and less than 9
			prob = (1 - p)/9;
			// cout << "\t In if" << endl;
		}
		else if (stateShown == stateHidden + 7) { //face card
			prob = p;
			// cout << "\t In else if 1" << endl;
		}
		else if (stateShown == stateHidden + 15 || stateShown == stateHidden + 23) { // 15 for ace and 23 for pair
			prob = (1 - p)/9;
			// cout << "\t In else if 2" << endl;
		}
		else {
			prob = 0;
			// cout << "\t In else" << endl;
		}
	}
	else if (stateHidden == 8) { // up card 10
		// cout << "In else if 1" << endl;
		if (stateShown >= stateHidden - 1 && stateShown != 2*stateHidden - 1 && stateShown < stateHidden + 7) {
			prob = (1 - p)/9;
			// cout << "\t In if" << endl;
		}
		else if (stateShown == 31) { // pair
			prob = p;
			// cout << "\t In else if 1" << endl;
		}
		else if (stateShown == 33) { // blackjack
			prob = (1 - p)/9;
			// cout << "\t In else if 2" << endl;
		}
		else {
			prob = 0;
			// cout << "\t In else" << endl;
		}
	}
	else if (stateHidden == 9) { // ace
		// cout << "In else if 2" << endl;
		if (stateShown >= 15 && stateShown <= 22) { // 2-9
			prob = (1 - p)/9;
			// cout << "\t In if" << endl;
		}
		else if (stateShown == 32) { // pair
			prob = (1 - p)/9;
			// cout << "\t In else if 1" << endl;
		}
		else if (stateShown == 33) { // blackjack
			prob = p;
			// cout << "\t In else if 2" << endl;
		}
		else {
			prob = 0;
			// cout << "\t In else" << endl;
		}
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
			prob = transProb[dealerStateInitial][dealerStateFinal][15]; 
		}
	}

	return prob;

}

double Game::calcFinalScore (int dealerStateInitial, int handValue) { //does not quite feel good as we can not represent dealer final state by the same state denotion system

	double prob = 0;

	if (handValue < 17)
		prob = 0;
	else if (handValue <= 19) {
		prob += calcFinalState (dealerStateInitial, handValue - 5);
		prob += calcFinalState (dealerStateInitial, handValue + 2);
		
		if (handValue == 18)
			prob += calcFinalState (dealerStateInitial, 30);
	
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

		// cout << "Prob update " << i << ": " << prob << "\t stateShown: " << i << " " << calcStateProb(dealerStateHidden, i) << "\t \t shownState to value: " << calcFinalScore (i, handValue) << endl;
	}

	return prob;

}

double Game::calcStandingReward (int statePlayer, int stateDealer) {

	double reward = 0;

	int playerHand = valueHand(statePlayer);
	// cout << "PlayerHand Value: " << playerHand << endl;
	if (playerHand == 22) {
		reward = -1;
	}
	else if (playerHand != 21) {
		
		for (int i = 0; i < playerHand; i++) {
			reward += probScore(stateDealer, i);
			// cout << "Reward update "<< i << ": " << reward << endl;
		}

		for (int i = playerHand + 1; i <= 21; i++) {
			reward -= probScore(stateDealer, i);
			// cout << "Reward update "<< i << ": " << reward << endl;
		}

		reward += probScore(stateDealer, 22);

	}
	else  {

		if (statePlayer == 33) {
			
			reward += calcStateProb(stateDealer, 33)*0;
		
			for (int i = 0; i < 33; i++) {
				reward += calcStateProb(stateDealer, i) * 1.5;
			}

			for (int i = 34; i < 38; i++) {
				reward += calcStateProb(stateDealer, i) * 1.5;
			}
		
		}
		else {

			reward -= calcStateProb(stateDealer, 33);
			for (int i = 0; i < 33; i++) {
				reward += calcStateProb(stateDealer, i);
			}

			for(int i = 34; i < 38; i++) {
				reward += calcStateProb(stateDealer, i);
			}

		}
	
	}
	return reward;
}

int Game::valueHand (int state) {

	if (state <= 14)
		return state + 5;
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
	else if (state == 36)
		return 22;
	else
		return 21;

}

void Game::fillTable () {

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 38; j++) {
			if (i == j)
				// transProb[i][j][0] = calcTransProb (i, 1, j);
				transProb[i][j][0] = 1;
			else
				transProb[i][j][0] = 0;
		}
	}

}

void Game::updateTable () {

	for (int step = 1; step < 15; step++) {
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
			for (int k = 1; k < 15; k++) {
				transProb[i][j][15] += transProb[i][j][k];
			}
		}
	}

}

void Game::fillVMatrix () {

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			VMatrix[i][j] = calcStandingReward(i, j);
		}
	}

	// cout << endl << endl << "***********************************************************" << endl << endl << endl << endl << endl;

	// for (int i = 0; i < 38; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		cout << VMatrix[i][j] << " \t";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			actionMatrix[i][j] = 2;
		}
	}

}

bool checkGreater(double d1, double d2) {
	if (d1 - d2 > 0.0001)
		return true;
	return false;
}

void Game::updateVMatrix () {

	double ** tempVMatrix = new double*[38];
	double rewardSplit = 0;
	double rewardStand = 0;
	double rewardHit = 0;
	double rewardDouble = 0;

	for (int i= 0; i < 38; i++) {
		tempVMatrix[i] = new double[10];
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			tempVMatrix[i][j] = -100000;
		}
	}

	// cout << tempVMatrix[0][0] << endl;

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			for (int action = 1; action <= 4; action++) {
				if (action == 4) {
					rewardSplit = 0;
					for (int k = 0; k < 38; k++) {
						if (i != 32) {
							for (int l = 0; l < 38; l++) {
								rewardSplit += calcTransProb(i,4,k) * calcTransProb(i,4,l) * (VMatrix[k][j] + VMatrix[l][j]);
							}
						}
						else {
							for (int l = 0; l < 38; l++) {
								rewardSplit += calcTransProb(i,4,k) * calcTransProb(i,4,l) * (calcStandingReward(k,j) + calcStandingReward(l,j));
							}
						}
					}
				}
				else if (action == 3) {
					rewardDouble = 0;				// see this
					for(int k=0;k<38;k++){
						rewardDouble += 2 * calcTransProb(i,3,k) * calcStandingReward(k,j);
					}
				}
				else if (action == 2) {
					rewardStand = calcStandingReward(i,j);
				}
				else if (action == 1) {
					rewardHit = 0;
					for (int k = 0; k < 38; k++) {
						rewardHit += calcTransProb(i,1,k) * VMatrix[k][j];
					}
					// cout << "Reward on hit\tfor playerState: " << i << " dealerState: " << j << ": " << rewardHit << endl;
					// cout << "Reward on stand\tfor playerState: " << i << " dealerState: " << j << ": " << calcStandingReward(i,j) << endl;
				}
			}
			bool debug=false;
			if (i >= 23 && i <= 32) {
				if (checkGreater(rewardHit, rewardSplit) && checkGreater(rewardHit, rewardStand) && checkGreater(rewardHit, rewardDouble)) {
					tempVMatrix[i][j] = rewardHit;
					actionMatrix[i][j] = 1;
					if(debug) cout << "here1" << endl;
				}
				else if (checkGreater(rewardStand, rewardSplit) && checkGreater(rewardStand, rewardHit) && checkGreater(rewardStand, rewardDouble)) {
					tempVMatrix[i][j] = rewardStand;
					actionMatrix[i][j] = 2;
					if(debug) cout << "here2" << endl;
				}else if(checkGreater(rewardDouble, rewardSplit) && checkGreater(rewardDouble, rewardHit) && checkGreater(rewardDouble, rewardStand)){
					tempVMatrix[i][j] = rewardDouble;
					actionMatrix[i][j] = 3;
					if(debug) cout << "hered" << endl;
				}
				else {
					tempVMatrix[i][j] = rewardSplit;
					actionMatrix[i][j] = 4;
					if(debug) cout << "here3" << endl;
				}
			}
			else {
				if (checkGreater(rewardHit, rewardStand) && checkGreater(rewardHit, rewardDouble)) {
					tempVMatrix[i][j] = rewardHit;
					actionMatrix[i][j] = 1;
					if(debug) cout << "here4" << endl;
				}else if(checkGreater(rewardDouble, rewardStand) && checkGreater(rewardDouble, rewardHit)){
					tempVMatrix[i][j] = rewardDouble;
					actionMatrix[i][j] = 3;
					if(debug) cout << "hered" << endl;
				}
				else {
					tempVMatrix[i][j] = rewardStand;
					actionMatrix[i][j] = 2;
					if(debug) cout << "here5" << endl;
				}
			}
		}
	}
	int diff=0;
	for(int i=0;i<38;i++){
		for(int j=0;j<10;j++){
			if(abs(VMatrix[i][j]- tempVMatrix[i][j]) > 0.0001){
				diff++;
			}
		}
	}
	cout << "number of values changed were : "<<diff<<endl;

	VMatrix = tempVMatrix;

	diff=0;
	for(int i=0;i<38;i++){
		for(int j=0;j<10;j++){
			if(abs(VMatrix[i][j]- tempVMatrix[i][j]) > 0.0001){
				diff++;
			}
		}
	}
	cout << "number of values changed were ---------------------------check: "<<diff<<endl;
}

void Game::valueIteration (int times) {

	fillVMatrix();

	double ** tempVMatrix = new double*[38];
	double reward = 0;

	for (int i= 0; i < 38; i++) {
		tempVMatrix[i] = new double[10];
	}

	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 10; j++) {
			tempVMatrix[i][j] = VMatrix[i][j];
		}
	}

	for (int i = 0; i < times; i++) {
		updateVMatrix();
		// printAction();
	}

	// for (int i = 0; i < 38; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		reward = 0;
	// 		for (int k = 0; k < 38; k++) {
	// 			reward += 2 * calcTransProb(i, 3, k) * calcStandingReward(k,j);
	// 		}
	// 		if(reward - VMatrix[i][j] > 0.0001) {
	// 			tempVMatrix[i][j] = reward;
	// 			actionMatrix[i][j] = 3;
	// 		}
	// 	}
	// }

	// VMatrix = tempVMatrix;

}

void Game::printTable (){
	for (int k = 0; k < 15; k++) {
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 38; j++) {
				cout<< transProb[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << k << " ---------------------------- " <<endl;
	}
	cout << "printed"<<endl;
}

string Game::numToAction (int action) {

	if (action == 1)
		return "H";
	else if (action == 2)
		return "S";
	else if (action == 3)
		return "D";
	else
		return "P";

}

void Game::printAction () {

	for (int i = 0; i <= 32; i++) {
		if (i <= 14) {
			cout << i+5 << "\t";
		}
		else if (i <= 22) {
			cout << "A" << i-13 << "\t";
		}
		else if (i <32) {
			cout << i-21 << i-21 << "\t";
		}
		else if (i == 32) {
			cout << "AA" << "\t";
		}
		cout << "\t";
		
		cout << numToAction(actionMatrix[i][0])/** << ": " << VMatrix[i][0] << "\t\t"*/;
		
		for (int j = 1; j < 10; j++) {
			cout << " " << numToAction(actionMatrix[i][j])/** << ": " << VMatrix[i][j] << "\t\t"*/;
		}
		cout << endl;
	}
	cout << endl;

}