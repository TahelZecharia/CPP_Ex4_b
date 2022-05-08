#include "Contessa.hpp"

using namespace std;

namespace coup{


    // Contruuctor:
    Contessa :: Contessa(Game &game, const string &name) : 
            
            Player(game, name, "Contessa"){

            }

    // Can block the act of assassination  
    void Contessa :: block(Player &player){

        player.cancelCoup();

    }
    
    // Destructor:
    Contessa :: ~Contessa(){

    }
}