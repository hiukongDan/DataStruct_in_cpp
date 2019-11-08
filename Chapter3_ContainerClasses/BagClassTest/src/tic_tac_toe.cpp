#include "tic_tac_toe.h"

#include <cctype>
#include <cassert>
#include <iostream>

using namespace std;

tic_tac_toe::tic_tac_toe(char type)
{
    playerType = (toupper(type) == 'X' || toupper(type) == 'O') ?
        toupper(type) : 'X';
    componentType = playerType=='X' ? 'O' : 'X';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

tic_tac_toe::~tic_tac_toe()
{
    //dtor
}

void tic_tac_toe::attachComponent(tic_tac_toe* com)
{
    component = com;
}

void tic_tac_toe::askMove()
{
        size_type row = 0, column = 0;
    do
    {
        cout << playerType << " next move: " << endl;
        cout << "row: ";
        cin >> row;
        cout << "column: ";
        cin >> column;
    } while (occupiedType(row, column));

    makeMove(row, column);
    component->componentMove(row, column);
}

void tic_tac_toe::makeMove(size_type row, size_type column)
{
    assert(row < 3 && column < 3);

    if (!board[row][column])
        board[row][column] = playerType;
}

void tic_tac_toe::componentMove(size_type row, size_type column)
{
    board[row][column] = componentType;
}

char tic_tac_toe::occupiedType(size_type row, size_type column) const
{
    assert(row < 3 && column < 3);

    return board[row][column];
}

char tic_tac_toe::wonType() const
{
    for (size_type row = 0; row < 3; row++)
        if (board[row][0] != 0 && board[row][0] == board[row][1] && board[row][1] == board[row][2])
            return board[row][0];

    for (size_type column = 0; column < 3; column++)
        if (board[0][column] != 0 && board[0][column] == board[1][column] && board[2][column] == board[1][column])
            return board[0][column];

    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[2][2] == board[1][1])
        return board[0][0];
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[2][0] == board[1][1])
        return board[2][0];

    return 0;
}

void tic_tac_toe::printBoard() const
{
    for (size_type row = 0; row < 3; row++)
    {
        for (size_type i = 0; i < 13; i++)
            cout << '-';
        cout << endl;
        for (size_type column = 0; column < 3; column++)
            cout << "| " << (board[row][column] != 0 ? board[row][column] : ' ') << " ";
        cout << "|" << endl;
    }
    for (size_type i = 0; i < 13; i++)
        cout << '-';
    cout << endl;
}







