#include "fraction.h"
#include <iostream>
using namespace std;

int main()
{
    Fraction x;
    cout << "Enter numerator and denominator for X: ";
    cin >> x.num;
    cin >> x.den;
    
    Fraction y;
    cout << "Enter numerator and denominator for Y: ";
    cin >> y.num;
    cin >> y.den;
    
    cout << endl;
    
    cout << "ADD: " << x + y << endl;
    cout << "SUB: " << x - y << endl;
    cout << "MUL: " << x * y << endl;
    cout << "DIV: " << x / y << endl; 
}