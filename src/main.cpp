#include<iostream>
using namespace std;

int sort(int a[], int x, int y)
{
	int v, i, j, temp;
	v = a[x];
	i = x;
	j = y+1;
	do {
		do{
			i++;
		}while (a[i] < v && i <= y);
		
		do{
			j--;
		}while (v < a[j]);
		
		if (i < j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	while (i < j);
	a[x] = a[j];
	a[j] = v;
	
	return (j);
}

void quickSort (int a[], int x, int y)
{
	int j;
	if (x < y){
		j = sort(a, x, y);
		quickSort(a, x, j-1);
		quickSort(a, j+1, y);
	}
}

int main()
{
	int a[100], n, i;
	cout << "array 개수: ";
	cin >> n;
	cout << "배열 숫자들:\n";
	
	for (i = 0; i < n; i++)
		cin >> a[i];
	quickSort(a, 0, n-1);
	
	cout << "정렬된 숫자들: ";
	
	for (i = 0; i < n; i++)
		cout << " " << a[i];
	
	return 0;
}