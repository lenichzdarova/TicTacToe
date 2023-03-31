#include "Cell.h"

CellStatus Cell::GetStatus() const
{
    return status_;
}
void Cell::SetStatus(CellStatus status)
{
    status_ = status;
}
char Cell::Print() const
{
    char valueToPrint = ' ';
    switch (status_)
    {
        case Empty:
            {
                valueToPrint = ' ';
                break;
            }
        case X:
            {
                valueToPrint = 'X';
                break;
            }
        case O:
            {
                valueToPrint = 'O';
            }        
    }
   return valueToPrint;
}

bool operator==(const Cell& a, const Cell& b)
{
    return a.status_ == b.status_;
}
bool operator!=(const Cell& a , const Cell& b)
{
    return a.status_ != b.status_;
}




