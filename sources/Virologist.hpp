#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Virologist: public Player {
        public:
            // Board b; 
            // City c;
            Virologist(Board& b, City c): Player(b, c) {}
            Virologist& treat(City c);     
            std:: string role();
    };
}