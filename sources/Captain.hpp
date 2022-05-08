#pragma once

#include "Player.hpp"

namespace coup{

    class Captain : public Player{
        
        // Player *pFrom;
        
        public:
        
        // Contruuctor:
        Captain(Game &game, const std::string &name);
        
        // The func steal 2 coins from another player
        void steal(Player &player);

        // The captain can prevent a theft.
        void block(Player &player);

        // Destructor:
        ~Captain();
    }; 
}