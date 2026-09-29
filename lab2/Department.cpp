#include "Department.h"
#include <cstring>

Department::Department() {
    headLastName = new char[50];
    strcpy_s(headLastName, 50, "Unknown");
    employeeCount = 0;
}

Department::~Department() {
    delete[] headLastName;
}

void Department::Input() {
    cout << "Enter department head's last name: ";
    cin >> headLastName;
    cout << "Enter number of department employees: ";
    cin >> employeeCount;
}

void Department::Output() {
    cout << "  Department Head: " << headLastName << ", Employees: " << employeeCount << endl;
}

int Department::GetEmployeeCount() {
    return employeeCount;
}