#pragma once
#include "Institute.h"

class University {
private:
    char* rectorLastName;
    Institute* institutes;
    int instituteCount;

public:
    University();
    ~University();

    void Input();
    void Output();
    int GetTotalEmployees();
};