#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

string customToLower(string word)
{

	for (unsigned int i = 0; i < word.length(); i++)
		if (word[i] == '�')
		{
			word[i] += 16;
		}
		else if (word[i] >= '�' && word[i] <= '�')
		{
			word[i] += 32;
		}

	return word;
}

char customToUpper(char letter)
{
	if (letter == '�')
	{
		letter -= 16;
	}
	else if (letter >= '�' && letter <= '�')
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
