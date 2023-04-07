#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

TEST_CASE("check if the name of player is correct"){
    Player p1("player1");
    CHECK (p1.getName().compare("player1") == 0);
    CHECK (strcmp(p1.getName(), "player1") == 0);
}

TEST_CASE("The main check"){
    player p1("Alice");
    player p2 ("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.printStats());

}

