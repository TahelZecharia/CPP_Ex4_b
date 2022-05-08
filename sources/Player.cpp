#include "Player.hpp"

using namespace std;

const int SEVEN = 7;

namespace coup{

    // Contruuctor:
    Player:: Player(Game &game, string const &name)
            
            : _game(&game), _name(name), _role(""), _coins(0), _lastAction(""), _isActive(1) {

        this->_game->addPlayer(this);
    }

    // Contruuctor:
    Player:: Player(Game &game, string const &name, string const &role)
    
            : _game(&game), _name(name), _role(role), _coins(0), _lastAction(""), _isActive(1) {

        this->_game->addPlayer(this);
    }
        
    // Take a coin from the coin stack:
    void Player :: income(){

        this->turnConfirm();

        this->_coins++;

        this->endTurn("income");
    }
        
    // Take two coins from the coin stack:
    void Player :: foreign_aid(){

        this->turnConfirm();

        this->_coins+=2;

        this->endTurn("foreign_aid");
    }
        
    // Dismissing an opposing player from his position and thus removing him from the game:
    void Player :: coup(Player &player){

        if (player.isActive() == 0){

            throw runtime_error("The player is not active");
        }

        this->turnConfirm();

        if (this->coins() < SEVEN){

            throw runtime_error("There are not enough coins to make a coup (7 coins)");
        }

        player.isActive(0);

        this->_coins -= SEVEN;

        this->endTurn("coup");
    }

    // Cancelation of the coup:
    void Player :: cancelCoup(){

    }

    // Cancelation of the Theft:
    void Player :: cancelTheft(){

    }

    // The function returns the role of the player:
    string Player :: role(){

        cout << this->_name << " role is: " << this->_role << endl;

        return this->_role;
    }
        
    // The method returns how many coins the player has:
    int Player :: coins() const{

        return this->_coins;
    }

    // The method returns if the player is active now:
    int Player :: isActive() const{

        return this->_isActive;
    }

    // The method sets if the player is active now:
    void Player :: isActive(int num){

        this->_isActive = num;
    }

    // The function throws an error if it is not the player's turn:
    void Player :: turnConfirm(){

        if (this->_game->turn() != this->_name){

            throw runtime_error("It's someone else's turn");
        }

    }

    // The function updates the game that the player's turn is over:
    void Player :: endTurn(string action){

        this->_lastAction = move(action);

        this->_game->nextTurn();
    }

    // The function returns the player's name:
    string Player :: getName(){

        return this->_name;
    }

    // The function returns the player's last action:
    string Player :: getLastAction(){

        return this->_lastAction;
    }

    // The function adds coins to the player:
    void Player :: addCoins(int num){

        if ( (this->_coins + num) < 0 ){

            throw runtime_error("The player does not have enough coins");
        }

        this->_coins += num;
    }
        
    // Destructor:
    Player :: ~Player(){

    }
    
}