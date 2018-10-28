#include<iostream>
#include<string>
#include<limits>

class LabelGenerator
{
	private:
		std::string labelPref;
		int currIndex;
	public:
		LabelGenerator(std::string &prefix, int start)
		{
			labelPref = prefix;
			currIndex = start;
		}
		LabelGenerator()
		{
		}
		~LabelGenerator()
		{
		}
		std::string next_label() 
		{
			std::string label = labelPref + std::to_string(currIndex);
			currIndex += 1;
			return label;
		}
};

int GetNumCases()
{
	int response = 0;
	std::cin >> response;
	return response;
}

std::string GetStringArgument()
{
	std::string arg;
   std::cin >> arg;
   return arg;
}

int GetIntArgument()
{
   int arg;
   std::cin >> arg;
   return arg;
}

void PrintCaseStatement(int i)
{
	std::cout << "Case " << i << ":\n";
}

void GenerateLabels()
{
	std::string prefix = GetStringArgument();
	int start = GetIntArgument();
	int numIter = GetIntArgument();
	LabelGenerator generator(prefix, start);

	for (size_t i = 0; i < numIter; i++)
	{
		std::cout << generator.next_label() << " ";
	}
	std::cout << "\n";
}

int main()
{
	int numCases = GetNumCases();
	for(int i = 0; i < numCases; i++)
	{
		PrintCaseStatement(i);
		GenerateLabels();
	}
}
