#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace coup{

    class Game{

        std::vector<std::string> _players;
        int _turn;

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
        void addPlayer(const std::string &name);

        // Remove a player from the game:
        void removePlayer(const std::string &name);

        // The function advances the turn of the game:
        void nextTurn();
        
        // Destructor:
        ~Game();
    };
}