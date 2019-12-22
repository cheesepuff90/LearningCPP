#include <iostream>
using namespace std;

class hi
{
	public :
	hi();
	hi(int n);
	void setValue (int n);
	int getValue();
	
	private :
	int value;
};

int main ()
{
	hi h(700), g;
	cout << h.getValue() << endl;
	cout << g.getValue() << endl;
	
	h.setValue(100);
	cout << h.getValue() << endl;

	return 0;
}

int hi::getValue()
{
	return value;
}

void hi::setValue(int n)
{
	value = n;
}

hi::hi()
{
	value = 0;
}

hi::hi(int m)
{
	value = m;
}