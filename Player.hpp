#pragma once
#include "Board.hpp"
#include <string>

namespace pandemic{


    class Player {
        public:
            Player();
            Player(Board b, City c);
            Player& drive(City c);
            Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            void build(); 
            void discover_cure(Color c);  
            Player& treat(City c);     
            std:: string role();
            Player& take_card (City c);
    };
}