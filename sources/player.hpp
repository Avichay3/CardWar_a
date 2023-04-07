#include <string>
#include <iostream>

const int NUMOFCARDS = 26;
const int FULL

namespace ariel{
    class Player{
    private:
        std::string name;
    public:
        Player(){}
        Player(std::string name);

        int stackSize(){return 27};
        int cardsTaken(){return 27};
    };
    
   
    
};