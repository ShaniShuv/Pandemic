#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Dispatcher.hpp"

    namespace pandemic{
            Dispatcher::Dispatcher(Board& b, City c): Player(b, c) {} 
                

        Dispatcher& Dispatcher::fly_direct(City c){
            if(city == c){
                throw std::invalid_argument{"Dispatcher"};
            }
            if(board.reaserchStation[city]){
                        city = c;
                        return *this;
            }
            if(cardsH[c]){
                cardsH[c] = false;
                city = c;
                return *this;
            }
            throw std::invalid_argument{"Dispatcher"};
        }
        string Dispatcher ::role(){
            return "Dispatcher";
        }
    }