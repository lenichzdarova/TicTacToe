#pragma once

enum CellStatus {
    Empty,
    O,
    X
};

class Cell
{
    friend  bool operator ==(const Cell&,const Cell&);
    friend bool operator != (const Cell&,const Cell&);
    
    CellStatus status_ = Empty;
public:
    void SetStatus(CellStatus);
    CellStatus GetStatus() const;    
    char Print() const;
};

bool operator == (const Cell&,const Cell&);
bool operator != (const Cell&,const Cell&);
