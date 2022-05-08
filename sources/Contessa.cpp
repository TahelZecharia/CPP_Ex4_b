#include "Contessa.hpp"

using namespace std;

namespace coup{


    // Contruuctor:
    Contessa :: Contessa(Game &game, const string &name) : 
            
            Player(game, name, "Contessa"){

            }

    // Can block the act of assassination  
    void Contessa :: block(Player &player){

        if ( this->_isActive == 0 ){

            throw runtime_error("The player is not active");
        }

        player.cancelCoup();

    }
    
    // Destructor:
    Contessa :: ~Contessa(){

    }
}