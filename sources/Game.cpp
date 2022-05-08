#include<bits/stdc++.h>

#include "Game.hpp"

using namespace std;

const int SIX = 6;

namespace coup{

    // Contruuctor:
    Game:: Game(){

        this->_turn = 0;
    }
        
    // returns the names of the players currently active in the game.
    vector<string> Game:: players(){

        return this->_players;
    }
        
    // Print the name of the player whose turn to play now.
    string Game:: turn(){

        if (this->_players.empty()){

            throw runtime_error("The game has no players");

        }

        return this->_players.at( (unsigned long) this->_turn); 
    }
        
    // The method returns the name of the winner. 
    // If the game is still active, the method will throw an error.
    string Game:: winner(){

        if (this->_players.size() != 1){

            throw runtime_error("The game is not over yet");
        }

        return this->_players.at(0);
    }

    // Add a new player to the game:
    void Game :: addPlayer(string const &name){

        if (this->_players.size() >= SIX){

            throw runtime_error("The game contains 6 players");
        }

        for(string const &existName : this->_players ){

            if (existName == name){

                throw invalid_argument("The name already exists in the game");
            }

        }

        this->_players.push_back(name);
    }

    // Remove a player from the game:
    void Game :: removePlayer(const string &name){

        vector<string>::iterator iter;
        iter = remove(this->_players.begin(), this->_players.end(), name);
    }

    // The function advances the turn of the game:
    void Game :: nextTurn(){

        this->_turn += 1;
        this->_turn %= this->_players.size();
    }

    // Destructor:
    Game :: ~Game(){

    }
    
}