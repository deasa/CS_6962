#include<iostream>
#include<string>
#include<limits>

int GetNumCases()
{
	int response = 0;
	std::cin >> response;
	return response;
}


std::string GetArgument()
{
	std::string arg;
   std::cin >> arg;
   return arg;
}

void PrintCaseStatement(int i)
{
	std::cout << "Case " << i << ":\n";
}

int main()
{
	int numCases = GetNumCases();
	for(int i = 0; i < numCases; i++)
	{
		PrintCaseStatement(i);
       std::string str = GetArgument();
       encrypt(str);
	}
}