#include<iostream>
#include<string>
#include<limits>

void ParseInt()
{
}

int GetNumCases()
{
	int response = 0;
	std::cin >> response;
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return response;
}

std::string GetArgument()
{
	std::string arg;
    std::cin >> arg;
	// std::getline(std::cin, arg);
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
		ParseInt();
	}
}
