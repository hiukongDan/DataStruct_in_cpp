// FILE: life.cpp
// CLASS implementation: life
// INVARIANT for the class life
//      1. cells has 50x50 space, each has a boolean value, in which true represents life
//      and false represents death
//      2. cell populates with these rules:
//      A live cell dies if it has fewer than two live neighbors.
//      A live cell with two or three live neighbors lives on to the next generation.
//      A live cell with more than three live neighbors dies.
//      A dead cell will be brought back to live if it has exactly three live neighbors.


#include "life.h"
#include <iostream>
#include <algorithm>

using namespace std;

const life::size_type life::ROW_NUM;
const life::size_type life::COL_NUM;
const float life::POLULATION_RATE;

life::life()
{
    clear();
}

life::~life()
{

}

void life::clear()
{
    for (size_type i = 0; i < ROW_NUM; i++)
        for (size_type j = 0; j < COL_NUM; j++)
            cells[i][j] = false;
}

void life::init(int seed)
{
    srand(seed);

    for (size_type i = 0; i < ROW_NUM; i++)
    {
        for (size_type j = 0; j < COL_NUM; j++)
        {
            if ((float)rand() / RAND_MAX < POLULATION_RATE)
                cells[i][j] = true;
            else
                cells [i][j] = false;
        }
    }

}

void life::set_cells(value_type newCells[ROW_NUM][COL_NUM])
{
    copy(newCells[0], newCells[0]+COL_NUM*ROW_NUM, cells[0]);
}

void life::print_cells() const
{
    for (size_type i = 0; i < ROW_NUM; i++)
    {
        for (size_type j = 0; j < COL_NUM; j++)
        {
            if (cells[i][j])
                cout << '+';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

void life::generate()
{
    for (size_type i = 0; i < ROW_NUM; i++)
    {
        for (size_type j = 0; j < COL_NUM; j++)
        {
            life::State s = nextState(i, j);
            if (s == life::DEAD)
                tempCells[i][j] = false;
            else if (s == life::ALIVE)
                tempCells[i][j] = true;
            else
                tempCells[i][j] = false;
        }
    }

    copy(tempCells[0], tempCells[0]+COL_NUM*ROW_NUM, cells[0]);

}

life::State life::nextState(size_type row, size_type col) const
{
    int neighbors = 0;
    size_type left_col = (col + COL_NUM - 1) % COL_NUM;
    size_type right_col = (col + 1) % COL_NUM;
    size_type up_row = (row + ROW_NUM - 1) % ROW_NUM;
    size_type down_row = (row + 1) % ROW_NUM;
    neighbors += cells[row][left_col] ? 1 : 0;
    neighbors += cells[row][right_col] ? 1 : 0;
    neighbors += cells[up_row][col] ? 1 : 0;
    neighbors += cells[down_row][col] ? 1 : 0;
    neighbors += cells[up_row][left_col] ? 1 : 0;
    neighbors += cells[down_row][left_col] ? 1 : 0;
    neighbors += cells[up_row][right_col] ? 1 : 0;
    neighbors += cells[down_row][right_col] ? 1 : 0;

    if (neighbors < 2 || neighbors >= 4)
        return life::DEAD;
    else if (neighbors == 3)
        return life::ALIVE;
    else if (neighbors == 2)
    {
        if (cells[row][col])
            return life::ALIVE;
        else
            return life::DEAD;
    }
    return life::DEAD;
}
