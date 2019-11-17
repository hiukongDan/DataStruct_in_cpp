#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class employee
{
    public:
        enum Sex
        {
            MALE,
            FEMALE,
            UNDETERMINED
        };

        static const double REGULAR_BIWEEK_WORK_HOUR = 40.0f;
        employee();
        employee(std::string newName, double newWage, float newAge, Sex newSex);
        virtual ~employee();

        double getYearlySalary() const;
        void increaseSalary(double percentage);
        void setBiweekPaycheck(double paycheck);
        void setAge(float a);
        void setSex(Sex s);
        void setName(std::string n);
        void setWage(float newWage);

        double getOvertime() const;
        float getAge() const;
        Sex getSex() const;
        int getID() const;
        std::string getName() const;
        float getWage() const;
        double getWorkedHours() const;


    private:
        int id;     /* unique number to identify employee */
        double wage;   /* an hour wage */
        double biweek_paycheck;
        double overtime;
        float age;
        Sex sex;
        std::string name;

        void calculateOvertime();

        static int ID;
        static int genID();
};

bool operator ==(const employee& e1, const employee& e2);
bool operator !=(const employee& e1, const employee& e2);
bool operator >(const employee& e1, const employee& e2);
bool operator <(const employee& e1, const employee& e2);
bool operator >=(const employee& e1, const employee& e2);
bool operator <=(const employee& e1, const employee& e2);

#endif // EMPLOYEE_H
