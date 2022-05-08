#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Game.hpp"

namespace coup{

    class Game;

    class Player{

        protected:

        Game* _game;
        std::string _name;
        std::string _role;
        int _coins;
        std::string _lastAction;
        int _isActive;

        public:

        // Contruuctor:
        Player(Game &game, std::string const &name);
        
        // Contruuctor:
        Player(Game &game, std::string const &name, std::string const &role);
        
        // Take a coin from the coin stack:
        void income();
        
        // Take two coins from the coin stack:
        void foreign_aid();
        
        // Dismissing an opposing player from his position and thus removing him from the game:
        virtual void coup(Player &player);

        // Cancelation of the coup:
        virtual void cancelCoup();

        // Cancelation of the Theft:
        virtual void cancelTheft();
        
        // The function returns the role of the player:
        std::string role();
        
        // The method returns how many coins the player has:
        int coins() const;

        // The method returns if the player is active now:
        int isActive() const;

        // The method sets if the player is active now:
        void isActive(int num);

        // Remove a player from the game:
        void removePlayer();

        // The function throws an error if it is not the player's turn:
        void turnConfirm(std::string const &action);

        // The function updates the game that the player's turn is over:
        void endTurn(std::string action);

        // The function returns the player's name:
        std::string getName();

        // The function returns the player's last action:
        std::string getLastAction();

        // The function adds coins to the player:
        void addCoins(int num);
        
        // Destructor:
        ~Player();
    };
}
