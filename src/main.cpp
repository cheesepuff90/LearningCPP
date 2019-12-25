#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	
	int n, sum=0;
	int a[150000];
	bool flag=true;
	
	(cin>>n).get();
	
	for(int i=0;i<n;i++){
		(cin>>a[i]).get();
	}
	
	sum = a[0] > a[1] ? a[0] : a[1];
	
	for(int i = 2; i < n - 1; i++){
		flag = a[i+1] > a[i]; 
		
		if(flag)
			sum += a[i+1] - a[i];
	}
	
	cout<<sum<<endl;
}