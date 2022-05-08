#include "Ambassador.hpp"

using namespace std;

namespace coup{


    // Contruuctor:
    Ambassador :: Ambassador(Game &game, const string &name) : 
            
            Player(game, name, "Ambassador"){

            }

    // The func transfer coin from one player to another player in addition.
    void Ambassador :: transfer(Player &player1, Player &player2){

        this->turnConfirm();

        player1.addCoins(-1);
        player1.addCoins(1);

        this->endTurn("transfer");

    }
    
    // The ambassador can prevent a theft.
    void Ambassador :: block(Player &player){

        this->turnConfirm();

        /// to do ///
        this->endTurn("block");

    }
    
    // Destructor:
    Ambassador :: ~Ambassador(){

    }
}