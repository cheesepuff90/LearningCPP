#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int n = 0;
	
	while(1){
		if((b-a)==1&&(c-b)==1) break;
		else{
			if((b-a)>(c-b)){
				c = b;
				b = b-1;
			}else{
				a = b;
				b = b+1;
			}
			n++;
		}
	}
	cout<<n<<endl;
	return 0;
}