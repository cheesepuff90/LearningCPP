#include<iostream>
using namespace std;

class Rational
{
public:
	Rational(double value);
	Rational(int denom, int numer);
	void printValue();
	int getNumer();
	int getDenom();
	void setRational(double value);
private:
	int mNumer;
	int mDenom;
};


int gcd(int a, int b)
{
	if (a < b)
		return gcd(b, a);
	else if (a % b == 0)
		return b;
	else return gcd(b, a%b);
}

Rational::Rational(double value)
{
	int comp = (int) value;
	int exp = 1;

	while (comp != value)
	{
		
		value *= 10;
		comp = (int) value;
		exp *= 10;
	}

	int g = gcd(value, exp);
	mDenom = value / g;
	mNumer = exp / g;
}

Rational::Rational(int denom, int numer)
{
	int g = gcd(denom, numer);
	mDenom = denom / g;
	mNumer = numer / g;
}

void Rational::printValue()
{
	cout << mDenom << "/" << mNumer << endl;
}

int Rational::getDenom()
{
	return mDenom;
}

int Rational::getNumer()
{
	return mNumer;
}

void Rational::setRational(double value)
{
	int comp = (int) value;
	int exp = 1;

	while (comp != value)
	{
		
		value *= 10;
		comp = (int) value;
		exp *= 10;
	}

	int g = gcd(value, exp);
	mDenom = value / g;
	mNumer = exp / g;
}


Rational addRational(Rational addend, Rational augend)
{
	double p = (double) addend.getDenom() / (double) addend.getNumer();
	double q = (double) augend.getDenom() / (double) augend.getNumer();
	
	Rational res(p + q);
	
	return res;
}
Rational multiRational(Rational addend, Rational augend)
{
	double p = (double) addend.getDenom() / (double) addend.getNumer();
	double q = (double) augend.getDenom() / (double) augend.getNumer();
	
	Rational multi(p * q);
	
	return multi;
}

Rational arithmeticRational(Rational operand1, Rational operand2, int op)
{
	double p = (double) operand1.getDenom() / (double) operand1.getNumer();
	double q = (double) operand2.getDenom() / (double) operand2.getNumer();
	
	Rational res(1.0);
	switch (op)
	{
		case 0:
		res.setRational(p + q);
			break;
			
		case 1:
		res.setRational(p * q);
			break;
	}
	
	return res;
}

int main()
{
	Rational half(0.5);
	Rational qurd(1, 4);
	half.printValue();
	qurd.printValue();

	Rational add = arithmeticRational(half, qurd, 0);
	add.printValue();
	Rational mul = arithmeticRational(half, qurd, 1);
	mul.printValue();
	
	cout << half << endl;
	cout << half + qurd << endl;
	return 0;
}