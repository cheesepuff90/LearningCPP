#include <iostream>
using namespace std;

double fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}


double facthelper(int n, double result)
{
	if(n == 0)
		return result;
	else
		return facthelper(n-1, n * result);
}

int fiborecur(int n)
{
	if (n <= 1)
		return n;
	
	else
		return fiborecur (n-1) + fiborecur (n-2);
}


int fibohelper(int a, int b, int n)
{
	if(n == 0){
		return a;
	}
	else{
		return fibohelper (b, a+b, n-1);
	}
}

int fiboiter(int n)
{
	return fibohelper(0, 1, n);
}


int main()
{
	int n;

	while(true) {
		cin >> n;
		cout << fiboiter(n) << endl;
		cout << "ITER" << endl;
		cout << fiborecur(n) << endl;
		cout << "RECU" << endl;

	}
	return 0;
}