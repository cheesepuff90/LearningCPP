#include<iostream>
using namespace std;

class number
{
	public:
		number(int num);
		virtual int absolute();
	
	private:
		int mNum;
};

class Rational : public number
{
public:
	Rational(double value);
	Rational(int denom, int numer);
	int getNumer();
	int getDenom();
	void setRational(double value);
	virtual int absolute() override;
	
private:
	int mNumer;
	int mDenom;
};

number::number(int num)
{
	mNum = num;
}
int number::absolute ()
{
	if (mNum < 0)
	{
		return -mNum;
	} else
	{
		return mNum;
	}
}

Rational operator+(Rational& lhs, Rational& rhs)
{
	Rational res(lhs.getNumer()*rhs.getDenom() + rhs.getNumer()*lhs.getDenom(), lhs.getNumer() * rhs.getNumer());
	return res;
}

ostream& operator<<(ostream& ostr, Rational& num)
{
	ostr << num.getDenom() << "/" << num.getNumer();
	return ostr;
}


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

int main()
{
	number n(-10);
	
	Rational half(0.5);
	Rational qurd(1, 4);
	
	cout << n.absolute() << endl;
	cout << half << endl;
	cout << half.absolute() << endl;
	// (half + qurd).printValue();
	//Rational res = half + qurd; 
	//cout << res << endl;
	return 0;
}