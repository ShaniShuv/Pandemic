#include "Player.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include <set>
#include <iostream>
using namespace std;
int limkok = 0;
namespace pandemic{
    
    

    Board::Board(){
        colorM = {{Algiers, Black},{City::Atlanta, Color::Blue},{City::Baghdad, Color::Black},
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



cubes = {{City::Algiers,0},{City::Atlanta, 0},{City::Baghdad, 0},{City::Bangkok, 0},
        {City::Beijing, 0},{City::Bogota, 0},{City::BuenosAires, 0},{City::Cairo, 0},{City::Chennai, 0},{City::Chicago, 0},
        {City::Delhi, 0},{City::Essen, 0},{City::HoChiMinhCity, 0},{City::HongKong, 0},{City::Istanbul, 0},
        {City::Jakarta, 0},{City::Johannesburg, 0},{City::Karachi, 0},{City::Khartoum, 0},{City::Kinshasa, 0},{City::Kolkata, 0},
        {City::Lagos, 0},{City::Lima, 0 },{City::London, 0},{City::LosAngeles, 0},{City::Madrid, 0},{City::Manila, 0},
        {City::MexicoCity, 0},{City::Miami, 0},
        {City::Milan, 0},
        {City::Montreal, 0},
        {City::Moscow, 0},
        {City::Mumbai, 0},
        {City::NewYork, 0},
        {City::Osaka, 0},
        {City::Paris, 0},
        {City::Riyadh, 0},
        {City::SanFrancisco, 0},
        {City::Santiago, 0},{City::SaoPaulo, 0},
        {City::Seoul, 0},{City::Shanghai, 0},{City::StPetersburg, 0},{City::Sydney, 0},
        {City::Taipei, 0},{City::Tehran, 0},{City::Tokyo, 0 },{City::Washington, 0 }};
        reaserchStation = {{City::Algiers,false},{City::Atlanta, false},{City::Baghdad, false},{City::Bangkok, false},
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

        foundM = {{Black,false},{Blue, false},{Yellow, false},{Red, false}};
        neib = {{ City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo } },
    { City::Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }};
cout<< " 4 "<<endl;
    }
    int& Board::operator[] (City city){
        return cubes[city];
    }

    std::ostream& operator<<(std::ostream& os, const Board& b) {
        //  os << "\nthe board show: \n";
        // for (auto &element : b.cubes)
        // {
        //     City city_name_1 = element.first;
        //     string cn1 = b.stringM.at(city_name_1);
        //     int city_cube_1 = element.second;
        //     Color city_color_1 = b.colorM.at(city_name_1);
        //     bool station_in = b.reaserchStation.at(city_name_1);
        //     //os
        //     cout << "city " << cn1 << "has number of " << city_cube_1 << " " << city_color_1 << " cubes\n" << endl;
        //     if (station_in)
        //     {
        //         //os
        //         cout << "the city do have a Research station\n";
        //     }
        //     os << "\n";
        // }

        return os;
    }

    bool Board::is_clean(){
        for(const auto& m : cubes)
            {
                int i = m.second;
                if(i > 0)
                {
                    return false;
                }
            }
        return true;
    }
    void Board::remove_cures(){
        for(auto &m : foundM){
            m.second = false;
        }
    }
    void Board::remove_stations(){
        for(auto &m : reaserchStation){
            m.second = false;
        }
    }

    

//    const map <Color, set<City>> colorM =
    
}
