#include <iostream>
#include "Typedefs.h";

using namespace std;

template<class T>
class Matrix
{
public:
	Matrix(int rows_m, int column_n=-1);
	~Matrix();
	int Rows();
	int Columns();
	void FauInit(int n);
	friend std::ostream& operator<< <>(std::ostream& os, const Matrix<T>& mat);
	friend Matrix<T>& operator + <>(const Matrix<T>& A, const Matrix<T>& B);
private:
	int _m;
	int _n;
	T** _mat;
	void init(int m, int n);
};

template<class T>
Matrix<T>::Matrix(int rows_m, int column_n)
{
	_n = (column_n == -1) ? rows_m : column_n;
	_m = rows_m;

	_mat = new T*[_m];
	for (int i = 0; i < _m; i++){
		_mat[i] = new T[_n];
	}
}
template<class T>
Matrix<T>::~Matrix()
{
}

template<class T>
void Matrix<T>::FauInit(int n){
	for (int i = 0; i < _m; i++){
		for (int j = 0; j < _n; j++){
			_mat[i][j] = n;
		}
	}
}


template<class T>
std::ostream& operator<< (std::ostream& os, const Matrix<T>& mat){
	for (int i = 0; i < mat._m; i++){
		for (int j = 0; j < mat._n; j++){
			os<<mat._mat[i][j]<<" ";
		}
		os << endl;
	}
	return os;
}

template<class T>
Matrix<T>& operator + (const Matrix<T>& A, const Matrix<T>& B){
	//if (A == NULL || B == NULL) return NULL;
	//if (A._m != B._m || A._n != B._n) return ;

	Matrix<T> C(A._m, B._n);

	for (int i = 0; i < C._m; i++){
		for (int j = 0; j < C._n; j++){
			C._mat[i][j] = A._mat[i][j] + B._mat[i][j];
		}
	}
	return C;
}

//int main(){
//	Matrix<int> A(3),B(3);
//	A.FauInit(7);
//	B.FauInit(1);
//	Matrix<int> C = A + B;
//	Int32 a = 12;
//	cout << C << endl;
//
//}