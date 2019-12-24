#include<iostream>
using namespace std;

int main()
{
	int N, M;
	
	cin >> N >> M;
	
	int seat[41] = {};
	int vip[41] = {};
	int answer = 1;
	
	for (int i = 1; i < M+1; i++)
	{
		cin >> vip[i];
		
	}
	
	seat[0] = 1;
	seat[1] = 1;
	seat[2] = 2;
	
	for (int j = 3; j <= N; j++)
	{
		seat [j] = seat [j-1] + seat [j-2];
	}
	
	vip [M+1] = N+1;
	
	for (int k = 1; k <= M+1; k++)
	{
		int count = 0;
		for (int z  = vip [k-1] + 1; z < vip [k]; z++)
		
			 count ++;
		
		answer *= seat[count];
	}
	
	cout << answer;
	
}