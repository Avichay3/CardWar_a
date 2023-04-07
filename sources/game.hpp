using namespace ariel;

class Game{
    player p1;
    player p2;

    public:
        Game(player p1, player p2){}; //constructor for the class
        
        void playTurn();
        void playAll();
        void printWiner();
        void printStats();
        void printLog();
        void printLastTurn();
}



