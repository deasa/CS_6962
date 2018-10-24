#include<iostream>
#include<string>
#include<limits>
#include<ctype.h>

void ParseInt()
{
    std::string inputString = GetArgument();
    bool sign;
    bool hasSign = false;
    double parsedNum;
    if (inputString[0] == '-'|| inputString[0] == '+') hasSign = true;

    for(size_t i = 0; i < inputString.size(); i++)
    {
        if (hasSign && i == 0) {
            sign = inputString[0] == '+';
            continue;
        }
        else if (isDigit(inputString[i])) {
            parsedNum = parsedNum * 10 + (inputString[i] - '0');
        }
        else
        {
            std::cout << "Parsing failed";
            return;
        }
    }
    if (!sign) {
        parsedNum = 0 - parsedNum;
    }
    std::cout << parsedNum;
}

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
		ParseInt();
	}
}
