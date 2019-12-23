#include <iostream>
using namespace std;

int main()
{
  int n; bool prime = true;
	 
  cin >> n;
	
  for (int i = 2; i <= n / 2; i++)
  {
      if(n % i == 0)
      {
          prime = false;
		  
          break;
      }
  }
  if (prime)
      cout << "소수다" << endl;
  else
      cout << "소수가 아니다" << endl;
	
  return 0;
}