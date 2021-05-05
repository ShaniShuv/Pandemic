#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
using namespace std;
int limkok = 0;
namespace pandemic{
    Board::Board(){}

    int& Board::operator[] (City city){
        return limkok;
    }

    std::ostream& operator<<(std::ostream& out, const Board& b) {
        return out;
    }

    bool Board::is_clean(){
        return true;
    }
    void Board::remove_cures(){}
    // std::ostream& operator <<    (std::ostream &os, const Board &b){return os;}
}
