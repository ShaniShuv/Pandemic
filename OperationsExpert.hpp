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
            OperationsExpert(Board b, City c);

            // OperationExpert& drive(City c);
            // OperationExpert& fly_direct(City c);
            // OperationExpert& fly_charter(City c);
            // OperationExpert& fly_shuttle(City c);
            // void build(); 
            // void discover_cure(Color c);  
            // OperationExpert& treat(City c);     
            // std:: string role();
            // OperationExpert& take_card ();
    };
}