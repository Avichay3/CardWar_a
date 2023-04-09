#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <string.h>
#include <stdexcept>
#include <iostream>
using namespace ariel;

using namespace std;

TEST_CASE("Checking initialization"){
    CHECK_NOTHROW(Player p1("BOB"));
}

TEST_CASE("Checking Game class constructor"){
    Player p1("player1");
    Player p2("player2");
    CHECK_NOTHROW(Game{p1, p2});
}

TEST_CASE("Checking Player get fucntion"){
    Player p1("player1");
    CHECK(p1.getName().compare("player1") == 0);
}

TEST_CASE("Checking if game stats are correct"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    int amount_of_cards = 52;
    CHECK(p1.stacksize() == (amount_of_cards/2)); //if player 1 has 26 cards in the start
    CHECK(p2.stacksize() == (amount_of_cards/2)); //if player 2 has 26 cards in the start
    CHECK(p1.stacksize() - p2.stacksize() == 0);
    CHECK_NOTHROW(game.playTurn());
    CHECK(p1.stacksize() != (amount_of_cards/2));
    CHECK(p2.stacksize() != (amount_of_cards/2));
}

TEST_CASE("Checking if there is some winner"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playAll());
    CHECK((p1.cardesTaken() > p2.cardesTaken() || p2.cardesTaken() > p1.cardesTaken()));
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}


TEST_CASE("checking if exception has thrown if the game is not finished"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playTurn());
}

    

  
TEST_CASE("Checking if game function called after the game finish"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}

TEST_CASE("throwing errors from the functions")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}


TEST_CASE("check if other fucntions in game works good"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("Printing the winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
}


TEST_CASE("Checking if exception thrown when trying to print the last turn before game started"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
}

TEST_CASE("Checking if some player get rank greater than 26"){
    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    game.playAll();
    CHECK((p1.cardesTaken() <= 26 || p2.cardesTaken() <= 26));
}


