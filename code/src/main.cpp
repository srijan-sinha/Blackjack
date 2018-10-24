#include "Game.h"
int main(int argc, char** argv)
{
    Game * mgame = new Game(0.4);
    mgame->fillTable();
    mgame->updateTable();
    mgame->printTable();
}