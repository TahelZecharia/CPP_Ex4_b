#pragma once

#include "Player.hpp"

namespace coup{

    class Ambassador : public Player{

    public:

    // Contruuctor:  
    Ambassador(Game &game, const std::string &name);

    // The func transfer coin from one player to another player in addition.
    void transfer(Player &player1, Player &player2);
    
    // The ambassador can prevent a theft.
    void block(Player &player);
    
    // Destructor:
    ~Ambassador();
    
    };  
}