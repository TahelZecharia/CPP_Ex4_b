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

        int coins = player.coins();

        // if the player have 2 coins:
        if (coins >= 2){
            
            this->addCoins(2);
            player.addCoins(-2);
            this->endTurn("steal2");
        }

        // if the player have 1 coin:
        if (coins == 1){
            
            this->addCoins(1);
            player.addCoins(1);
            this->endTurn("steal1");
        }

        // if the player have no coins:
        if (coins == 0){
            
            this->endTurn("steal0");
        }

        this->_stoleFrom = &player;
    }

    // The captain can prevent a theft.
    void Captain :: block(Player &player){

        player.cancelTheft();

    }

    // Cancelation of the Theft:
    void Captain :: cancelTheft(){

        string lastAct = this->_lastAction;

        if ( lastAct != "steal0" && lastAct != "steal1" && lastAct != "steal2" ){

            throw runtime_error("The last action is not steal");
        }

        // if the player stole 2 coins:
        if (lastAct == "steal2"){
            
            this->addCoins(-2);
            this->_stoleFrom->addCoins(2);
        }

        // if the player stole 1 coin:
        if (lastAct == "steal1"){
            
            this->addCoins(-1);
            this->_stoleFrom->addCoins(1);
        }

        this->_stoleFrom = NULL;
    }
    
    // Destructor:
    Captain :: ~Captain(){

    }
}