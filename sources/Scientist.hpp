#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist: public Player {
        public:
            // Board b; 
            // City c;
            int i;
            Scientist(Board& b, City c, int i): Player(b, c), i(i) {}
            void discover_cure(Color c);  
            std:: string role();
    };
}