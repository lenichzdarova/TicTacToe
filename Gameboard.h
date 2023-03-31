#pragma once
#include <vector>
#include <iostream>
#include "Cell.h"


class Gameboard
{
private:
    CellStatus currentPlayer_ = X;
    std::vector<Cell> cells_{9,Cell()};
    void ChangePlayer();
    void ShowBoard() const;
    void ChooseCell();
    bool EndGameConditionsCheck();
public:
    void Turn();   
};

inline void Gameboard::ShowBoard() const
{
    std::cout << "_____________" << std::endl
              << "| " << cells_[0].Print() << " | " << cells_[1].Print() << " | " << cells_[2].Print() << " |" << std::endl
              << "| " << cells_[3].Print() << " | " << cells_[4].Print() << " | " << cells_[5].Print() << " |" << std::endl
              << "| " << cells_[6].Print() << " | " << cells_[7].Print() << " | " << cells_[8].Print() << " |" << std::endl
              << "-------------" << std::endl;
}
inline void Gameboard::ChangePlayer()
{
    currentPlayer_ = currentPlayer_ == X? O: X;
}
inline void Gameboard::ChooseCell()
{
    unsigned row, column;
    std::cin >> row >> column;
    if(row < 1 || row > 3 || column < 1 || column > 3)
    {
        std::cout << "Wrong choice, try again" << std::endl;
        Turn();
    }
    unsigned index = (row-1) * 3 + column - 1;
    Cell& current = cells_[index];
    if(current.GetStatus()!=Empty)
    {
        std::cout << "Wrong choice, try again" << std::endl;
        Turn();
    }
    else
    {
        current.SetStatus(currentPlayer_);
        if(!EndGameConditionsCheck())
        {
            ChangePlayer();
            Turn(); 
        }        
    }
}
inline void Gameboard::Turn()
{
    std::cout << "Enter row and column to make you turn:" << std::endl;
    ShowBoard();
    ChooseCell();
}

inline bool Gameboard::EndGameConditionsCheck()
{
    auto iter = cells_.begin();    
    for(int i = 0; i < 3; ++i)
    {        
        if(((iter + 3*i)->GetStatus() != Empty && *(iter + 3*i) == *(iter + 3*i+1) && *(iter + 3*i) == *(iter + 3*i + 2))
            || ((iter+i)->GetStatus() != Empty &&*(iter+i) == *(iter + i + 3) && *(iter+i) == *(iter + i + 6))
            || ((*iter).GetStatus() != Empty && *iter == *(cells_.end()-1) && *iter == *(iter + 4))
            || ( (iter+2)->GetStatus()!=Empty && *(iter+2) == *(cells_.end()-3) && *(iter+2) == *(iter + 4)))
        {
            std::cout << currentPlayer_ << " won!" << std::endl;
            return true;
        }
    }
    for(const Cell& c:cells_)
    {
        if(c.GetStatus() == Empty)
        {
            return false;
        }
    }
    std::cout << "Draw" << std::endl;
    return true;
}





