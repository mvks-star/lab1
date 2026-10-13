#include <iostream>
#include "Salary.h"

using namespace std;

int main() {
    Salary department;
    int choice = 0;

    try {
        do {
            cout << "\nMENU" << endl;
            cout << "1. Input workers" << endl;
            cout << "2. Show all workers" << endl;
            cout << "3. Give bonus (+=)" << endl;
            cout << "4. Hire new worker (+)" << endl;
            cout << "5. Dismiss worker (-)" << endl;
            cout << "6. Search by last name" << endl;
            cout << "7. Search by salary range" << endl;
            cout << "8. Search by position" << endl;
            cout << "0. Exit" << endl;
            cout << "Your choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Invalid choice format.");
            }

            switch (choice) {
            case 1:
                department.Input();
                break;
            case 2:
                department.Output();
                break;
            case 3: {
                double bonus;
                cout << "Enter bonus amount: ";
                if (!(cin >> bonus)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw invalid_argument("Invalid bonus format.");
                }
                department += bonus;
                cout << "Bonus applied!" << endl;
                break;
            }
            case 4: {
                Worker w;
                cout << "Last name: "; cin >> w.lastName;
                cout << "First name: "; cin >> w.firstName;
                cout << "Middle name: "; cin >> w.middleName;
                cout << "Phone: "; cin >> w.phone;
                cout << "Position: "; cin >> w.position;
                cout << "Salary: ";
                if (!(cin >> w.salary)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw invalid_argument("Invalid salary format.");
                }
                department = department + w;
                cout << "New worker added!" << endl;
                break;
            }
            case 5: {
                string name;
                cout << "Enter last name to dismiss: ";
                cin >> name;
                department = department - name;
                cout << "Worker dismissed!" << endl;
                break;
            }
            case 6: {
                string name;
                cout << "Enter last name to search: ";
                cin >> name;
                department.Search(name);
                break;
            }
            case 7: {
                double minS, maxS;
                cout << "Min salary: ";
                if (!(cin >> minS)) { cin.clear(); cin.ignore(10000, '\n'); throw invalid_argument("Invalid min salary."); }
                cout << "Max salary: ";
                if (!(cin >> maxS)) { cin.clear(); cin.ignore(10000, '\n'); throw invalid_argument("Invalid max salary."); }
                department.Search(minS, maxS);
                break;
            }
            case 8: {
                string pos;
                cout << "Enter position: ";
                cin >> pos;
                department.Search(pos, 'p');
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
            }
        } while (choice != 0);

    }
    catch (const exception& e) {
        cout << "\n[ERROR] Exception caught: " << e.what() << endl;
    }

    return 0;
}