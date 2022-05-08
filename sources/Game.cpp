#include<bits/stdc++.h>

#include "Game.hpp"

using namespace std;

const int SIX = 6;

namespace coup{

    // Contruuctor:
    Game:: Game(){

        this->_turn = 0;
        this->_start = 0;
    }
        
    // returns the names of the players currently active in the game.
    vector<string> Game:: players(){

        vector<string> names;
        
        for(Player *player : this->_players ){
            
            if (player->isActive() == 1){

                names.push_back(player->getName());
            }  
        }
        return names;
    }
        
    // Print the name of the player whose turn to play now.
    string Game:: turn(){

        if (this->_players.empty()){

            throw runtime_error("The game has no players");

        }

        return this->_players.at( (unsigned long) this->_turn)->getName(); 
    }
        
    // The method returns the name of the winner. 
    // If the game is still active, the method will throw an error.
    string Game:: winner(){

        if (this->_players.size() < 2){
            
            throw runtime_error("The game is not start yet");
        }

        if (this->players().size() != 1){

            throw runtime_error("The game is not over yet");
        }

        cout << "**************************" << endl;
        cout << "  THE WINNER IS " << this->players().at(0) << endl;
        cout << "**************************" << endl;

        return this->players().at(0);
    }

    // Add a new player to the game:
    void Game :: addPlayer(Player *player){

        if (this->_start == 1){

            throw runtime_error("The game already started");
        }

        if (this->_players.size() >= SIX){

            throw runtime_error("The game contains 6 players");
        }

        this->_players.push_back(player);
    }

    // The function advances the turn of the game:
    void Game :: nextTurn(){

        this->_start = 1;

        this->_turn += 1;
        this->_turn %= this->_players.size();

        while ( (this->_players.at( (unsigned long) this->_turn)->isActive()) != 1){

            this->_turn += 1;
            this->_turn %= this->_players.size();
        }
    }

    // Destructor:
    Game :: ~Game(){

    }
    
}