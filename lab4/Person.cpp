#include "Person.h"

Person::Person() {
    lastName = "None";
    firstName = "None";
    age = 0;
}

Person::~Person() {}

void Person::Input() {
    cout << "Last name: "; cin >> lastName;
    cout << "First name: "; cin >> firstName;
    cout << "Age: ";
    if (!(cin >> age) || age < 0) throw invalid_argument("Invalid age!");
}

void Person::Output() const {
    cout << "Name: " << lastName << " " << firstName << " | Age: " << age;
}

void Person::SaveToFile(ofstream& outFile) const {
    outFile << lastName << " " << firstName << " " << age << " ";
}

void Person::LoadFromFile(ifstream& inFile) {
    inFile >> lastName >> firstName >> age;
}


Sportsman::Sportsman() {
    sportType = "None";
    rank = 0;
}

Sportsman::~Sportsman() {}

void Sportsman::Input() {
    Person::Input();
    cout << "Sport type: "; cin >> sportType;
    cout << "Rank: "; cin >> rank;
}

void Sportsman::Output() const {
    Person::Output();
    cout << " | Sport: " << sportType << " | Rank: " << rank;
}

void Sportsman::SaveToFile(ofstream& outFile) const {
    Person::SaveToFile(outFile);
    outFile << sportType << " " << rank << " ";
}

void Sportsman::LoadFromFile(ifstream& inFile) {
    Person::LoadFromFile(inFile);
    inFile >> sportType >> rank;
}


Teacher::Teacher() {
    subject = "None";
    experience = 0;
}

Teacher::~Teacher() {}

void Teacher::Input() {
    Person::Input();
    cout << "Subject: "; cin >> subject;
    cout << "Experience (years): "; cin >> experience;
}

void Teacher::Output() const {
    Person::Output();
    cout << " | Subject: " << subject << " | Experience: " << experience << " years";
}

void Teacher::SaveToFile(ofstream& outFile) const {
    Person::SaveToFile(outFile);
    outFile << subject << " " << experience << " ";
}

void Teacher::LoadFromFile(ifstream& inFile) {
    Person::LoadFromFile(inFile);
    inFile >> subject >> experience;
}


Trainer::Trainer() {
    teamSize = 0;
}

Trainer::~Trainer() {}

void Trainer::Input() {
    cout << "\n--- Enter Trainer Info ---" << endl;
    Person::Input();
    cout << "Sport type: "; cin >> sportType;
    cout << "Rank: "; cin >> rank;
    cout << "Subject: "; cin >> subject;
    cout << "Experience (years): "; cin >> experience;
    cout << "Team size: "; cin >> teamSize;

    ofstream outFile("trainer.txt");
    if (outFile.is_open()) {
        SaveToFile(outFile);
        outFile.close();
        //cout << "[Info] Data automatically saved to 'trainer.txt'!" << endl;
    }
    else {
        cout << "[Error] Could not create or open file for writing!" << endl;
    }
}

void Trainer::Output() const {
    cout << "\n--- Trainer Info ---" << endl;
    Person::Output();
    cout << " | Sport: " << sportType << " | Rank: " << rank << " | Subject: " << subject << " | Experience: " << experience
    << " years | Team size: " << teamSize << endl;
}

void Trainer::SaveToFile(ofstream& outFile) const {
    Person::SaveToFile(outFile);
    outFile << sportType << " " << rank << " " << subject << " " << experience << " " << teamSize << endl;
}

void Trainer::LoadFromFile(ifstream& inFile) {
    Person::LoadFromFile(inFile);
    inFile >> sportType >> rank >> subject >> experience >> teamSize;
}