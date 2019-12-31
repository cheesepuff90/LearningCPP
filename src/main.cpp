#include <iostream>
#include <math.h>

using namespace std;

class derivation
{
	public:
	derivation (double x);
	double fact(double x);
	double euler_expo(double x); // e^x
	double getEulerDeriv();
	
	private:
	double mInput;
	double h = 0.00001; // static

};

derivation::derivation (double x) : mInput (x) {}


double derivation::fact(double x)
{
	return x ? x * fact(x - 1) : 1;
}

double derivation::euler_expo(double x)
{
	double e = 0;
	for(int i = 0; i < 100; i++)
		e += 1.0 / fact(i);
	
	return pow(e, x);
}

double derivation::getEulerDeriv()
{
	double res;
	res = (euler_expo(mInput+h) - euler_expo(mInput)) / h;
	
	return res;
}

int main(){
	derivation deriv(5);
	cout << deriv.euler_expo(5) << endl;
	cout << deriv.getEulerDeriv() << endl;
	
	int n;
	n = cin.get();
	cout << n << endl;
	return 0;
	
}
