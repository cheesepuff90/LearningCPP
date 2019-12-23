#include<iostream>
using namespace std;

bool divisible (int x, int y)
{
	if(x % y == 0)
		return true;
	else 
		return false;
}

bool prime(int a)
{
	for (int i = a/2; i >1; i--)
		if (divisible(a, i))
			return false;
	
	return a == 1 ? false : true;
}

int main()
{
	int n;
	int a;

	cin >> n;

	    for (a=2; a <= n / 2; a++)
    {
        if ((prime(a)) && (prime(n-a)))
        {
            cout << n << " = " << a << " + " << n-a << endl;
        }
    }

}
