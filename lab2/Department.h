#pragma once
#include <iostream>

using namespace std;

class Department {
private:
    char* headLastName;
    int employeeCount;

public:
    Department();
    ~Department();

    void Input();
    void Output();
    int GetEmployeeCount();
};