#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class GeneSplicer: public Player {
        public:
            // Board b; 
            // City c;
            GeneSplicer(Board& b, City c);
            void discover_cure(Color c);     
            std:: string role();
    };
}