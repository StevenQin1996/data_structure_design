#include <iostream>
using namespace std;

// This struct will comprise a Fraction value
struct Fraction {
    int num; // numerator
    int den; // denominator
};

// This calculates greatest common divisor (GCD)
// I expect that you will find it useful
int gcd(int a, int b)
{
    if( b == 0 )
        return a;
    return gcd(b,a%b);
}

// Reduces the given Fraction value lowest possible denominator
void reduce(Fraction &f)
{
   int n=gcd(f.num, f.den);
        f.num=f.num/n;
        f.den=f.den/n;
    
}

// Add the two given Fractions, return the result as a new Fraction (reduced, of course)
Fraction add(Fraction a, Fraction b)
{
    Fraction test;
    if (a.den==b.den)
    {
        test.num=a.num+b.num;
        test.den=a.den;
        if (test.den < 0 && test.num > 0)
                {
                    test.num = -test.num;
                    test.den = -test.den;
                }
              reduce (test);  
        return test;
    }
    else if(a.den<b.den)
    {
        for (int temp=2; temp<b.den;temp++)
        {
            if (a.den*temp==b.den)
            {
                test.num = a.num*temp+b.num;
                test.den = b.den;
                if (test.den < 0 && test.num > 0)
                {
                    test.num = -test.num;
                    test.den = -test.den;
                }
                reduce (test);
                return test;
            }
        }
        test.den = a.den * b.den;
        test.num = a.num *b.den + b.num*a.den;
        if (test.den < 0 && test.num > 0)
                {
                    test.num = -test.num;
                    test.den = -test.den;
                }
               reduce (test); 
        return test;
    }
    else if (b.den<a.den)
    {
        for (int temp=2; temp<a.den;temp++)
        {
            if (b.den*temp==a.den)
            {
                test.num = b.num*temp+a.num;
                test.den = a.den;
                if (test.den < 0 && test.num > 0)
                {
                    test.num = -test.num;
                    test.den = -test.den;
                }
                reduce (test);
                return test;
            }
        }
        test.den = a.den * b.den;
        test.num = a.num *b.den + b.num*a.den;
        if (test.den < 0 && test.num > 0)
                {
                    test.num = -test.num;
                    test.den = -test.den;
                }
                reduce (test);
        return test;
    }
    return test;
}
// Subtract b from a, return the result as a new Fraction (reduced, of course)
Fraction subtract(Fraction a, Fraction b)
{
    Fraction test;
    if (a.den==b.den)
    {
        test.num=a.num-b.num;
        test.den=a.den;
    }
    else if(a.den<b.den)
    {
        for (int temp=2; temp<b.den;temp++)
        {
            if (a.den*temp==b.den)
            {
                test.num = a.num*temp-b.num;
                test.den = b.den;
            }
        }
        test.den = a.den * b.den;
        test.num = a.num * b.den - b.num * a.den;
            }
    else if (b.den<a.den)
    {
        for (int temp=2; temp<a.den;temp++)
        {
            if (b.den*temp==a.den)
            {
                test.num = b.num*temp-a.num;
                test.den = a.den;
    
            }
        }
        test.den = a.den * b.den;
        test.num = a.num *b.den - b.num*a.den;

    }
    reduce(test);
    if(test.den < 0)
    {
        test.num *= -1;
        test.den *= -1;
    }
    return test;
}

// Multiply the two given Fractions, return the result as a new Fraction (reduced, of course)
Fraction multiply(Fraction a, Fraction b)
{
    Fraction test;
    test.num = a.num * b.num;
    test.den = a.den * b.den;
    if (test.den < 0 && test.num > 0)
        {
                    test.num = -test.num;
                    test.den = -test.den;
        }
        reduce (test);
    return test;
}

// Divide given Fractions (a/b), return the result as a new Fraction (reduced, of course)
// You may assume that b will be a non-zero value
Fraction divide(Fraction a, Fraction b)
{
    Fraction test;
    test.num = a.num * b.den;
    test.den = a.den * b.num;
    if (test.den < 0 && test.num > 0)
        {
                    test.num = -test.num;
                    test.den = -test.den;
        }
        reduce (test);
    return test;
}

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
    
    Fraction r;
    
    r = add(x,y);
    cout << "ADD: " << r.num << "/" << r.den << endl;
    
    r = subtract(x,y);
    cout << "SUB: " << r.num << "/" << r.den << endl;
    
    r = multiply(x,y);
    cout << "MUL: " << r.num << "/" << r.den << endl;
    
    r = divide(x,y);
    cout << "DIV: " << r.num << "/" << r.den << endl;   
}