#include<iostream>
#include<string>
#include<limits>

void encrypt(std::string &str)
{
    for (size_t i = 0; i < str.size(); ++i) {
        
        if ((tolower(str[i]) - 'a') < 14 {
            str[i] = str[i] + 13;  
        }
        else
        {
            str[i] = str[i] - 13;
        }
    }
    std::cout << str;
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
        std::string str = GetArgument();
        encrypt(str);
	}
}
