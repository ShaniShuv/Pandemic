#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Researcher.hpp"
const int FIVE = 5;
namespace pandemic{
	Researcher::Researcher(Board& b, City c): Player(b, c) {} 
	void Researcher::discover_cure(Color c){
        redC = 0; blueC = 0; blackC = 0; yellowC = 0;
        for(auto m : cardsH){
            if(m.second){
                switch (board.colorM[m.first])
                {
                case Color::Red:
                    redC++;
                case Color::Blue:
                    blueC++;
                case Color::Black:
                    blackC++;
                case Color::Yellow:
                    yellowC++;
                }
            }

		}
		// if(!board.reaserchStation[city]){
		// 	throw std::invalid_argument{"Scientist"};
		// }
		switch (c)
		{
		case Color::Red:
			if(redC < FIVE){
				throw std::invalid_argument{" RED"};
			}
		case Color::Blue:
			if(blueC < FIVE){
				throw std::invalid_argument{" BLUE"};
			}
		case Color::Black:
			if(blackC < FIVE){
				throw std::invalid_argument{" BLACK"};
			}
		case Color::Yellow:
			if(yellowC < FIVE){
				throw std::invalid_argument{" YELLOW"};
			}
		}
		if(board.foundM[c]){
			return;
		}
        board.foundM[c] = true;
        int i = FIVE;
		switch (c)
		{
		case Color::Red:
				for(auto m : cardsH){
					if(m.second && board.colorM[m.first] == c && i >0){
						i--;
						cardsH[m.first] = false;
					}
				}
				redC -=FIVE;
		case Color::Blue:
				for(auto m : cardsH){
					if(m.second && board.colorM[m.first] == c && i >0){
						i--;
						cardsH[m.first] = false;
					}
				}
				blueC -=FIVE;
		case Color::Black:
				for(auto m : cardsH){
					if(m.second && board.colorM[m.first] == c && i >0){
						i--;
						cardsH[m.first] = false;
					}
				}
				blackC -=FIVE;
		case Color::Yellow:
				for(auto m : cardsH){
					if(m.second && board.colorM[m.first] == c && i >0){
						i--;
						cardsH[m.first] = false;
					}
				}
				yellowC -=FIVE;
		}
	}

	string  Researcher::role(){
		return "Researcher";
	}
}