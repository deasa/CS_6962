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
		num = 0;
		denom = 0;
	}

	Rational(int n, int d)
	{
		num = n;
		denom = d;
		normalize();
		//You will also need to normalize() the number to make sure that GCD(num, denom) == 1 and denom > 0.
	}

	Rational(int n)
	{
		num = n;
		denom = 1;
		//This constructor will need to turn an int into a rational number.
	}

	~Rational()
	{
	}

	Rational operator+(Rational lhs, Rational rhs)
	{
		int lNum, lDenom, rNum, rDenom;
		lNum = lhs.get_numerator();
		lDenom = lhs.get_denominator();
		rNum = rhs.get_numerator();
		rDenom = rhs.get_denominator();
		
		if (lDenom != rDenom) {
			lNum = lNum * rDenom;
			rNum = rNum * lDenom;
			lDenom = lDenom * rDenom;
			rDenom = rDenom * lDenom;
		}
		Rational result = Rational((lNum + rNum), lDenom)
		return result;
	}

	Rational operator-(Rational lhs, Rational rhs)
	{
		int lNum, lDenom, rNum, rDenom;
		lNum = lhs.get_numerator();
		lDenom = lhs.get_denominator();
		rNum = rhs.get_numerator();
		rDenom = rhs.get_denominator();
		
		if (lDenom != rDenom) {
			lNum = lNum * rDenom;
			rNum = rNum * lDenom;
			lDenom = lDenom * rDenom;
			rDenom = rDenom * lDenom;
		}
		Rational result = Rational((lNum - rNum), lDenom)
		return result;
	}

	Rational operator*(Rational lhs, Rational rhs)
	{
		int lNum, lDenom, rNum, rDenom;
		lNum = lhs.get_numerator();
		lDenom = lhs.get_denominator();
		rNum = rhs.get_numerator();
		rDenom = rhs.get_denominator();
		return Rational((lNum * rNum), (lDenom * rDenom));
	}

	Rational operator/(Rational lhs, Rational rhs)
	{
		int lNum, lDenom, rNum, rDenom;
		lNum = lhs.get_numerator();
		lDenom = lhs.get_denominator();
		rNum = rhs.get_numerator();
		rDenom = rhs.get_denominator();
		return Rational((lNum * rDenom), (lDenom * rNum));
	}

	bool operator==(Rational lhs, Rational rhs)
	{
		return lhs.toDecimal() == rhs.toDecimal();
	}

	std::ostream& operator<<(std::ostream& output, Rational a)
	{
		output << num << '/' << denom;
		return output;
	}

	int gcd(int n, int d) 
	{ 
		if (n == 0) 
			return d; 
		return gcd(d % n, n); 
	} 

	int get_numerator()
	{
		return num;
	}

	int get_denominator()
	{
		return denom;
	}

	void normalize()
	{
		while(gcd(num, denom) > 1){
			int divisor = gcd(num, denom);
			num = num / divisor;
			denom = denom / divisor;
		}
		// reduce num and denom until the greatest common denominator is 1
	}

	double toDecimal()
	{
		return num / denom;
	}

	bool operator<(Rational lhs, Rational rhs)
	{
		return toDecimal(lhs) < toDecimal(rhs);
	}
};

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

void RationalOperations()
{
	Rational lhs = Rational(GetArgument(), GetArgument());
	Rational rhs = Rational(GetArgument(), GetArgument());
	std::cout << lhs + rhs + " ";
	std::cout << lhs - rhs + " ";
	std::cout << lhs * rhs + " ";
	std::cout << lhs / rhs + " ";
	std::cout << lhs < rhs + "\n";
	std::cout << lhs.toDecimal() + " ";
	std::cout << rhs.toDecimal() + "\n";
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
       	RationalOperations();
	}
}