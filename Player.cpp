#include <iostream>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    Player::Player(Board b, City c){}
    Player::Player(){}
    Player& Player::drive(City c){
        return *this;
    }
    Player& Player::fly_direct(City c){
        return *this;
    }
    Player& Player::fly_charter(City c){
        return *this;
    }
    Player& Player::fly_shuttle(City c){
        return *this;
    }
    void Player::build(){
        return;
    }
    void Player::discover_cure(Color c){
        return;
    }
    Player& Player::treat(City c){
        return *this;
    } 
    string Player::role(){
        return "admatay";
    }
    Player& Player::take_card (City c){
        return *this;
    }
}