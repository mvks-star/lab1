#pragma once
#include "Department.h"

class Institute {
private:
    char* directorLastName;
    Department* departments;
    int departmentCount;

public:
    Institute();
    ~Institute();

    void Input();
    void Output();
    int GetTotalEmployees();
};