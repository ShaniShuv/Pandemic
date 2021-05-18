#include <iostream>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include <set>
#include "Player.hpp"
#include "Board.hpp" 
const int FIVE = 5;
namespace pandemic{
	const map <City, Color> colorM = {{City::Algiers, Color::Black},
			{City::Atlanta, Color::Blue},
			{City::Baghdad, Color::Black}, 
			{City::Bangkok, Color::Red}, 
			{City::Beijing, Color::Red},
			{City::Bogota, Color::Yellow},
			{City::BuenosAires, Color::Yellow},
			{City::Cairo, Color::Black},
			{City::Chennai, Color::Black}, 
			{City::Chicago, Color::Blue}, 

			{City::Delhi, Color::Black},
			{City::Essen, Color::Blue},
			{City::HoChiMinhCity, Color::Red},
			{City::HongKong, Color::Red},
			{City::Istanbul, Color::Black},
			{City::Jakarta, Color::Red},
			{City::Johannesburg, Color::Yellow},
			{City::Karachi, Color::Black},
			{City::Khartoum, Color::Yellow},
			{City::Kinshasa, Color::Yellow},
			{City::Kolkata, Color::Black},
			{City::Lagos, Color::Yellow},
			{City::Lima, Color::Yellow },
			{City::London, Color::Blue},
			{City::LosAngeles, Color::Yellow},
			{City::Madrid, Color::Blue},
			{City::Manila, Color::Red},
			{City::MexicoCity, Color::Yellow},
			{City::Miami, Color::Yellow},
			{City::Milan, Color::Blue},
			{City::Montreal, Color::Blue},
			{City::Moscow, Color::Black},
			{City::Mumbai, Color::Black},
			{City::NewYork, Color::Blue},
			{City::Osaka, Color::Red},
			{City::Paris, Color::Blue},
			{City::Riyadh, Color::Black},
			{City::SanFrancisco, Color::Blue},
			{City::Santiago, Color::Yellow},
			{City::SaoPaulo, Color::Yellow},
			{City::Seoul, Color::Red},
			{City::Shanghai, Color::Red},
			{City::StPetersburg, Color::Blue},
			{City::Sydney, Color::Red},
			{City::Taipei, Color::Red},
			{City::Tehran, Color::Black},
			{City::Tokyo, Color::Red },
			{City::Washington, Color::Blue }}; 

	Player& Player::drive(City c){
		// cout << "city: "<< board.stringM[city]<< " c: "<<board.stringM[c]<<endl;
		if(board.neib[city].count(c) > 0 && c!=city){
			city = c;
		}
		else{
			throw std::invalid_argument{" player drive"};
		}
		// cout << board << endl;
		return *this;
	}

	Player& Player::fly_direct(City c){
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
		}
		else{
			throw invalid_argument{" Player::fly_direct"};
		}
		// cout << board << endl;
		return *this;
	} 

	Player& Player::fly_charter(City c){
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
		}
		// cout << board << endl;
        city = c;
		return *this;
	}

	Player& Player::fly_shuttle(City c){
		if(board.reaserchStation[c] && board.reaserchStation[city] && city != c){
			city = c;
		}
		else{
			throw std::invalid_argument{"nini shuttle"};
		}
		// cout << board<< endl;
		return *this;
	}

	void Player::build(){
        // if(board.reaserchStation[city]){
		// 	return;
		// }
        if(!cardsH[city]){
            throw std::invalid_argument{"nini build "+ board.stringM[city]};
        }
		if(board.reaserchStation[city]){
			return;
		}
		if(cardsH[city]){
			// board.cardAvailable[city] = true;
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
			}
			board.reaserchStation[city] = true;
		}
		else{
			throw std::invalid_argument{" p build doesn't have sick cubes"};
		}
		// cout << board << endl;
	}

	void Player::discover_cure(Color c){
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
			throw std::invalid_argument{"Player dis cure"};
		}
		switch (c)
		{
		case Color::Red:
			if(redC < FIVE){
				throw std::invalid_argument{" dis cure 1"};
			}
		case Color::Blue:
			if(blueC < FIVE){
				throw std::invalid_argument{"  dis cure 2"};
			}
		case Color::Black:
			if(blackC < FIVE){
				throw std::invalid_argument{ "dis cure 3 "};
			}
		case Color::Yellow:
			if(yellowC < FIVE){
				throw std::invalid_argument{" dis cure 4"};
			}
		}
		if(board.foundM[c]){ 
			return;
		}
		if(board.reaserchStation[city] ){
			switch (c)
			{
			case Color::Red:
				if(redC > 4){
					board.foundM[c] = true;
					// board[city] = 0;
					int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && i >0){
							i--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					redC -=FIVE;
				}else{
					throw std::invalid_argument{" doesn't have RED  "};
				}
			case Color::Blue:
				if(blueC > 4){
					board.foundM[c] = true;
					// board[city] = 0;
					int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && i >0){
							i--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					blueC -=FIVE;
				}
				else{
					throw std::invalid_argument{" doesn't have BLUE"};
				}
			case Color::Black:
				if(blackC > 4){
					board.foundM[c] = true;
					// board[city] = 0;
					int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && i >0){
							i--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					blackC -=FIVE;
				}
				else{
					throw std::invalid_argument{" doesn't have BLACK"};
				}
			case Color::Yellow:
				if(yellowC > 4){
					board.foundM[c] = true;
					// board[city] = 0;
					int i = FIVE;
					for(auto m : cardsH){
						if(m.second && board.colorM[m.first] == c && i >0){
							i--;
							cardsH[m.first] = false;
							// board.cardAvailable[m.first] = true;
						}
					}
					yellowC -=FIVE;
				}
				else{
					throw std::invalid_argument{" doesn't have YELLOW"};
				}
			}
		}
		else{
			throw std::invalid_argument{" doesn't have ANY sick cubes"};
		}
		// cout << board << endl;
	}


	Player& Player::treat(City c){
		if(city != c){
			throw std::invalid_argument{"p treat 1 doesn't have sick cubes"};
		}
		if(board[c] <= 0){
            board[c] = 0;
			throw std::invalid_argument{" p treat doesn't have sick cubes"};
		}
		if (board.foundM[board.colorM[c]]) {
			board[c] = 0;
		}
		else{
			board[c]--;
		}
		// cout << board << endl;
		return *this;
	} 

	string Player::role(){
		return "player";
	}

	Player& Player::take_card (City c){
        if(cardsH[c]){
            return *this;
        }
		cardsH[c] = true;
		Color color = colorM.at(c);
		switch (color)
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
		// cout << board << endl;
		return *this;
	}

	void Player::remove_cards(){
		City tempC = city;
		for(auto m : cardsH){
			cardsH[tempC] = false;
			tempC = m.first;
			//    board.cardAvailable[tempC] = true;

		} 
		cardsH[tempC] = false;
        redC = 0; blueC = 0; blackC = 0; yellowC = 0;

	}
	ostream& operator<<(std::ostream& os, const Player& p) {
		os <<" Player in city " << p.board.stringM.at(p.city)<< endl;
		os << "\nthe board show: \n";
		for (auto element : p.cardsH)
		{
			if(element.second){
				City city_name_1 = element.first;
				string cn1 = p.board.stringM.at(city_name_1);
				//os
				os << cn1;
				os << "\n\n";
			}
		}

		return os;
	}

}

