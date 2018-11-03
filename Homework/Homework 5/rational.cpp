#include<iostream>
#include<string>
#include<limits>

class Rational {
private: 
  int num;
  int denom;
public:
	Rational()
	{
		//default constructor
	}

	Rational(int n, int d)
	{
		//You will also need to normalize() the number to make sure that GCD(num, denom) == 1 and denom > 0.
	}

	Rational(int n)
	{
		//This constructor will need to turn an int into a rational number.
	}

	~Rational()
	{
		//delete num and denom
	}

	Rational Rational::operator+(Rational lhs, Rational rhs)
	{

	}

	Rational operator-(Rational lhs, Rational rhs)
	{

	}

	Rational operator*(Rational lhs, Rational rhs)
	{

	}

	Rational operator/(Rational lhs, Rational rhs)
	{

	}

	bool operator==(Rational lhs, Rational rhs)
	{

	}

	bool operator<(Rational lhs, Rational rhs)
	{
		return toDecimal(lhs) < toDecimal(rhs);
	}

	std::ostream& operator<<(std::ostream& output, Rational a)
	{

	}

	int Rational::get_numerator()
	{
		return num;
	}

	int Rational::get_denominator()
	{
		return denom;
	}

	void normalize()
	{
		// reduce num and denom until the greatest common denominator is 1
	}

	double toDecimal()
	{
		return num / denom;
	}
};





double Rational::toDecimal()
{
	return num / denom;
	//convert the current rational number to decimal format
}

int GetNumCases()
{
	int response = 0;
	std::cin >> response;
	return response;
}

int GetArgument()
{
	int arg;
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
       	encrypt();
	}
}