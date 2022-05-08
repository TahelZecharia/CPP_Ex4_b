#include "Captain.hpp"

using namespace std;

namespace coup{


    // Contruuctor:
    Captain :: Captain(Game &game, const string &name) : 
            
            Player(game, name, "Captain"){

            }

    // The func steal 2 coins from another player
    void Captain :: steal(Player &player){

        this->turnConfirm();

        player.addCoins(-2);
        this->addCoins(2);

        this->endTurn("steal");
    }

    // The captain can prevent a theft.
    void Captain :: block(Player &player){

        this->turnConfirm();

        /// to do ////

        this->endTurn("block");

    }
    
    // Destructor:
    Captain :: ~Captain(){

    }
}