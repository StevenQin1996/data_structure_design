#include <iostream>
using namespace std;
// Define data type Fraction
struct Fraction {
    int num; // numerator
    int den; // denominator
};

// Calculates greatest common divisor (GCD)
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
Fraction operator+(Fraction a, Fraction b)
{
	Fraction test;
	test.num= a.num*b.den+b.num*a.den;
	test.den= a.den*b.den;
	if(test.den < 0 )
	{
		test.num*= -1;
		test.den*= -1;
	}
	reduce (test);
	return test;
}

// Subtract b from a, return the result as a new Fraction (reduced, of course)
Fraction operator-(Fraction a, Fraction b)
{
	Fraction test;
	test.num= a.num*b.den-b.num*a.den;
	test.den= a.den*b.den;
	if(test.den < 0 )
	{
		test.num*= -1;
		test.den*= -1;
	}
	reduce (test);
	return test;
}

// Multiply the two given Fractions, return the result as a new Fraction (reduced, of course)
Fraction operator*(Fraction a, Fraction b)
{
	Fraction test;
	test.num= a.num*b.num;
	test.den= a.den*b.den;
	if(test.den < 0 )
	{
		test.num*= -1;
		test.den*= -1;
	}
	reduce (test);
	return test;
}

// Divide given Fractions (a/b), return the result as a new Fraction (reduced, of course)
// You may assume that b will be a non-zero value
Fraction operator/(Fraction a, Fraction b)
{
	Fraction test;
	test.num= a.num*b.den;
	test.den= a.den*b.num;
	if(test.den < 0 )
	{
		test.num*= -1;
		test.den*= -1;
	}
	reduce (test);
	return test;
}

// Overload the output operator to allow output of Fractions
ostream& operator<<(ostream &out, Fraction test)
{
    out << test.num<<"/"<<test.den;
    return out;
}
