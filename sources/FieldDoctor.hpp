#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class FieldDoctor: public Player {
        public:
            // Board b; 
            // City c;
            FieldDoctor(Board& b, City c);
;  
            FieldDoctor& treat(City c);     
            std:: string role();

    };
}