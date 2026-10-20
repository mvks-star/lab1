#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

class Person {
protected:
    string lastName;
    string firstName;
    int age;

public:
    Person();
    Person(string lName, string fName, int a);
    virtual ~Person();

    virtual void Input();
    virtual void Output() const;
    virtual void SaveToFile(ofstream& outFile) const;
    virtual void LoadFromFile(ifstream& inFile);
};

class Sportsman : virtual public Person {
protected:
    string sportType;
    int rank;

public:
    Sportsman();
    Sportsman(string lName, string fName, int a, string sType, int rnk);
    virtual ~Sportsman();

    void Input() override;
    void Output() const override;
    void SaveToFile(ofstream& outFile) const override;
    void LoadFromFile(ifstream& inFile) override;
};

class Teacher : virtual public Person {
protected:
    string subject;
    int experience;

public:
    Teacher();
    Teacher(string lName, string fName, int a, string subj, int exp);
    virtual ~Teacher();

    void Input() override;
    void Output() const override;
    void SaveToFile(ofstream& outFile) const override;
    void LoadFromFile(ifstream& inFile) override;
};

class Trainer : public Sportsman, public Teacher {
private:
    int teamSize;

public:
    Trainer();
    Trainer(string lName, string fName, int a, string sType, int rnk, string subj, int exp, int tSize);
    virtual ~Trainer();

    void Input() override;
    void Output() const override;
    void SaveToFile(ofstream& outFile) const override;
    void LoadFromFile(ifstream& inFile) override;
};