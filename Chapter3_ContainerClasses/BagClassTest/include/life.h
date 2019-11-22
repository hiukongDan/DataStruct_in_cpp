// FILE: life.h
// CLASS provided: life
//

#ifndef LIFE_H
#define LIFE_H

#include <cstdlib>

class life
{
    public:
        enum State
        {
            ALIVE,
            DEAD,
            TOTAL_STATE
        };

        typedef bool value_type;
        typedef size_t size_type;
        static const size_type ROW_NUM = 10;
        static const size_type COL_NUM = 20;
        static const float POLULATION_RATE = 0.3;

        life();
        virtual ~life();

        void clear();
        void init(int seed = 0);
        void generate();

        void set_cells(value_type newCells[ROW_NUM][COL_NUM]);

        State nextState(size_type row, size_type col) const;
        void print_cells() const;


    protected:

    private:
        value_type cells[ROW_NUM][COL_NUM];
        value_type tempCells[ROW_NUM][COL_NUM];
};

#endif // LIFE_H
