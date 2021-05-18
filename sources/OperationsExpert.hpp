#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class OperationsExpert: public Player {
        public:
            // Board b; 
            // City c;
            OperationsExpert(Board& b, City c);
            std:: string role();
            void build(); 
    };
}