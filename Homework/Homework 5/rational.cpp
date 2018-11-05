#include<iostream>
#include<string>
#include<limits>
#include<cmath>

int gcd(int n, int d)
{
	n = std::abs(n);
	d = std::abs(d);
	if (n == 0)
		return d;
	return gcd(d % n, n);
}

class Rational {
private:
	int num;
	int denom;
public:
	Rational();
	Rational(int n, int d);
	Rational(int n);

	int get_numerator() const;
	int get_denominator() const;

	void normalize();

	double toDecimal() const;
};

Rational::Rational()
{
	num = 0;
	denom = 0;
}

Rational::Rational(int n, int d)
{
	if (n < 0 && d < 0) 
	{
		num = -n;
		denom = -d;
	}
	else if (n < 0 || d < 0)
	{
		num = ((n < 0) ? n : -n);
		denom = ((d < 0) ? -d : d);
	}
	else
	{
		num = n;
		denom = d;
	}
	normalize();
	//You will also need to normalize() the number to make sure that GCD(num, denom) == 1 and denom > 0.
}

Rational::Rational(int n)
{
	num = n;
	denom = 1;
	//This constructor will need to turn an int into a rational number.
}

int Rational::get_numerator() const
{
	return this->num;
}

int Rational::get_denominator() const
{
	return this->denom;
}

void Rational::normalize()
{
	while (gcd(this->num, this->denom) > 1) {
		int divisor = gcd(this->num, this->denom);
		this->num = this->num / divisor;
		this->denom = this->denom / divisor;
	}
	// reduce num and denom until the greatest common denominator is 1
}

double Rational::toDecimal() const
{
	double n, d;
	n = static_cast<double>(this->num);
	d = static_cast<double>(this->denom);
	double result = n / d;
	return result;
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
		rDenom = lDenom;
	}
	Rational result = Rational((lNum + rNum), lDenom);
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
		rDenom = lDenom;
	}
	Rational result = Rational((lNum - rNum), lDenom);
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

bool operator<(Rational lhs, Rational rhs)
{
	return lhs.toDecimal() < rhs.toDecimal();
}

std::ostream& operator<<(std::ostream& output, Rational a)
{
	output << a.get_numerator() << '/' << a.get_denominator();
	return output;
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

void RationalOperations()
{
	int num, denom;
	num = GetArgument();
	denom = GetArgument();
	Rational lhs = Rational(num, denom);
	num = GetArgument();
	denom = GetArgument();
	Rational rhs = Rational(num, denom);
	std::cout << lhs + rhs << " ";
	std::cout << lhs - rhs << " ";
	std::cout << lhs * rhs << " ";
	std::cout << lhs / rhs << " ";
	std::cout << ((lhs < rhs) ? "true" : "false") << "\n";
	std::cout << lhs.toDecimal() << " ";
	std::cout << rhs.toDecimal() << "\n";
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