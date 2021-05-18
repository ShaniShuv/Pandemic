#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Medic: public Player {
        public:
            // Board b; 
            // City c;
            Medic(Board &b, City c): Player(b, c) {}
            Medic& fly_shuttle(City c);
            Medic& drive(City c);
            Medic& fly_direct(City c);
            Medic& fly_charter(City c);
 
            Medic& treat(City c);     
            std:: string role();
    };
}