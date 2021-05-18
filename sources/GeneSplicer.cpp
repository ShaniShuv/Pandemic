#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "GeneSplicer.hpp"
const int FIVE = 5;
    namespace pandemic{
            GeneSplicer::GeneSplicer(Board &b, City c): Player(b, c) {}
        void GeneSplicer::discover_cure(Color c){
            // redC = 0; blueC = 0; blackC = 0; yellowC = 0;
            int counter = 0;
        for(auto m : cardsH){
            if(m.second){
                counter ++;
                // switch (board.colorM[m.first])
                // {
                // case Color::Red:
                //     redC++;
                // case Color::Blue:
                //     blueC++;
                // case Color::Black:
                //     blackC++;
                // case Color::Yellow:
                //     yellowC++;
                // }
            }

		}
            if(!board.reaserchStation[city] ){
                throw std::invalid_argument{"GeneSplicer 1"};
            }
            if((counter) < FIVE){
                throw std::invalid_argument{"GeneSplicer 2 "};
            }
        //     if(board.foundM[c]){
        //     return;
        // }
            board.foundM[c] = true;
                for (size_t i = 0; i < FIVE; i++)
                {
                    for(auto m:cardsH)
                    {
                        if(m.second && i < FIVE)
                        {
                            i++;
                            cardsH[m.first] = false;
                            Color color = board.colorM[m.first];
                            switch (color)
                            {
                                case Color::Red:
                                    redC--;
                                case Color::Blue:
                                    blueC--;
                                case Color::Black:
                                    blackC--;
                                case Color::Yellow:
                                    yellowC--;
                            }
                        }
                    }
                }//for
              
        } // viod     
            std:: string GeneSplicer::role(){
                    return "GeneSplicer";
            }
    }