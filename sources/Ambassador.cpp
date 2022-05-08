#include "Ambassador.hpp"

using namespace std;

namespace coup{


    // Contruuctor:
    Ambassador :: Ambassador(Game &game, const string &name) : 
            
            Player(game, name, "Ambassador"){

    }

    // The func transfer coin from one player to another player in addition.
    void Ambassador :: transfer(Player &player1, Player &player2){

        this->turnConfirm("transfer");

        player1.addCoins(-1);
        player2.addCoins(1);

        this->endTurn("transfer");

    }
    
    // The ambassador can prevent a theft.
    void Ambassador :: block(Player &player){

        if ( player.role() != "Captain" ){

            throw runtime_error("The player can not block a theft");
        }

        if ( this->_isActive == 0 ){

            throw runtime_error("The player is not active");
        }

        player.cancelTheft();
    }
    
    // Destructor:
    Ambassador :: ~Ambassador(){

    }
}