#include <iostream>

using namespace std;

int scale(int n)
{
	return n ? 1 + scale(n / 10) : 0;
}

int exp(int n)
{
	return (n - 1) ? 10 * exp(n-1) : 1;
}

int main()
{
	const int segments[10][15] = {
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
		{0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1}
	};

	int input;
	cout << "INPUT: ";
	cin >> input;
	
	cout << "SCALE: " << scale(input) << ", EXP: " << exp(scale(input)) << endl << endl;
	
	int size = scale(input);
	int* foo = new int[size];
	
	for (int i = 0; i < size; i++){
		foo[i] = input / exp(scale(input));
		input = input % exp(scale(input));
	}


	for (int j = 0; j < 5; j++) {
		for (int x = 0; x < size; x++) {
			for (int y = (j * 3); y < (j*3 + 3); y++) {
				if (segments[foo[x]][y] == 1)
					cout << "●";
				else cout << "○";
			}
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}