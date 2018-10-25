#include "Game.h"
#include <string.h>

int main(int argc, char** argv)
{
	string input = "";
	if(argc != 2)
		cout << "Arguments in format: p" << endl;
	else
		input = argv[1];
	double p = stod(input);
    Game * mgame = new Game(p);
    mgame->fillTable();
    mgame->updateTable();
    // mgame->printTable();
    // mgame->fillVMatrix();
    // mgame->printAction();
    mgame->valueIteration(10);
    mgame->printAction();
    // cout << "5 " << mgame->calcStandingReward(0, 0) << endl;
	// cout << "6 " << mgame->calcStandingReward(1, 0) << endl;
 //    cout << "7 " << mgame->calcStandingReward(2, 0) << endl;
 //    cout << "8 " << mgame->calcStandingReward(3, 0) << endl;
 //    cout << "9 " << mgame->calcStandingReward(4, 0) << endl;
 //    cout << "10 " << mgame->calcStandingReward(5, 0) << endl;
 //    cout << "11 " << mgame->calcStandingReward(6, 0) << endl;
 //    cout << "12 " << mgame->calcStandingReward(7, 0) << endl;
 //    cout << "13 " << mgame->calcStandingReward(8, 0) << endl;
 //    cout << "14 " << mgame->calcStandingReward(9, 0) << endl;
 //    cout << "15 " << mgame->calcStandingReward(10, 0) << endl;
 //    cout << "16 " << mgame->calcStandingReward(11, 0) << endl;
    // cout << endl << mgame->probScore(3, 18) << endl;
    // cout << "Up card is 2 and probability of reaching sum 5 is: " << mgame->calcStateProb(1, 0) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 6 is: " << mgame->calcStateProb(1, 8) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 7 is: " << mgame->calcStateProb(1, 2) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 8 is: " << mgame->calcStateProb(1, 3) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 9 is: " << mgame->calcStateProb(1, 4) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 10 is: " << mgame->calcStateProb(1, 5) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 11 is: " << mgame->calcStateProb(1, 6) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 12 is: " << mgame->calcStateProb(1, 7) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 13 is: " << mgame->calcStateProb(1, 16) << endl; 
    // cout << "Up card is 2 and probability of reaching sum 4 is: " << mgame->calcStateProb(1, 24) << endl; 
 	// cout << mgame->calcFinalState(7,13) << endl;
    

    // for (int j = 11; j < 21; j++) {
    // 	double sum = 0;
/***********

 //    for (int j = 0; j < 38; j++) {
 //    	double sum = 0;
	//     for (int i = 0; i < 38; i++) {
	//     	cout << "From shown state of dealer: "<< j << " After hit state of dealer: " << i << " prob is: " << mgame->transProb[j][i][1] << endl;
	//     	sum += mgame->transProb[j][i][1];
	//     }

	//     cout << endl << "State Num: " << j << " Sum: " << sum << endl;
	//     cout << endl;
	// }
    for(int j=0;j<38;j++){
            double sum =0;
            sum += mgame->calcTransProb(j,1,i);
            cout <<"j is "<<j<< " i "<<i<< " is "<< mgame->calcTransProb(j,1,i) << endl;
        }
            cout <<"Sum is : "<< sum << endl;
            if(sum-1>0.0001){
                cout << "j "<<j<<endl;
            }
    }
	// cout << mgame->calcTransProb(0, 1 ,37) << endl;
    // for (int j = 33; j < 38; j++) {
    // 	double sum = 0;
	//     for (int i = 0; i < 38; i++) {
	//     	cout << "From shown state of dealer: "<< j << " After hit state of dealer: " << i << " prob is: " << mgame->transProb[j][i][1] << endl;
	//     	sum += mgame->transProb[j][i][1];
	//     }

	//     cout << endl << "State Num: " << j << " Sum: " << sum << endl;
	//     cout << endl;
	// }
*********/
    // cout << mgame->calcStandingReward(0, 9) << endl;
    // for(int i = 0; i < 38; i++) {
    // 	cout << "State: " << i << " Value: " << mgame->valueHand(i) << endl;
    // }

    // for (int i = 23; i < 33; i++) {
    // 	double sum = 0;
    // 	for (int j = 0; j < 38; j++) {
    // 		cout << "State from: " << i << "\t State to: " << j << "\t prob on hit: " << mgame->calcTransProb(i, 4 ,j) << endl;
    // 		sum += mgame->calcTransProb(i, 4, j);
    // 	}
    // 	cout << endl << "Sum: " << sum << endl << endl;;
    // }
/********************
*/
	cout << mgame-> calcStandingReward(14, 5);

// ******************/

	// cout << mgame->calcTransProb(24, 1 ,3) << endl;
    // mgame->printTable();
}