/*#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

bool search(int item, int size, int arr[])
{
	for (int i = 0; i < size; i++)
		if (arr[i] == item)
			return true;
	return false;
}

bool binarySearch(int item, int size, int arr[])
{
	int low = 0, high = size - 1;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (item > arr[mid])
			low = mid + 1;
		else if (item < arr[mid])
			high = mid - 1;
		else 
			return true;
	}
	return false;
}

int main()
{

	int size = 2000;
	int* arr = new int [size];
	int* sortedArr = new int [size];
	
	for(int i = 0; i< size; i++) {
		arr[i] = rand() % (size * 5);
		sortedArr[i] = arr[i];
	}

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(sortedArr[j] > sortedArr[j+1]) {
				int temp = sortedArr[j];
				sortedArr[j] = sortedArr[j+1];
				sortedArr[j+1] = temp;
			}
	
	//PRINTING
	cout << "PLAIN ARR: ";
	for(int i = 0; i< size; i++)
		cout << setw(5) << arr[i];
	cout << endl;
	cout << "SORTED ARR: ";
	for(int i = 0; i< size; i++)
		cout << setw(5) << sortedArr[i];
	cout << endl;
	
	// PLAIN SEARCH
	time_point begin = steady_clock::now();
	for(int i = 0; i < size; i++) {
		int temp = rand() % (size * 5);
		cout << search(temp, size, arr);
	}
	cout << endl;
	time_point end = steady_clock::now();
	cout << "Time difference in plain search= " << duration_cast<microseconds>(end - begin).count() << "[µs]" << endl;

	// BINARY SEARCH
	begin = steady_clock::now();
	for(int i = 0; i < size; i++) {
		int temp = rand() % (size * 5);
		cout <<  binarySearch(temp, size, sortedArr);
	}
	cout << endl;
	end = steady_clock::now();
	cout << "Time difference in binary search= " << duration_cast<microseconds>(end - begin).count() << "[µs]" << endl;

	return 0;
}*/

#include <iostream>
#include <iomanip>

using namespace std;

void push_back(int size, int* arr, int*arr1)
{
	int* res = new int [size * 2];
	
	for (int i = 0; i < 2 * size; i++)
		res[i] = i < size ? arr[i] : arr1[i];
	
	arr = res;
}

int main()
{
	int size = 10;
	int size1 = 10;
	int* arr = new int [size];
	int* arr1 = new int [size1];
	
	for(int i = 0; i < size; i++)
		arr[i] = 2 * i;
	
	for(int j = 0; j < size1; j++)
		arr1[j] = j;
	
	push_back(size+size1, arr, arr1);
	
	for(int i = 0; i < size * 2; i++)
		cout << setw(3) << arr[i];
	// puch_front(item, arr);
}













