#include "Duke.hpp"

using namespace std;

namespace coup{

    // Contruuctor:
    Duke :: Duke(Game &game, const string &name) : 
            
            Player(game, name, "Duke"){

            }

    // Can take a tax of three coins from the pot without any player being able to prevent it.
    void Duke :: tax(){

        this->turnConfirm("tax");

        this->_coins += 3;

        this->endTurn("tax");
    }
        
    // The Duke can block double pay action. The blocked player returns the two coins to the pot.
    void Duke :: block(Player &player){

        if ( this->_isActive == 0 ){

            throw runtime_error("The player is not active");
        }

        string lastAct = player.getLastAction();

        if ( lastAct != "foreign_aid" ){

            throw runtime_error("The last action is not foreign_aid");
        }

        player.addCoins(-2);
    }

    // Destructor:
    Duke::~Duke(){

    }
}