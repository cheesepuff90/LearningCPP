// helloworld.cpp

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int size = 1000;
	int* arr = new int[size];
	
	int count = 0;
	
	cout << "enter number";
	cin >> n;
	
	for (int i = 2; i<n; i++)
		for (int j = 2; j<=i; j++){
			if (i%j == 0)
				break;
			else if (j+1 > sqrt(i)){
				arr[count] = i;
				count = count+1;
				break;
			}
		}
	
	for (int i = 0; i < count; i++)
		cout << arr[i] << " ";
	
	return 0;
			
}
