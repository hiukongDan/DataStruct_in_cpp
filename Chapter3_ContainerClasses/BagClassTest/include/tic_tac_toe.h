#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <cstdlib>

/*
------------- -*13
| X | O | X |
-------------
| X | O | X |
-------------
| X | O | X |
-------------
*/

class tic_tac_toe
{
    public:
        typedef size_t size_type;

        tic_tac_toe* component;

        tic_tac_toe(char type);
        virtual ~tic_tac_toe();

        void askMove();

        void attachComponent(tic_tac_toe* com);

        void makeMove(size_type row, size_type column);
        void componentMove(size_type row, size_type column);

        char occupiedType(size_type row, size_type column) const;
        char wonType() const;
        void printBoard() const;


    private:
        char playerType;
        char componentType;
        char board[3][3];
};

#endif // TIC_TAC_TOE_H
