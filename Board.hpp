#pragma once
#include <iostream>
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
namespace pandemic{



class Board {
    public:
    Board();
    int& operator[] (City city);
    bool is_clean();
    void remove_cures();
    friend std::ostream& operator <<    (std::ostream &os, const Board &b);
        // double amount;
        // std:: string type;
};
}