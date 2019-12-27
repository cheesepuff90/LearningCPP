#include <iostream>
#include <iomanip>

using namespace std;

class Board
{
	public:
		Board(int height, int width);
		int getWidth();
		int getHeight();
		
		void setSize(int height, int width);

	private:
		int mHeight;
		int mWidth;
};

Board::Board(int height, int width) : mHeight(height), mWidth(width)
{
}

int Board::getHeight()
{
	return mHeight;
}

int Board::getWidth()
{
	return mWidth;
}

void Board::setSize(int height, int width)
{
	mHeight = height;
	mWidth = width;
}

int main()
{
	Board cell(20, 30);
	
	cout << "HEIGHT: " << cell.getHeight() << ", WIDTH: " << cell.getWidth() << endl; // HEIGHT: 20 WIDTH: 30

	cout << setw(3) << "*";
//	cout << cell << endl;
	
	return 0;
}