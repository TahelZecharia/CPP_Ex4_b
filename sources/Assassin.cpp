#include "Assassin.hpp"

using namespace std;

namespace coup{

    // Contruuctor:
    Assassin :: Assassin(Game &game, const string &name) : 
            
            Player(game, name, "Assassin"){

            }

    // Assassin can coup with only 3 coins (instead of 7):
    void Assassin :: coup(Player &player){

        this->turnConfirm();

        if (this->coins() < 3){

            throw runtime_error("There are not enough coins to make a coup (3 coins)");
        }

        this->_game->removePlayer(player.getName());

        this->_coins -= 3;

        this->endTurn("coup");
    }

    // Destructor:
    Assassin :: ~Assassin(){

    }
}