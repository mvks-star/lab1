#include "Institute.h"
#include <cstring>

Institute::Institute() {
    directorLastName = new char[50];
    strcpy_s(directorLastName, 50, "Unknown");
    departments = nullptr;
    departmentCount = 0;
}

Institute::~Institute() {
    delete[] directorLastName;
    delete[] departments;
}

void Institute::Input() {
    cout << "Enter institute director's last name: ";
    cin >> directorLastName;
    cout << "Enter number of departments in the institute: ";
    cin >> departmentCount;

    departments = new Department[departmentCount];
    for (int i = 0; i < departmentCount; i++) {
        cout << "\n--- Department #" << i + 1 << " ---" << endl;
        departments[i].Input();
    }
}

void Institute::Output() {
    cout << "\nInstitute (Director: " << directorLastName << ")" << endl;
    for (int i = 0; i < departmentCount; i++) {
        departments[i].Output();
    }
}

int Institute::GetTotalEmployees() {
    int total = 0;
    for (int i = 0; i < departmentCount; i++) {
        total += departments[i].GetEmployeeCount();
    }
    return total;
}