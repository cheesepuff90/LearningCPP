#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;                         
	int array[n][n];
	int len=n,a=1,b=0,i;
	
	while(a<=n*n)                      
	{
		for(i=b;i<len;i++)
		{
			array[b][i]=a++;
		}
		for(i=b+1;i<len;i++)
		{
			array[i][len-1]=a++;
		}
		for(i=len-2;i>=b;i--)
		{
			array[len-1][i]=a++;
		}
		for(i=len-2;i>b;i--)
		{
			array[i][b]=a++;
		}
		b++,len=len-1;
		
	}
	if(!n%2)
	{
		array[(n+1)/2][(n+1)/2]=n*n;
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

