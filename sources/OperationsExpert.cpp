#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"

    namespace pandemic{
            OperationsExpert::OperationsExpert(Board& b, City c): Player(b, c){
            }
            void OperationsExpert::build(){
                    board.reaserchStation[city] = true;
                //     return *this;
            }
            string  OperationsExpert::role(){
			return "OperationsExpert";
		}
    }