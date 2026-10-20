#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

int main() {
    Trainer trainer;
    int choice = 0;

    try {
        do {
            cout << "1. Input Trainer data" << endl;
            cout << "2. Show Trainer data" << endl;
            cout << "3. Save Trainer data to file" << endl;
            cout << "4. Load Trainer data from file" << endl;
            cout << "0. Exit" << endl;
            cout << "Your choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Invalid choice format.");
            }

            switch (choice) {
            case 1:
                trainer.Input();
                break;
            case 2:
                trainer.Output();
                break;
            case 3: {
                ofstream outFile("trainer.txt");
                if (!outFile.is_open()) {
                    throw runtime_error("Could not open file for writing!");
                }
                trainer.SaveToFile(outFile);
                outFile.close();
                cout << "Data successfully saved to 'trainer.txt'!" << endl;
                break;
            }
            case 4: {
                ifstream inFile("trainer.txt");
                if (!inFile.is_open()) {
                    throw runtime_error("Could not open file for reading!");
                }
                trainer.LoadFromFile(inFile);
                inFile.close();
                cout << "Data successfully loaded from 'trainer.txt'!" << endl;
                trainer.Output();
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