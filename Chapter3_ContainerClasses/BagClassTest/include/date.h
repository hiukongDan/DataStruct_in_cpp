#ifndef DATE_H
#define DATE_H


class date
{
    public:
        date();
        date(int d, int m, int y);
        virtual ~date();

        void increaseDate();
        void setDate(int d, int m, int y);

        int getDay() const;
        int getMonth() const;
        int getYear() const;

    protected:

    private:
        int day;
        int month;
        int year;

    friend void printDate(const date& d);
};



#endif // DATE_H
