#include "Game.h"
int main(int argc, char** argv)
{
    Game * mgame = new Game(0.4);
    mgame->fillTable();
    mgame->updateTable();
    mgame->printTable();
    for(int i=0;i<38;i++){
        double ct=0;
        for(int j=0;j<38;j++){
            ct += mgame->transProb[i][j][0];
        }
        cout<<ct<<endl;
    }
    cout << "done"<<endl;
}