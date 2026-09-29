#include "University.h"5

#include <cstring>

University::University() {
    rectorLastName = new char[50];
    strcpy_s(rectorLastName, 50, "Unknown");
    institutes = nullptr;
    instituteCount = 0;
}

University::~University() {
    delete[] rectorLastName;
    delete[] institutes;
}

void University::Input() {
    cout << "Enter university rector's last name: ";
    cin >> rectorLastName;
    cout << "Enter number of institutes: ";
    cin >> instituteCount;

    institutes = new Institute[instituteCount];
    for (int i = 0; i < instituteCount; i++) {
        cout << "\n========================================" << endl;
        cout << "Institute #" << i + 1 << endl;
        cout << "========================================" << endl;
        institutes[i].Input();
    }
}

void University::Output() {
    cout << "\n================ UNIVERSITY ================" << endl;
    cout << "Rector: " << rectorLastName << endl;
    for (int i = 0; i < instituteCount; i++) {
        institutes[i].Output();
    }
    cout << "\n============================================" << endl;
    cout << "Total number of employees: " << GetTotalEmployees() << endl;
}

int University::GetTotalEmployees() {
    int total = 0;
    for (int i = 0; i < instituteCount; i++) {
        total += institutes[i].GetTotalEmployees();
    }
    return total;
}