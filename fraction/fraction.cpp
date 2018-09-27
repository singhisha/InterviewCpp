#include<iostream>
#include"fraction.h"

using namespace std;

fraction::fraction(){
	numerator = 0;
	denominator = 1;
}

fraction::fraction(long num){
	numerator = num;
	denominator = 1;
}

fraction::fraction(long num, long deno){
	long divisor = gcd(num, deno);
	numerator = num/abs(divisor);
	denominator = deno/abs(divisor);
}

fraction::~fraction()
{

}

fraction fraction::operator+(fraction f){
	if(numerator == 0)
		return f;
	else if(f.getNum() == 0)
		return fraction(numerator,denominator);
	else{
		fraction answer((numerator * f.getDeno()) + (denominator * f.getNum()), (denominator * f.getDeno()));
		answer.simplify();
		return answer;
	}
}

fraction fraction::operator-(fraction f){
	if(f.getNum() == 0)
		return fraction(numerator,denominator);
	else{
		fraction answer((numerator * f.getDeno()) - (denominator * f.getNum()), (denominator * f.getDeno()));
		answer.simplify();
		return answer;
	}
}

fraction fraction::operator*(fraction f){
	fraction answer((f.getNum()*numerator), (f.getDeno()*denominator));
	answer.simplify();
	return answer;
}

fraction fraction::operator/(fraction f){
	if(numerator == 0)
		return fraction(0,1);
	if(f.getNum() == 0){
		throw "Division by zero condition!";
	}
	fraction answer((f.getDeno()*numerator),(f.getNum()*denominator));
	answer.simplify();
	return answer;
}

bool fraction::operator==(fraction f){
	double first, second;
	if(denominator)
		first = numerator/ (double) denominator;
	else 
		first = 0.0;
	if(f.getDeno())
		second = f.getNum()/ (double) f.getDeno();
	else
		second = 0.0;
	return (first == second);
}

bool fraction::operator<(fraction f){
	double first, second;
	if(denominator)
		first = numerator/ (double) denominator;
	else 
		first = 0.0;
	if(f.getDeno())
		second = f.getNum()/ (double) f.getDeno();
	else
		second = 0.0;
	return (first < second);
}

bool fraction::operator>(fraction f){
	double first, second;
	if(denominator)
		first = numerator/ (double) denominator;
	else 
		first = 0.0;
	if(f.getDeno())
		second = f.getNum()/ (double) f.getDeno();
	else
		second = 0.0;
	return (first > second);
}

long fraction::getNum(){
	return numerator;
}
long fraction::getDeno(){
	return denominator;
}
void fraction::setNum(long n){
	numerator = n;
}
void fraction::setDeno(long d){
	denominator = d;
}

void fraction::simplify(){
	long divisor = fraction::gcd(numerator, denominator);
	if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator > 0)){
		numerator /= divisor;
		denominator /= divisor;
	}
	//Because -1/2 and 1/-2 are the same, simplifying the fraction for more readable output
	else{
		numerator = abs(numerator)/abs(divisor);
		denominator = abs(denominator)/abs(divisor);
		numerator = -numerator;
		denominator = abs(denominator);
	}
}

long fraction::gcd(long a, long b) {
   if ((a % b) == 0)
      return b;
   else
      return gcd(b, a % b);
}

void display(fraction f){
	if(f.getNum() == 0)
		cout<<0 << endl;
	else if(f.getDeno() == 1)
		cout<<f.getNum() << endl;
	else{
		cout<<f.getNum() <<"/"<<f.getDeno() << endl;
	}
}

void runTestCases(){
	cout<<"Running the default test cases:"<<endl;
	fraction f1(1,2);
	fraction f2(2,4);
	display(f1);
	display(f2);
	cout<<"+,-,*,/ operations"<<endl;
	fraction f3;
	f3 = f1 + f2;
	display(f3);
	f3 = f1 - f2;
	display(f3);
	f3 = f1 * f2;
	display(f3);
	f3 = f1/f2;
	display(f3);
	cout<<"..............................."<<endl;
	//Testing equations with multiple operations, follows DMAS
	fraction fx(1,2);
	fraction fy(2,5);
	fraction fz(-1,2);
	display(fx);
	display(fy);
	display(fz);
	cout<<"a * b + c operation"<<endl;
	f3 = fx * (fy + fz);
	display(f3);
	cout<<"a - b + c operation"<<endl;
	f3 = fx - fy + fz;
	display(f3);
	cout<<"..............................."<<endl;
	fraction f4(-1,2);
	fraction f5(-1,4);
	display(f4);
	display(f5);
	cout<<"+,-,*,/ operations"<<endl;
	f3 = f4 + f5;
	display(f3);
	f3 = f4 - f5;
	display(f3);
	f3 = f4 * f5;
	display(f3);
	f3 = f4/f5;
	display(f3);
	cout<<"..............................."<<endl;
	fraction f6(-1,2);
	fraction f7(1,5);
	display(f6);
	display(f7);
	cout<<"+,-,*,/ operations"<<endl;
	f3 = f6 + f7;
	display(f3);
	f3 = f6 - f7;
	display(f3);
	f3 = f6 * f7;
	display(f3);
	f3 = f6/f7;
	display(f3);
	cout<<"..............................."<<endl;
	fraction f8(1,2);
	fraction f9(-1,4);
	display(f8);
	display(f9);
	cout<<"+,-,*,/ operations"<<endl;
	f3 = f8 + f9;
	display(f3);
	f3 = f8 - f9;
	display(f3);
	f3 = f8 * f9;
	display(f3);
	f3 = f8/f9;
	display(f3);
	cout<<"..............................."<<endl;
	//testing the condition when the numerator is zero
	fraction f10(0);
	fraction f11(1,2);
	display(f10);
	display(f11);
	cout<<"+,-,*,/ operations"<<endl;
	f3 = f10 + f11;
	display(f3);
	f3 = f10 - f11;
	display(f3);
	f3 = f10 * f11;
	display(f3);
	f3 = f10/f11;
	display(f3);
	cout<<"..............................."<<endl;
	//testing divide by zero exception
	try{
		fraction f12(1,2);
		fraction f13(0);
		display(f12);
		display(f13);
		cout<<"+,-,*,/ operations"<<endl;
		f3 = f12 + f13;
		display(f3);
		f3 = f12 - f13;
		display(f3);
		f3 = f12 * f13;
		display(f3);
		f3 = f12/f13;
		display(f3);
	}catch(const char* msg){
		cerr<< msg <<endl;
	}
	
}

