#include <string>
#include <iostream>

namespace ariel{
    class player{
    private:
        std::String name;
    public:
        player(){}
        player(std::String name);

        int stackSize(){return 27};
        int cardsTaken(){return 27};
    };
    
   
    
};