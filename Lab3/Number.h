#pragma once
#include <string>

using namespace std;

class Number
{
	bool is_valid_number;
	float value;

public:
	Number();
	~Number();
	Number(string s)
	{
		try
		{
			setValue(s);
		}
		catch (...)
		{
			is_valid_number = false;
		}
	};

	Number(float op)
	{
		value = op;
	};
	
	//getters
	float getValue()
	{
		return value;
	}

	//setter
	void setValue(string s)
	{
		value = stof(s);
	}
};