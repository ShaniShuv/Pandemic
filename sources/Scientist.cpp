#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Scientist.hpp"

namespace pandemic{
	// Scientist::Scientist(Board b, City c, int i){
	//     this->i = i;
	// };
	void Scientist::discover_cure(Color c){
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
		if(!board.reaserchStation[city]){
			throw std::invalid_argument{"Scientist"};
		}
		switch (c)
		{
		case Color::Red:
			if(redC < i){
				throw std::invalid_argument{"S RED"};
			}
		case Color::Blue:
			if(blueC < i){
				throw std::invalid_argument{"S BLUE"};
			}
		case Color::Black:
			if(blackC < i){
				throw std::invalid_argument{"S BLACK"};
			}
		case Color::Yellow:
			if(yellowC < i){
				throw std::invalid_argument{"S YELLOW"};
			}
		}
		if(board.foundM[c]){
			return;
		}
		if(board.reaserchStation[city] ){
			int j = i;
			switch (c)
			{
			case Color::Red:
				board.foundM[c] = true;
			for(auto m : cardsH){
				if(m.second && board.colorM[m.first] == c && j >0){
					j--;
					cardsH[m.first] = false;
				}
			}
			redC -=i;
			case Color::Blue:
				if(blueC >= i){
					board.foundM[c] = true;
					// board[city] = 0;
					// int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && j >0){
							j--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					blueC -=i;
				}
				else{
					throw std::invalid_argument{" S BLUE"};
				}
			case Color::Black:
				if(blackC >= i){
					board.foundM[c] = true;
					// board[city] = 0;
					// int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && j >0){
							j--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					blackC -=i;
				}
				else{
					throw std::invalid_argument{" S BLACK"};
				}
			case Color::Yellow:
				if(yellowC >= i){
					board.foundM[c] = true;
					// board[city] = 0;
					// int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && j >0){
							j--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					yellowC -=i;
				}
				else{
					throw std::invalid_argument{" S YELLOW"};
				}
			}
		}
		else{
			throw std::invalid_argument{" doesn't have sick cubes"};
		}
    }

		
		string  Scientist::role(){
			return "Scientist";
		}

	}