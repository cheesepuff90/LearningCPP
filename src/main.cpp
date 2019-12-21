#include <iostream>
#include <math.h>

int main()
{
	int a, b;
	std::cin >> a >> b;
	
	for (int i = a; i >= 2; i--){
		if(a%i == 0 && b%i == 0){
			a /= i;
			b /= i;
		}
	}
	
	while (a != 1){
		
		int x = ceil ((double)b / a);
		std::cout << "1/ " << x << ", ";
		a *= x;
		a -= b;
		b *= x;
		for (int i = a; i >= 2; i--){
			if (a % i== 0 && b%i == 0){
				a/=i;
				b/=i;
			}
		}
	}
	std::cout << "1/ " << b << std::endl;
}