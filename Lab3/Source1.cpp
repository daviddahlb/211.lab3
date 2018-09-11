/*	David Dahlberg
	Lab 3
	
	Postfix calculator

*/

#include <iostream>
#include <string>
#include "StringSplitter.h"
#include <stack>

using namespace std;

int main() {
	
	vector<string> vString; //for getting input from console
	stack<int> stackInt;
	string expression;



	//parse the vector<string> that was returned by StringSplitter
	for (auto i : vString)
	{
		//if number, push onto stack
		//int temp1, temp2;
		int result = 0;
		int mathResult;
		int temp1;
		int temp2;
		bool goodData = false;

		while (goodData = false) {

			//take input from user for a string
			cout << "Enter an expression to evaluate: ";
			getline(cin, expression);

			try
			{
				result = stoi(i);
				cout << "Trying to parse: " << i << endl;
				goodData = true;
			}
			catch (...)
			{
				cout << "could not parse: Trying Arithmetic on top 2 values in stack...";
			}
		}

		//split expression using Stringsplitter
		StringSplitter ss;
		vString = ss.split(expression, " ");

		
		//pop top two and apply the i that could not be parsed
		temp1 = stackInt.top();
		stackInt.pop();
		temp2 = stackInt.top();
		stackInt.pop();
		if (i == "+")
		{
			mathResult = temp1 + temp2;
			stackInt.push(mathResult);
		}
		else if (i == "*")
		{
			cout << "multiply!";
			mathResult = temp1 * temp2;
			stackInt.push(mathResult);

		}
		else if (i == "/")
		{
			cout << "divide!";
			mathResult = temp1 / temp2;
			stackInt.push(mathResult);
		}
		else
			cout << "error";

	stackInt.push(result);
	}
	//debug
	while (stackInt.size() != 0)
	{
		cout << stackInt.top();
		stackInt.pop();
	}
	system("pause");


	//else (must be operator)
		//pop off top two values and apply operator
		//push result onto stack
	//detect invalid states
		//more than one value left in stack after final calculation
		//having too many operations in equation
		//having unexpected input in expression string



		//debug
		//for (auto i : vString) {
		//	cout << "this is in the returned vector string from ss: " << i << endl;
		//}
		//system("pause");



}