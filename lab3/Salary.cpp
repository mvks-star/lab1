#include "Salary.h"
#include <limits>

int readPositiveInt(string prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= 0) {
            return val;
        }
        cout << "Error! Enter a valid non-negative integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readPositiveDouble(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= 0 && val == static_cast<int>(val)) {
            return val;
        }
        cout << "Error! Enter a whole non-negative number (no fractions).\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

Salary::Salary() {
    workers = nullptr;
    size = 0;
}

Salary::~Salary() {
    delete[] workers;
}

Salary::Salary(const Salary& other) {
    size = other.size;
    workers = new Worker[size];
    for (int i = 0; i < size; i++) {
        workers[i] = other.workers[i];
    }
}

Salary& Salary::operator=(const Salary& other) {
    if (this == &other) {
        return *this;
    }
    delete[] workers;
    size = other.size;
    workers = new Worker[size];
    for (int i = 0; i < size; i++) {
        workers[i] = other.workers[i];
    }
    return *this;
}

void Salary::Input() {
    size = readPositiveInt("Enter number of workers: ");

    delete[] workers;
    if (size > 0) {
        workers = new Worker[size];
        for (int i = 0; i < size; i++) {
            cout << "Worker #" << i + 1 << endl;
            cout << "Last name: "; cin >> workers[i].lastName;
            cout << "First name: "; cin >> workers[i].firstName;
            cout << "Middle name: "; cin >> workers[i].middleName;
            cout << "Phone: "; cin >> workers[i].phone;
            cout << "Position: "; cin >> workers[i].position;
            workers[i].salary = readPositiveDouble("Salary: ");
        }
    }
    else {
        workers = nullptr;
    }
}

void Salary::Output() {
    cout << "\n--- LIST OF WORKERS ---" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << workers[i].lastName << " "
            << workers[i].firstName << " " << workers[i].middleName
            << " | Phone: " << workers[i].phone
            << " | Position: " << workers[i].position
            << " | Salary: " << workers[i].salary << endl;
    }
    cout << "-----------------------" << endl;
}

Salary& Salary::operator+=(double bonus) {
    if (bonus < 0) return *this;
    for (int i = 0; i < size; i++) {
        workers[i].salary += bonus;
    }
    return *this;
}

Salary Salary::operator+(Worker newWorker) {
    if (newWorker.salary < 0) {
        throw invalid_argument("New worker salary cannot be negative!");
    }

    Salary temp;
    temp.size = size + 1;
    temp.workers = new Worker[temp.size];

    for (int i = 0; i < size && i < temp.size; i++) {
        temp.workers[i] = workers[i];
    }

    temp.workers[temp.size - 1] = newWorker;

    return temp;
}

Salary Salary::operator-(string dismissName) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (workers[i].lastName == dismissName) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Worker not found for dismissal!" << endl;
        return *this;
    }

    Salary temp;
    temp.size = size - 1;
    if (temp.size > 0) {
        temp.workers = new Worker[temp.size];
        int k = 0;
        for (int i = 0; i < size && k < temp.size; i++) {
            if (i == index) continue;
            temp.workers[k] = workers[i];
            k++;
        }
    }
    else {
        temp.workers = nullptr;
    }
    return temp;
}

void Salary::Search(string searchLastName) {
    bool found = false;
    cout << "\nSearch by last name (" << searchLastName << "):" << endl;
    for (int i = 0; i < size; i++) {
        if (workers[i].lastName == searchLastName) {
            cout << workers[i].lastName << " " << workers[i].firstName << " | Salary: " << workers[i].salary << endl;
            found = true;
        }
    }
    if (!found) cout << "Not found." << endl;
}

void Salary::Search(double minSalary, double maxSalary) {
    if (minSalary > maxSalary) {
        cout << "Invalid range (min > max)." << endl;
        return;
    }
    bool found = false;
    cout << "\nSearch by salary range (" << minSalary << " - " << maxSalary << "):" << endl;
    for (int i = 0; i < size; i++) {
        if (workers[i].salary >= minSalary && workers[i].salary <= maxSalary) {
            cout << workers[i].lastName << " " << workers[i].firstName << " | Salary: " << workers[i].salary << endl;
            found = true;
        }
    }
    if (!found) cout << "Not found." << endl;
}

void Salary::Search(string searchPosition, char flag) {
    bool found = false;
    cout << "\nSearch by position (" << searchPosition << "):" << endl;
    for (int i = 0; i < size; i++) {
        if (workers[i].position == searchPosition) {
            cout << workers[i].lastName << " " << workers[i].firstName << " | Salary: " << workers[i].salary << endl;
            found = true;
        }
    }
    if (!found) cout << "Not found." << endl;
}