#include <iostream>
using namespace std;

int gcd (int a, int b)
{
	int r = 1;
	
	while (r != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	
	return a;
}

int big (int a1, int a2, int b1, int b2)
{
	if (a1*b2 > b1*a2)
		return 1;
	else return 0;
}

int main()
{
	int num[100] = {};
	int i, j, k = 0, x, y, n, nk;
	
	cin >> n;
	
	for (i = 2; i <= n; i++){
		for (j = 1; j < i; j++){
			if (gcd(i, j)== 1){
				num[k++] = j;
				num[k++] = i;
			}
		}
	}
	nk = k;
	
	for(i = 0; i < nk; i += 2){
		for (j = 0; j < nk - i - 2; j += 2){
			if (big(num[j], num[j+1], num[j+2], num[j+3])){
				x = num[j];
				y = num[j+1];
				num [j] = num [j+2];
				num [j+1] = num [j+3];
				num [j+2] = x;
				num [j+3] = y;
			}
		}
	}
	cout << "0/1" << endl;
	
	for (i = 0; i < nk; i+=2){
		cout << num [i] << "/" << num [i+1] << endl;
	}
	
	cout << "1/1" << endl;
	
	return 0;
}