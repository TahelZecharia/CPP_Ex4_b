#pragma once

#include "Player.hpp"

namespace coup{

    class Contessa : public Player{

    public:

    // Contruuctor:    
    Contessa(Game &game, const std::string &name);

    // Can block the act of assassination  
    void block(Player &player);
    
    // Destructor:
    ~Contessa();

    };
}