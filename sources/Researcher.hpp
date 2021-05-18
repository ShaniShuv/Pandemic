#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Researcher: public Player {
        public:
            // Board b; 
            // City c;
            Researcher(Board& b, City c);

            void discover_cure(Color c);
            std:: string role();  
    };
}