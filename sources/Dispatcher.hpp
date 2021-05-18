#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Dispatcher: public Player {
        public:
            // Board b; 
            // City c;
            Dispatcher(Board &b, City c);

            // Dispatcher& drive(City c);
            Dispatcher& fly_direct(City c);
            // Dispatcher& fly_charter(City c);
            // Dispatcher& fly_shuttle(City c);    
            std:: string role();
    };
}