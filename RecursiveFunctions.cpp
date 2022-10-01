#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

string customToLower(string word)
{

	for (unsigned int i = 0; i < word.length(); i++)
		if (word[i] == '¨')
		{
			word[i] += 16;
		}
		else if (word[i] >= 'À' && word[i] <= 'ß')
		{
			word[i] += 32;
		}

	return word;
}

char customToUpper(char letter)
{
	if (letter == '¸')
	{
		letter -= 16;
	}
	else if (letter >= 'à' && letter <= 'ÿ')
	{
		letter -= 32;
	}

	return letter;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a = 1;
}
