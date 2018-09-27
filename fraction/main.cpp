#include<iostream>
#include"fraction.h"

using namespace std;

int main(){
	int input;
	char loop;
	long num1, num2, deno1, deno2;
	do{
		cout<<"Press 1 to run default test cases" <<endl;
		cout<<"Press 2 to run custom cases" << endl;
		cin>>input;
		if(input == 1){
			runTestCases();
		}
		else if(input == 2){
			cout<<"Enter two numbers:"<<endl;
			cout<<"Enter numerator and denominator for fraction1:"<<endl;
			cin>>num1;
			cin>>deno1;
			while(deno1 == 0){
				cout<<"denominator can't be zero, enter again"<<endl;
				cin>>deno1;
			}
			cout<<"Enter numerator and denominator for fraction2:"<<endl;
			cin>>num2;
			cin>>deno2;
			while(deno2 == 0){
				cout<<"denominator can't be zero, enter again"<<endl;
				cin>>deno2;
			}
			fraction fraction1(num1, deno1);
			fraction fraction2(num2, deno2);
			cout<<"Fraction1: "<<fraction1.getNum()<<"/"<<fraction1.getDeno()<<endl;
			cout<<"Fraction2: "<<fraction2.getNum()<<"/"<<fraction2.getDeno()<<endl;
			fraction fraction3;
			cout << "Choose operation:" << std::endl;
    		cout << "1 : addition(+)" << std::endl;
    		cout << "2 : substraction(-)" << std::endl;
    		cout << "3 : multiplication(*)" << std::endl;
    		cout << "4 : division(/)" << std::endl;
    		cout << "5 : comparison" << std::endl;
    		int op;
			cin>>op;
			while(op<1 || op>5){
				cout<<"Enter the value again:"<<endl;
				cin>>op;
			}

			switch(op){
				case 1: cout<<"Adding ";
						cout<<"Fraction1: "<<fraction1.getNum()<<"/"<<fraction1.getDeno()<<" and Fraction2: "<<fraction2.getNum()<<"/"<<fraction2.getDeno()<<endl;					
						fraction3 = fraction1 + fraction2;
						display(fraction3);
						break;
				case 2: cout<<"Subtracting "<<endl;
						cout<<"Fraction1: "<<fraction1.getNum()<<"/"<<fraction1.getDeno()<<" and Fraction2: "<<fraction2.getNum()<<"/"<<fraction2.getDeno()<<endl;	
						fraction3 = fraction1 - fraction2;
						display(fraction3);
						break;
				case 3: cout<<"Multiplying "<<endl;
						cout<<"Fraction1: "<<fraction1.getNum()<<"/"<<fraction1.getDeno()<<" and Fraction2: "<<fraction2.getNum()<<"/"<<fraction2.getDeno()<<endl;	
						fraction3 = fraction1 * fraction2;
						display(fraction3);
						break;
				case 4: cout<<"Dividing "<<endl;
						cout<<"Fraction1: "<<fraction1.getNum()<<"/"<<fraction1.getDeno()<<" and Fraction2: "<<fraction2.getNum()<<"/"<<fraction2.getDeno()<<endl;	
						try{
							fraction3 = fraction1 / fraction2;
							display(fraction3);
						}catch(const char* msg){
							cerr<< msg <<endl;
						}
						break;
				case 5: cout<<"Comparing "<<endl;
						cout<<"Fraction1: "<<fraction1.getNum()<<"/"<<fraction1.getDeno()<<" and Fraction2: "<<fraction2.getNum()<<"/"<<fraction2.getDeno()<<endl;	
						if(fraction1 < fraction2)
							cout<<"fraction2 is greater than fraction1"<<endl;
						else if(fraction1 > fraction2)
							cout<<"fraction1 is greater than fraction2"<<endl;
						else if(fraction1 == fraction2)
							cout<<"fraction1 is equal to fraction2"<<endl;
						break;
			}
		}
		cout<<"Do you want to continue(y/n)?"<<endl;
		cin>>loop;
	}while(loop != 'n');
	return 0;
}

