#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <string>

namespace pandemic{


    class Player {
        public:
            int redC, blueC, blackC, yellowC;
            Board &board;
            City city;
            std::map<City, bool> cardsH = 
{{City::Algiers,false},{City::Atlanta, false},{City::Baghdad, false},{City::Bangkok, false},
        {City::Beijing, false},{City::Bogota, false},{City::BuenosAires, false},{City::Cairo, false},{City::Chennai, false},{City::Chicago, false},
        {City::Delhi, false},{City::Essen, false},{City::HoChiMinhCity, false},{City::HongKong, false},{City::Istanbul, false},
        {City::Jakarta, false},{City::Johannesburg, false},{City::Karachi, false},{City::Khartoum, false},{City::Kinshasa, false},{City::Kolkata, false},
        {City::Lagos, false},{City::Lima, false },{City::London, false},{City::LosAngeles, false},{City::Madrid, false},{City::Manila, false},
        {City::MexicoCity, false},{City::Miami, false},
        {City::Milan, false},
        {City::Montreal, false},
        {City::Moscow, false},
        {City::Mumbai, false},
        {City::NewYork, false},
        {City::Osaka, false},
        {City::Paris, false},
        {City::Riyadh, false},
        {City::SanFrancisco, false},
        {City::Santiago, false},{City::SaoPaulo, false},
        {City::Seoul, false},{City::Shanghai, false},{City::StPetersburg, false},{City::Sydney, false},
        {City::Taipei, false},{City::Tehran, false},{City::Tokyo, false },{City::Washington, false }};

            // static const map <City, Color> colorM;

            Player():board(*(new Board())), city(City::Algiers){}
            // Player(Board b, City c);
            Player(Board& b, City c): board(b), city(c) {}
            virtual Player& drive(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual void build(); 
            virtual void discover_cure(Color c);  
            virtual Player& treat(City c);     
            virtual std:: string role();
            Player& take_card (City c);
            void remove_cards();

            
    };
}