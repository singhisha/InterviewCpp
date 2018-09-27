/* Matching pairs
 * You are given a String, input, comprised of alphabetical letters with varying case.
 * These letters should create pairs with one another, based on case. For example, the letter 'N forms a "matching pair' with the letter 'a', in that order.
 * Rules:
 * 1. The first letter must be upper-case.
 * 2. Every upper-case letter must be followed by its lower-case version or any upper-case letter.
 * 3. When an upper-case letter is followed by its lower-case version, those two letters are considered a "matching pair and can then be disregarded from further match consideration.
 * 4. If any of these rules are broken or a lower-case letter is encountered that does not create a "matching pair' with its nearest un-matched left neighbour, that letter and all following letters are considered "un-matched".
 * Output: Your method should return the zero-based index of the last matching lower-case letter, or -1 if no pairs exist.
 * Limits: 0 < input length < 10,000 characters The optimal method has a running time of O(input length).
 * Sample input #1
 * ABba
 * Sample output #1
 * 3
 */
#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
	string mystring;
	cout<< "Enter your string: ";
	cin>>mystring;
	stack<char> mystack;
	mystack.push(mystring[0]);
	int res = 0;
	if(mystring.length() == 0 || islower(mystring[0]))
		return -1;
	for(int i = 1; i< mystring.length(); i++){
		if(islower(mystring[i]) && !mystack.empty()){
			char t = mystack.top();
			if(t == toupper(mystring[i])){
				mystack.pop();
				res = i;
			}
			else if(islower(mystring[i]) && mystack.empty()){
				cout<<res;
				return 0;
			}
			else{
				cout<<res;
				return 0;
			}
				
		}
		else
			mystack.push(mystring[i]);
	}

	cout<< res;
	return 0;
}