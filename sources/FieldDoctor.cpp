#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "FieldDoctor.hpp"
 
    namespace pandemic{
            FieldDoctor::FieldDoctor(Board &b, City c): Player(b, c) {}
              
            FieldDoctor& FieldDoctor::treat(City c){
                if(board[c] > 0 && ( board.neib.at(city).count(c) > 0 || city == c)){
                    if(board.foundM[board.colorM[c]]){
                        board[c] = 0;
                    }
                    else{
                        board[c]--;
                    }
                }
                else{
                    throw std::invalid_argument{" doesn't have sick cubes"};
                }
                        return *this;
                    }     
            std:: string FieldDoctor::role(){
                    return "FieldDoctor";
            }
    }