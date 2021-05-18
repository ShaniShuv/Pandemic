#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "Medic.hpp"

namespace pandemic{
	Medic& Medic::drive(City c){
		if(board.neib[city].count(c) > 0 && c!=city){
			city = c;
			if(board.foundM[board.colorM[c]]){
				board[c] = 0;
			}
			return *this;
		}
		throw std::invalid_argument{" doesn't have sick cubes"};
	}

	Medic& Medic::fly_shuttle(City c){
		if(board.reaserchStation[c] && board.reaserchStation[city] && city != c){
			city = c;
			if(board.foundM[board.colorM[c]]){
				board[c] = 0;
			}
		}
		else{
			throw std::invalid_argument{"nini shuttle"};
		}
		return *this;
	}

	Medic& Medic::fly_direct(City c){
		if(cardsH[c] && c!=city){
			cardsH[c] = false;
			switch (board.colorM[c])
			{
			case Red:
				redC--;
			case Blue:
				blueC--;
			case Black:
				blackC--;
			case Yellow:
				yellowC--;
			}
			city = c;
			if(board.foundM[board.colorM[c]]){
				board[c] = 0;
			}
		}
		else{
			throw invalid_argument{" doesn't have sick cubes"};
		}
		return *this;
	}

	Medic& Medic::fly_charter(City c){
		if(city == c){
			throw invalid_argument{" ..."};
		}
		if(!cardsH[city]){
			throw invalid_argument{"........"};
		}
		cardsH[city] = false;
		switch (board.colorM[city])
		{
		case Red:
			redC--;
		case Blue:
			blueC--;
		case Black:
			blackC--;
		case Yellow:
			yellowC--;
			city = c;
		}
		if(board.foundM[board.colorM[c]]){
			board[c] = 0;
		}
		return *this;
	}
	Medic& Medic::treat(City c){
		if (city != c) {
			throw invalid_argument{"Medic"};
		}
		if (board[c] <= 0) {
			board[c] = 0;
			throw invalid_argument{"Medic"};
		}
		board.cubes[city] = 0;
		return *this;
	}     
	std:: string Medic::role(){
		return "Medic";
	}

}