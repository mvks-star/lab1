#include "Class.h"
#include <cmath>

using namespace std;

double Calculator::CalculateB(double x, double y, double z){
    double b1 = 1.0 - x / Factorial(1);
    double b2 = pow(y, 2) / Factorial(3);
    double b3 = pow(z, 3) / Factorial(5);
    double b4 = pow(sin(x - z), 2) /  (pow(abs(y), 1.23) + z);

    return b1 + b2 + b3 + b4;
}

double Calculator::CalculateA(double x, double y, double z, double b){
    double a1 = 2.0 * cos(pow(abs(pow(x, 2) - b / 6.0),1.0 / 3.0));
    double a2 = 1.0 + x * b + pow(sin(pow(y, 3)), 2);
    double a3 = pow(log(pow(abs((x + 1.0) / z),1.2)),3);

    return a1 / a2 + a3;
}

double Calculator::Factorial(int n){
    double result = 1.0;

    for (int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}