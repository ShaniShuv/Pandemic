#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Virologist.hpp"

    namespace pandemic{
            // Virologist(Board &b, City c): Player(b, c) {}
            Virologist& Virologist::treat(City c){
                if(board[c] <= 0) {
                    board[c] = 0;
                        throw invalid_argument{" V--------------------"};
            }    
                if (city == c){
                    if(board.foundM[board.colorM[c]]){
                        board[c] = 0;
                    }
                    else{
                        board[c]--;
                    }
                    return *this;
                }
                if(cardsH[c]){
                    cardsH[c]=false;
                    if(board.foundM[board.colorM[c]]){
                        board[c] = 0;
                    }
                    else{
                        board[c]--;
                   }
                return *this;
                }
                throw invalid_argument{" V--------------------"};
                 
            }
            std:: string Virologist ::role(){
                    return "Virologist";
            }
    }