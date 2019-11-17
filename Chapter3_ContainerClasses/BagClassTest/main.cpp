// FILE: bag_demo.cxx, main.cpp
// This is a small demonstration program showing how the bag class is used.

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

#include "bag1.h"
#include "sequence1.h"
#include "set1.h"
#include "sequence2.h"
#include "bag2.h"
#include "bag3.h"
#include "polynomial1.h"
#include "tic_tac_toe.h"
#include "pokerhand.h"
#include "peg1.h"
#include "towers.h"
#include "big_number.h"
#include "deck_of_cards.h"
#include "sequence3.h"
#include "sequence4.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program.
void get_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family members. These
// ages have been read and placed in the ages bag, stopping when the bag is full or when
// the user types a negative number.

void check_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family members again.
// Each age is removed from the ages bag when it is typed, stopping the bag is empty.


//void get_ages(multiset<int>& ages);
// Postcondition: The user has been prompted to type in the ages of family members. These
// ages have been read and placed in the ages multiset, stopping when the user types a negative number.

//void show_ages(const multiset<int>& ages);
// Postcondition: Show family ages stored in ages multiset in the order player typed. Stopping then
// all the ages have been printed to the screen.

void get_ages(sequence& ages);
// Postcondition: The user has been prompted to type in the ages of family members. These
// ages have been read and placed in the ages sequence, stopping when the sequence is full or when
// the user types a negative numbers.

void show_ages(sequence& ages);
// Postcondition: Show family ages stored in ages sequence in the order player typed. Stopping then
// all the ages have been printed to the screen.

//double average(const multiset<double>& numbers);
// Postcondition: Returns the average value of the numbers stored in the multiset<double>.

bool bag_blackbox_test();
// Postcondition: A black box test for the bag class, where only access members through public member
// functions. Returns true if the test passed, otherwise returns false.

void get_person(person_sequence& friends);
// Postcondition: The user has been prompted to type in his friend's name and birthday. These information
// are placed and stored in sequence friends.

void print_menu();
// Postcondition: Print a menu for friend's birthday recording system.
// Instruct user to enter a choice for later operation.

void get_employee(employee_sequence& employees);
// Postcondition: The user has been prompted to type in an employee's information for recorded to employees
// sequence.

void print_employee_menu();
// Postcondition: Print out a menu for user to operate in Employee Recording System.

void print_employee_modify_menu();
// Postcondition: Print out a sub menu for employee modification.


int main()
{
    /*
    multiset<int> ages;

    get_ages(ages);
    show_ages(ages);

    multiset<double> numbers;
    multiset<int>::const_iterator it;
    for (it = ages.begin(); it != ages.end(); ++it)
        numbers.insert((double)*it);

    double ave = average(numbers);
    cout << "The average age of your family is: " << ave << endl;
    */

    /*
    bag_with_receipts bwr;
    bag_with_receipts::receipt_type receipt1 = bwr.insert(8);
    bag_with_receipts::receipt_type receipt2 = bwr.insert(10);
    bag_with_receipts::receipt_type receipt3 = bwr.insert(10);
    bag_with_receipts::receipt_type receipt4 = bwr.insert(10);

    bwr.remove(receipt2);
    bwr.remove(receipt1);
    receipt2 = bwr.insert(8);
    receipt1 = bwr.insert(39);

    cout << receipt1 << " : " << bwr.retrieve(receipt1) << endl;
    cout << receipt2 << " : " << bwr.retrieve(receipt2) << endl;
    cout << receipt3 << " : " << bwr.retrieve(receipt3) << endl;
    cout << receipt4 << " : " << bwr.retrieve(receipt4) << endl;
    */

    /*
    keyed_bag kb;
    kb.insert(23, 12);
    kb.insert(42, 13);
    kb.remove(12);
    kb.insert(12, 12);
    kb.insert(44, 9);

    cout << 9 << " : " << kb.retrieve(9) << endl;
    cout << 12 << " : " << kb.retrieve(12) << endl;
    cout << 13 << " : " << kb.retrieve(13) << endl;
    */

    /*
    polynomial poly;
    poly.addTerm(23, 1);
    poly.addTerm(1, 0);

    cout << "f(x) = 23x + 1" <<endl;
    cout << "f(2) = " << poly.evaluate(2) << endl;

    polynomial poly2;
    poly2.addTerm(10, 1);
    poly2.addTerm(11, 0);
    poly2.addTerm(4, 2);

    poly += poly2;

    cout << "f(x) = 4x^2+33x+12" << endl;
    cout << "f(2) = " << poly.evaluate(2) << endl;
    */

    /*
    tic_tac_toe playerX('X');
    tic_tac_toe playerO('O');

    playerX.attachComponent(&playerO);
    playerO.attachComponent(&playerX);

    char type = 'X';
    while(!playerX.wonType() || !playerO.wonType())
    {
        if (type == 'X')
        {
            playerX.askMove();
            playerX.printBoard();
        }
        else
        {
            playerO.askMove();
            playerO.printBoard();
        }
        type = type == 'X' ? 'O' : 'X';
    }

    cout << "\n\n" << playerX.wonType() << "won!" << endl;
    */

    /*
    pokerhand ph1, ph2;
    ph1.insert(2);
    ph2.insert(1);
    ph1.insert(7);
    ph2.insert(5);
    ph1.insert(9);
    ph2.insert(9);
    ph1.insert(10);
    ph2.insert(10);
    ph1.insert(11);
    ph2.insert(11);

    if (ph1 >= ph2)
        cout << "pokerhand one is better than pokerhand two." << endl;
    else
        cout << "pokerhand two if better than pokerhand one." << endl;

    cout << "poker hand one value: " << ph1.value() << endl;
    cout << "poker hand two value: " << ph2.value() << endl;
    */

    /*
    peg_stacked_ring peg1(30);
    peg_stacked_ring peg2(20);

    peg1.pop();
    peg1.pop();
    peg1.pop();
    peg1.push(1);

    cout << peg1 << endl;
    cout << peg2 << endl;
    */

    /*
    towers tower(3);
    int start_peg, end_peg;
    while(1)
    {
        cout << tower << endl;
        cout << "Enter peg number to move topmost peg: ";
        cin >> start_peg;
        cout << "Enter peg number to specify destination: ";
        cin >> end_peg;
        tower.move(start_peg, end_peg);
    }
    */

    /*
    big_number bnum1(1234);
    big_number bnum2(-321);
    big_number temp;
    temp = bnum1 + bnum2;
    cout << bnum1 << " + " << bnum2  << " = " << temp << "(" << 1234-321 << ")" << endl;

    bnum1 = big_number(123);
    bnum2 = big_number(234);
    temp = bnum1 + bnum2;
    cout << bnum1 << " + " << bnum2 << " = " << temp << "(" << 123 + 234 << ")" << endl;

    bnum1 = big_number(-123);
    bnum2 = big_number(-34566);
    temp = bnum1 + bnum2;
    cout << bnum1 << " + " << bnum2 << " = " << temp << "(" << -123-34566 << ")" << endl;

    bnum1 = big_number(-12345);
    bnum2 = big_number(43);
    temp = bnum1 + bnum2;
    cout << bnum1 << " + " << bnum2 << " = " << temp << "(" << -12345+43 << ")" << endl;

    bnum1 = big_number(23);
    bnum2 = big_number(-5321);
    temp = bnum1 + bnum2;
    cout << bnum1 << " + " << bnum2 << " = " << temp << "(" << 23-5321 << ")" << endl;

    bnum1 = big_number(-43);
    bnum2 = big_number(53241);
    temp = bnum1 + bnum2;
    cout << bnum1 << " + " << bnum2 << " = " << temp << "(" << -43+53241 << ")" << endl;
    */

    /* TEST for FRIEND BIRTHDAY RECORDING PROGRAM
    person_sequence friends;

    char choice;
    std::string name;
    int index = 0;

    do
    {
        print_menu();
        cin >> choice;
        choice = toupper(choice);
        switch(choice)
        {
        case 'I':
            get_person(friends);
            break;
        case 'R':
            cout << "Please enter your friend's name: " << endl;
            cout << ">> ";
            cin >> name;
            index = friends.find(name);
            if (index > -1)
                displayPerson(friends.current());
            else
                cout << "Not found: " << name << endl;
            break;
        case 'Q':
            cout << "Thanks for using Friends Birthday Recording System, bye!" << endl;
            break;
        default:
            cout << "Invalid operation: " << choice << endl;
            break;
        }
    } while(choice != 'Q');
    */

    employee_sequence employees;

    char choice;
    int id, index;
    char subchoice1, subchoice2;
    employee tempEmployee;
    std::string tempStr;
    float ftemp;
    employee::Sex tempSex;

    do
    {
        print_employee_menu();
        cin >> choice;
        choice = toupper(choice);


        switch(choice)
        {
        case 'I':
            get_employee(employees);
            cout << "Insert successfully!\n" << endl;
            break;
        case 'D':
            cout << "Enter employee's ID: " << endl;
            cin >> id;
            if (employees.find(id) >= 0)
            {
                employees.remove_current();
                cout << "Removed successfully!" << endl;
            }
            else
                cout << "Employee: " << id << " Not Found" << endl;
            cout << endl;
            break;
        case 'M':
            cout << "Enter employee's id: ";
            cin >> id;
            index = employees.find(id);
            if (index < 0)
            {
                cout << "Employee not found" << endl;
                cout << endl;
                break;
            }
            tempEmployee = employees[index];
            cin >> subchoice1;
            subchoice1 = toupper(subchoice1);
            switch(subchoice1)
            {
            case 'N':
                cout << "Enter new name: " << endl;
                cin >> tempStr;
                tempEmployee.setName(tempStr);
                cout << "Name changed successfully" << endl;
                break;
            case 'A':
                cout << "Enter new age: " << endl;
                cin >> ftemp;
                tempEmployee.setAge(ftemp);
                cout << "Age changed successfully" << endl;
                break;
            case 'W':
                cout << "Enter new wage: " << endl;
                cin >> ftemp;
                tempEmployee.setWage(ftemp);
                cout << "Wage changed successfully" << endl;
                break;
            case 'S':
                cout << "Enter new sex(m/f): " << endl;
                cin >> subchoice2;
                subchoice2 = toupper(subchoice2);
                if (subchoice2 == 'M')
                    tempEmployee.setSex(employee::MALE);
                else if (subchoice2 == 'F')
                    tempEmployee.setSex(employee::FEMALE);
                else
                    tempEmployee.setSex(employee::UNDETERMINED);
                cout << "Sex changed successfully" << endl;
                break;
            case 'I':
                cout << "Enter promote rate(in floating number): " << endl;
                cin >> ftemp;
                tempEmployee.increaseSalary(ftemp);
                cout << "Wage increased successfully" << endl;
                break;
            case 'B':
                cout << "Enter paycheck: ";
                cin >> ftemp;
                tempEmployee.setBiweekPaycheck(ftemp);
                cout << "Paycheck recorded successfully" << endl;
                break;
            default:
                break;
            }
            /*
                cout << "\tN: Change name" << endl;
                cout << "\tA: Change age" << endl;
                cout << "\tW: Change wage" << endl;
                cout << "\tS: Change sex" << endl;
                cout << "\tI: Increase wage" << endl;
            */
            break;
        case 'R':
            cout << "Enter employee's id: " << endl;
            cin >> id;
            index = employees.find(id);
            if (index < 0)
            {
                cout << "employee: " << id << " Not Found" << endl;
                break;
            }
            tempEmployee = employees[index];
            cout << "employee ID: " << id << endl;
            cout << "name: " << tempEmployee.getName() << endl;
            cout << "age: " << tempEmployee.getAge() << endl;
            cout << "wage: " << tempEmployee.getWage() << endl;
            cout << "sex: ";
            tempSex = tempEmployee.getSex();
            if (tempSex == employee::MALE)
                cout << "male" << endl;
            else if (tempSex == employee::FEMALE)
                cout << "female" << endl;
            else
                cout << "undetermined" << endl;
            cout << endl;
            break;
        case 'A':
            cout << "Average ages: " << averageAge(employees) << endl;
            break;
        case 'S':
            cout << "Average salaries: " << averageSalaries(employees) << endl;
            break;
        case 'H':
            cout << "Average work hours: " << averageWorkedHours(employees) << endl;
            break;
        case 'F':
            cout << "Radio of Male/Female: " << radioMaleFemale(employees) << endl;
            break;
        case 'Q':
            break;
        default:
            break;
        }

    /*
    I: Insert new entry.
    D: Remove entry.
    M: Modify employee's information.
    R: Retrieve Employee's information.
    A: Calculate average ages.
    S: Calculate average salaries.
    H: Calculate average number of hours worded.
    F: Calculate radio of male/female.
    Q: Quit program.
    */

    } while(choice != 'Q');

    return EXIT_SUCCESS;
}


void get_ages(bag& ages)
{
    int user_input;

    cout << "Type the ages of your family." << endl;
    cout << "Type a negative number when you are done." << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        if (ages.size() < ages.CAPACITY)
            ages.insert(user_input);
        else
            cout << "I have run out of room and can't add that age." << endl;
        cin >> user_input;
    }
}

void check_ages(bag& ages)
{
    int user_input;

    cout << "Type those ages again. Press return after each age:" << endl;
    while(ages.size() > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've found that age and removed it!" << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}


void get_ages(sequence& ages)
{
    cout << "Please type in your family member's ages." << endl;
    cout << "Enter a negative number when you are done." << endl;

    sequence::value_type user_input;
    cin >> user_input;
    while(user_input >= 0)
    {
        ages.attach(user_input);
        cin >> user_input;
    }
}

void show_ages(sequence& ages)
{
    int index = 0;
    for (ages.start(); ages.is_item(); ages.advance())
    {
        cout << index++ << " : " << ages.current() << endl;
    }
}

/*
void get_ages(multiset<int>& ages)
{
    cout << "Please type in your family member's ages." << endl;
    cout << "Enter a negative number when you are done." << endl;

    multiset<int>::value_type user_input;
    cin >> user_input;
    while (user_input >= 0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }
}

void show_ages(const multiset<int>& ages)
{
    multiset<int>::const_iterator it;
    for (it = ages.begin(); it != ages.end(); ++it)
        cout << *it << endl;
}

double average(const multiset<double>& numbers)
{
    assert(numbers.size() > 0);

    double sum = 0;
    multiset<double>::const_iterator it;
    for (it = numbers.begin(); it != numbers.end(); ++it)
        sum += *it;

    return sum / numbers.size();
}
*/

bool bag_blackbox_test()
{
    try
    {
        // test for an empty box
        bag b1;
        b1.erase(1);
        b1.erase_one(1);

        bag b2;
        b1 += b2;

        b1 = b1 + b2;

        b1.insert(1);
        b1.erase(1);
        b1.insert(1);
        b1.erase_one(1);


        b1.insert(1);
        b2.insert(2);

        b1 += b2;
        b1 = b1 + b2;

        b1.erase(1);
        b1.erase(2);
        b2.erase(2);

        for (bag::size_type i = 0; i < bag::CAPACITY; i++)
        {
            b1.insert(1);
            b2.insert(2);
        }

        b1 += b2;
        b1 = b1 + b2;

        b1.insert(1);
    }
    catch(exception e)
    {
        return false;
    }
    return true;
}


void get_person(person_sequence& friends)
{
    int year, month, day;
    date d;
    person p;
    std::string name;
    cout << "Enter your friend's name: ";
    cin >> name;
    cout << "Enter your friend's birthday: " << endl;
    cout << "year: ";
    cin >> year;
    cout << "month: ";
    cin >> month;
    cout << "day: ";
    cin >> day;

    d = date(day, month, year);
    p = person(name, d);
    friends.insert(p);
}



void print_menu()
{
    cout << ">>>The Friend's Birthday Recording System<<<" << endl;
    cout << "Please choose operation:" << endl;
    cout << "I: Insert new entry." << endl;
    cout << "R: Retrieve friend's birthday." << endl;
    cout << "Q: Quit program." << endl;
    cout << "Enter your choice: " << endl;
    cout << ">> ";
}


void get_employee(employee_sequence& employees)
{
    std::string newName;
    double newWage;
    float newAge;
    employee::Sex newSex;
    char sex;
    float biweekPaycheck;

    cout << "Enter your employee's name: ";
    cin >> newName;
    cout << "Enter your employee's hourly wage: ";
    cin >> newWage;
    cout << "Enter your employee's age: ";
    cin >> newAge;
    cout << "Enter your employee's sex(m/f): ";
    cin >> sex;
    cout << "Enter your employee's bi-week paycheck: ";
    cin >> biweekPaycheck;
    sex = toupper(sex);
    if (sex == 'M')
        newSex = employee::MALE;
    else if (sex == 'F')
        newSex = employee::FEMALE;
    else
        newSex = employee::UNDETERMINED;

    employee newEmployee(newName, newWage, newAge, newSex);
    newEmployee.setBiweekPaycheck(biweekPaycheck);
    employees.insert(newEmployee);
}

void print_employee_menu()
{
    cout << ">>>The Employee Recording System<<<" << endl;
    cout << "Please choose operation:" << endl;
    cout << ">> DATA MODIFICATION" << endl;
    cout << "\tI: Insert new entry." << endl;
    cout << "\tD: Remove entry." << endl;
    cout << "\tM: Modify employee's information." << endl;
    cout << ">> INFORMATION RETRIEVAL" << endl;
    cout << "\tR: Retrieve Employee's information." << endl;
    cout << "\tA: Calculate average ages." << endl;
    cout << "\tS: Calculate average salaries." << endl;
    cout << "\tH: Calculate average number of hours worded." << endl;
    cout << "\tF: Calculate radio of male/female." << endl;
    cout << ">> OTHER OPERATIONS" << endl;
    cout << "\tQ: Quit program." << endl;
    cout << "Enter your choice: " << endl;
    cout << ">> ";
}

void print_employee_modify_menu()
{
    cout << ">>>EMPLOYEE MODIFICATION" << endl;
    cout << "Choose your operation" << endl;
    cout << "\tN: Change name" << endl;
    cout << "\tA: Change age" << endl;
    cout << "\tW: Change wage" << endl;
    cout << "\tS: Change sex" << endl;
    cout << "\tI: Increase wage" << endl;
    cout << "\tB: Assign Bi-week Paycheck" << endl;
    cout << "Enter your choice: " << endl;
    cout << ">> ";
}
