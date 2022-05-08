#pragma once

#include "Player.hpp"

namespace coup{

    class Assassin : public Player{

        // A pointer that points to the player who has been blocked by the Assassin:
        Player* _blocked = NULL;

        public:

        // Contruuctor:
        Assassin(Game &game, const std::string &name);
        
        // Assassin can coup with only 3 coins (instead of 7):
        void coup(Player &player);
        
        // Cancelation of the coup:
        void cancelCoup();

        // Destructor:
        ~Assassin();

    };  
}