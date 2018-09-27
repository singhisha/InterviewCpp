#ifndef Fraction_h
#define Fraction_h

#include<iostream>

class fraction{
private:
	long numerator, denominator;
	//this function is private as gcd will be only used by internal functions of the class
	long gcd(long, long);
public:
	//Constructors
	fraction();
	fraction(long, long);	
	fraction(long);	
	//Destructor	
	~fraction();
	//Overloaded operators
	fraction operator+(fraction);
    fraction operator-(fraction);
    fraction operator*(fraction);
    fraction operator/(fraction);
	bool operator<(fraction);
	bool operator>(fraction);
	bool operator==(fraction);
	//This function reduces the fraction, as 2/4 = 1/2
	void simplify();
	//Getters and setters for the class variables
	long getNum();
	long getDeno();
	void setNum(long);
	void setDeno(long);
};

//non-member function to print the fraction value
void display(fraction);
//non-member function to run the default test cases
void runTestCases();
#endif /* Fraction_h */