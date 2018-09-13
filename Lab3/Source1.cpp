/*
Assignment:			211.lab3
Description:		Postfix calculator
Author:				David Dahlberg
HSU ID:				013669107
Completion Time:	5-6 hours, solo
*/

#include <iostream>
#include <string>
#include "StringSplitter.h"
#include "Number.h"
#include <stack>

using namespace std;

int main() {

	vector<string> pieces = {}; //for getting pieces from console after stringsplitter
	stack<Number> number_stack = {}; //controlling stack of Numbers
	string exp; //for user console input and stringsplitter processing
	string in;  //for Continue (y/n)
	Number num1, num2; //storing values temporarily when doing operations on top two Numbers on stack
	float operator_result; //for outputting
	bool moar_math_pls = true; //for top menu looping after a Yes response
	bool in_is_bad = true; //for looping bad inputs on (Y/N)
	bool expression_is_good = true;

	while (moar_math_pls) {

		//reset continue (y/n)
		in_is_bad = true;
		expression_is_good = true;

		//clear out number_stack
		while (!number_stack.empty())
		{
			number_stack.pop();
		}

		//take input from user for a string
		cout << "Enter an expression to evaluate: ";
		getline(cin, exp);

		//split exp using Stringsplitter to remove spaces
		StringSplitter ss;
		pieces = ss.split(exp, " ");

		//loop through vector<string> pieces
		for (auto i : pieces)
		{
			//if the string is an operator
			if (i == "+" || i == "-" || i == "*" || i == "/")
			{
				//save the top two Number values, then pop two off number_stack
				if (!number_stack.empty())
				{
					num2 = number_stack.top();
					number_stack.pop();
				}

				if (!number_stack.empty())
				{
					num1 = number_stack.top();
					number_stack.pop();
				}

				else if (number_stack.empty())
				{
					cout << "ERROR - not enough numbers on stack for operation" << endl;
					break;
				}

				float num1_value = num1.getValue();
				float num2_value = num2.getValue();

				if (i == "+")
				{
					cout << "addition! ";
					operator_result = num1_value + num2_value;
					number_stack.push(Number(operator_result));
				}
				else if (i == "-")
				{
					cout << "subtract! ";
					operator_result = num1_value - num2_value;
					number_stack.push(Number(operator_result));
				}
				else if (i == "*")
				{
					cout << "multiply! ";
					operator_result = num1_value * num2_value;
					number_stack.push(Number(operator_result));

				}

				else if (i == "/")
				{
					cout << "divide! ";
					operator_result = num1_value / num2_value;
					number_stack.push(Number(operator_result));
				}
				else
					cout << "ERROR, not an operator, but got past if(i == operator)? -> " << i << endl;
			}

			//must be NOT an operator, likely a number, but is maybe a bad input
			//catch invalid state - not an operator & not a number
			else
			{

				try
				{
					stof(i);
				}
				catch (...)
				{
					cout << "error could not convert i: " << i << endl;
					expression_is_good = false;
				}

				if (expression_is_good)
				{

					//create Number and push onto number_stack
					number_stack.push(Number(i));
				}
				

			}
		}

		//print final answer, should only be stack of 1, any other state is a invalid expression
		//check for invalid states, then if okay, print output_final
		if (number_stack.empty())
		{
			cout << "ERROR - Invalid expression  -  Stack empty at final output" << endl;
		}
		else if (number_stack.size() >= 2)
		{
			cout << "ERROR - Invalid expression  -  Stack size is 2 or more, final calculation. " << endl;
		}
	
		else if (number_stack.size() == 1)
		{

			//output final result and pop because done with this expression 
			//nothing is saved for next expression
			cout << "Final Result: " << operator_result << endl;
			number_stack.pop();
		}

		//for Continue (y/n) functionality
		while (in_is_bad)
		{

			//finished looping through vector<string> pieces
			//output output_result
			cout << "Continue?   (Y/N): ";
			getline(cin, in);

			if (in[0] != 'y' && in[0] != 'Y' && in[0] != 'n' && in[0] != 'N')
			{
				cout << "try again...  " << endl;
				in_is_bad = true;
			}
			else if (in[0] == 'y' || in[0] == 'Y')
			{
				in_is_bad = false;
				moar_math_pls = true;
			}
			else if (in[0] == 'N' || in[0] == 'n')
			{

				//in was good, but less math pls
				in_is_bad = false;
				moar_math_pls = false;
			}
		}
	}
}