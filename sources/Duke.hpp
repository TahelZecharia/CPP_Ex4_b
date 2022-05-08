#pragma once

#include "Player.hpp"

namespace coup{

    class Duke : public Player{
        
        public: 
        // Contruuctor:
        Duke(Game &game, const std::string &name);
        
        // Can take a tax of three coins from the pot without any player being able to prevent it.
        void tax();
        
        // The Duke can block double pay action. The blocked player returns the two coins to the pot.
        void block(Player &player);

        // Destructor:
        ~Duke();
    };
}