// #include <iostream>
// #include <iomanip>

// using namespace std;

// class Matrix
// {	
// 	public:
// 		Matrix (int row, int col);
// 		Matrix (int row, int col, int* m);
// 		void set(int* m);
// 		int getRow();
// 		int getCol();
// 		int getItem(int index);
// 		void transpose();
	
// 	private:
// 		int mRow;
// 		int mCol;
// 		int* mPtr;
// };

// Matrix::Matrix(int row, int col) : mRow(row), mCol(col) { mPtr = new int [row * col]; }
// Matrix::Matrix(int row, int col, int* m) : mRow(row), mCol(col) 
// { 
// 	mPtr = new int [row * col]; 
// 	for(int i = 0; i < mRow * mCol; i++)
// 		mPtr[i] = m[i];
// }

// void Matrix::set(int* m)
// {
// 	for(int i = 0; i < mRow * mCol; i++)
// 		mPtr[i] = m[i];
// }

// void Matrix::transpose ()
// {
// 	for(int i = 0; i < mCol; i++ ){
// 		for(int j = 0; j < mRow; j++) {
// 			cout <<	setw(3) << mPtr[mRow*j+i];
// 		}
// 		cout << endl;
// 	}
// }

// int Matrix::getRow() { return mRow; }
// int Matrix::getCol() { return mCol; }
// int Matrix::getItem(int index) { return mPtr[index]; }

// ostream& operator<<(ostream& ostr, Matrix& m)
// {
// 	int row = m.getRow();
// 	int col = m.getCol();
	
// 	for(int i = 0; i < row * col; i++) {
// 		ostr << setw(3) << m.getItem(i);
// 		if(i % col == col - 1)
// 			ostr << endl;
// 	}
// 	return ostr;
// }

// int main()
// {

// 	int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	Matrix mat(3, 3, input);
// 	cout << mat << endl;

// 	mat.transpose();
	
// 	return 0;
// }