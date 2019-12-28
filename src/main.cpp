#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{	
	public:
		Matrix (int row, int col);
		void set(int* m);
		void get() const;
		int getRow();
		int getCol();
		int getItem(int index);
	
	private:
		int mRow;
		int mCol;
		int* mPtr;
	
};

Matrix::Matrix(int row, int col) : mRow(row), mCol(col) { mPtr = new int [row * col]; }

void Matrix::set(int* m)
{
	for(int i = 0; i < mRow * mCol; i++)
		mPtr[i] = m[i];
}
	
void Matrix::get() const
{
	for(int i = 0; i < mRow * mCol; i++)
	{
		cout << mPtr[i] << " ";
		if(i % mCol == mCol - 1)
			cout << endl;
	}
}

int Matrix::getRow() { return mRow; }
int Matrix::getCol() { return mCol; }
int Matrix::getItem(int index) { return mPtr[index]; }

ostream& operator<<(ostream& ostr, Matrix& m)
{
	int row = m.getRow();
	int col = m.getCol();
	
	for(int i = 0; i < row * col; i++)
	{
		ostr << setw(3) << m.getItem(i);
		if(i % col == col - 1)
			ostr << endl;
	}
	return ostr;
}

Matrix operator+(Matrix& lhs, Matrix& rhs)
{
	int row = lhs.getRow();
	int col = lhs.getCol();
	
	int* input = new int [row * col];
	
	for(int i = 0; i < row * col; i++)
		input[i] = lhs.getItem(i) + rhs.getItem(i);
	
	Matrix result(lhs.getRow(), lhs.getCol());
	result.set(input);
	
	return result;
}

Matrix operator*(Matrix& lhs, Matrix& rhs)
{
	int rowl = lhs.getRow();
	int coll = lhs.getCol();
	// int rowr = rhs.getRow();
	int colr = rhs.getCol();
	
	int* input = new int [rowl * colr];
	
	for(int i = 0; i < rowl; i++)
		for(int j = 0; j < colr; j++)
			for(int k = 0; k < coll; k++)
				input[colr * i + j] += lhs.getItem(coll * i + k) * rhs.getItem(colr * k + j);
	
	Matrix result(lhs.getRow(), lhs.getCol());
	result.set(input);
	
	return result;
}

int main()
{
	Matrix mat1(3, 3), mat2(3, 3);
	int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int input2[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	
	mat1.set(input);
	mat2.set(input2);
	
	Matrix result(3, 3);
	result = mat1 * mat2;
	
	cout << result << endl;
	
	return 0;
}