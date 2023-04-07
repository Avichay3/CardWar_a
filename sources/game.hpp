#include "iostream"
#include "player.hpp"
using namespace ariel;

class Game{
    Player p1;
    Player p2;

    public:
    Game(Player& player1, Player& player2): p1(player1) , p2(player2) {}
            
            

        Game(Player p1, Player p2){}; //constructor for the class

        void playTurn();
        void playAll();
        void printWiner();
        void printStats();
        void printLog();
        void printLastTurn();
        Player& getPlayerP1(){return p1}; //getter
        Player& getPlayerP2(){return p2}; //getter

}



