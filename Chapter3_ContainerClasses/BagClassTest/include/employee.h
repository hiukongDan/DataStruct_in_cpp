#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class employee
{
    public:
        static const double REGULAR_BIWEEK_WORK_HOUR = 40.0f;
        employee();
        virtual ~employee();

        double getYearlySalary() const;
        void increaseSalary(double percentage);
        void setBiweekPaycheck(double paycheck);
        double getOvertime() const;

    private:
        int id;     /* unique number to identify employee */
        double wage;   /* an hour wage */
        double biweek_paycheck;
        double overtime;
        void calculateOvertime();

        static int ID;
        static int genID();
};

#endif // EMPLOYEE_H
