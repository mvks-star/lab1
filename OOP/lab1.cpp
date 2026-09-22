#include <iostream>
#include <iomanip>
#include "Class.h"

using namespace std;

int main(){
    double x = 0.48 * 12;
    double y = 0.47 * 12;
    double z = -1.32 * 12;

    Calculator calc;

    double b = calc.CalculateB(x, y, z);
    double a = calc.CalculateA(x, y, z, b);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "b = " << b << endl;
    cout << "a = " << a << endl;

    cout << endl;
    cout << "Tabulation:" << endl;
    cout << "x\t\ta\t\tb" << endl;

    for (double currentX = -1.0; currentX <= 1; currentX += 0.2){
        double currentB = calc.CalculateB(currentX, y, z);
        double currentA = calc.CalculateA(currentX, y, z, currentB);

       cout << currentX << "\t\t" << currentA << "\t\t" << currentB << endl;
    }
    return 0;
}