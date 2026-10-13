#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Worker {
    string lastName;
    string firstName;
    string middleName;
    string phone;
    string position;
    double salary;
};

class Salary {
private:
    Worker* workers;
    int size;

public:
    Salary();
    ~Salary();
    Salary(const Salary& other);
    Salary& operator=(const Salary& other);

    void Input();
    void Output();

    Salary& operator+=(double bonus);
    Salary operator+(Worker newWorker);
    Salary operator-(string dismissName);

    void Search(string searchLastName);
    void Search(double minSalary, double maxSalary);
    void Search(string searchPosition, char flag);
};