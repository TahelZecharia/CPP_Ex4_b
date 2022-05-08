#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

#include <stdexcept>
#include <exception>
using namespace std;




TEST_CASE("Game"){

    Game game{};
    Duke duke1{game, "player 1"};
	Assassin assassin2{game, "player 2"};
	Ambassador ambassador3{game, "player 3"};
	Captain captain4{game, "player 4"};
	Contessa contessa5{game, "player 5"};

    SUBCASE("Contruuctor"){

        CHECK_THROWS(Assassin assassin(game, "player 5")); // name already exist.

        CHECK_NOTHROW(Duke duke6(game, "player 6")); // players can have the same role.
        
        CHECK_THROWS(Assassin assassin(game, "player 7")); // to much players.

        CHECK(game.players().size() == 6); // there is 6 players in the game.
    }

    vector<Player*> players = {&duke1, &assassin2, &ambassador3, &captain4, &contessa5};

    SUBCASE("Game"){
        
        // income:
        CHECK(duke1.coins() == 0);
        CHECK_NOTHROW(duke1.income()); 
        CHECK(duke1.coins() == 1);
        CHECK_THROWS(duke1.income()); // it is assassin2 turn

        // foreign_aid:
        CHECK(assassin2.coins() == 0);
        CHECK_NOTHROW(assassin2.foreign_aid()); 
        CHECK(assassin2.coins() == 2);
        CHECK_THROWS(assassin2.income()); // it is ambassador3 turn

        // block foreign_aid:
        CHECK_NOTHROW(duke1.block(assassin2)); 
        CHECK(assassin2.coins() == 0);

        // add 4 coins to all of the players:
        for (size_t i = 2; i < players.size(); i++){
            
            CHECK_NOTHROW(players.at(i)->income());
        }

        CHECK_NOTHROW(duke1.foreign_aid()); 
        CHECK_NOTHROW(assassin2.foreign_aid()); 

        for (size_t i = 2; i < players.size(); i++){
            
            CHECK_NOTHROW(players.at(i)->income());
        }

        for (size_t i = 0; i < players.size(); i++){
            
            CHECK_NOTHROW(players.at(i)->foreign_aid());
        }

        // check there are 4 coins to all of the players:
        for (size_t i = 1; i < players.size(); i++){
            
            CHECK(players.at(i)->coins() == 4);
        }

        CHECK_NOTHROW(duke1.foreign_aid()); 

        // assassin coup:
        CHECK_NOTHROW(assassin2.coup(ambassador3)); 
        CHECK(assassin2.coins() == 1);
        CHECK(game.players().size() == 4); // ambassador3 removed by coup of assassin2
        CHECK_THROWS(ambassador3.income()); // ambassador3 is blocked

        // contessa block:
        CHECK_NOTHROW(contessa5.block(assassin2));  // ambassador3 returned to the game by contessa5
        
        for (size_t i = 3; i < players.size(); i++){
            
            CHECK_NOTHROW(players.at(i)->income());
        }
        for (size_t i = 0; i < 3; i++){ //check that ambassador3 returned to the game
            
            CHECK_NOTHROW(players.at(i)->income());
        }

        // captain steal:
        CHECK(duke1.coins() == 8);
        CHECK_NOTHROW(captain4.steal(duke1)); // steal from duke1
        CHECK(duke1.coins() == 6); // cheak the theft

        // ambassador block:
        CHECK_NOTHROW(ambassador3.block(captain4)); // block captain4
        CHECK(duke1.coins() == 8); // cheak the theft

        // winner:
        CHECK_NOTHROW(contessa5.foreign_aid());
        CHECK_NOTHROW(duke1.coup(assassin2)); // coup assassin2
        for (size_t i = 2; i < players.size(); i++){
            
            CHECK_NOTHROW(players.at(i)->foreign_aid());
        }
        CHECK_NOTHROW(duke1.income()); 
        CHECK_NOTHROW(ambassador3.coup(duke1)); // coup duke1
        CHECK_NOTHROW(captain4.coup(ambassador3)); // coup ambassador3
        CHECK_NOTHROW(contessa5.coup(captain4)); // coup captain4

        CHECK(game.winner() == "player 5"); // contessa5 is the winner!

    }

}

