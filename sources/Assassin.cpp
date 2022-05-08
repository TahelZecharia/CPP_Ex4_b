#include "Assassin.hpp"

using namespace std;

namespace coup{

    // Contruuctor:
    Assassin :: Assassin(Game &game, const string &name) : 
            
            Player(game, name, "Assassin"){

    }

    // Assassin can coup with only 3 coins (instead of 7):
    void Assassin :: coup(Player &player){

        this->turnConfirm("coup");

        int coins = this->coins();

        const int SEVEN = 7;
        const int THREE = 3;

        if (coins < 3){

            throw runtime_error("There are not enough coins to make a coup (3 coins)");
        }

        if (coins >= SEVEN){

            player.removePlayer();

            this->_coins -= SEVEN;
        }

        else {

            player.removePlayer();

            this->_coins -= 3;

            this->_blocked = &player;
        }

        this->endTurn("coup");
    }

    // Cancelation of the coup:
    void Assassin :: cancelCoup(){

        if ( this->_lastAction != "coup" ){

            throw runtime_error("The last action is not coup");
        }

        if ( this->_blocked == NULL ){

            throw runtime_error("The coup cost 7 coins and cant be blocked");
        }

        this->_blocked->isActive(1);

        this->_blocked = NULL;
    }

    // Destructor:
    Assassin :: ~Assassin(){

    }
}