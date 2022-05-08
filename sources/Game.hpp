#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"

namespace coup{

    class Player;

    class Game{

        std::vector<Player*> _players;
        int _turn;
        int _start;

        public:
        
        // Contruuctor:
        Game();
        
        // returns the names of the players currently active in the game.
        std::vector<std::string> players();
        
        // Print the name of the player whose turn to play now.
        std::string turn();
        
        // The method returns the name of the winner. 
        // If the game is still active, the method will throw an error.
        std::string winner();

        // Add a new player to the game:
        void addPlayer(Player *player);

        // The function advances the turn of the game:
        void nextTurn();
        
        // Destructor:
        ~Game();
    };
}