// 0327 hw1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

int main()
{
	int size;
	cout << "Input N: ";
	cin >> size;
	cout << endl;

	Matrix A(size);
	Matrix B(size);
	Matrix C(size);
	Matrix adj(size);

	cout << "Input matrix A: ";
	A.input();
	cout << endl;
	cout << "Input matrix B: ";
	B.input();
	cout << endl;

	while (true) {
		cout << endl;
		cout << "1-Addition" << endl;
		cout << "2-Subtraction" << endl;
		cout << "3-Multiplication" << endl;
		cout << "4-Division" << endl;
		cout << "5-Exit" << endl;
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			C.Addition(&A, &B);
			C.display();
			break;
		}
		case 2: {
			C.Subtraction(&A, &B);
			C.display();
			break;
		}
		case 3: {
			C.Multiplication(&A, &B);
			C.display();
			break;
		}
		case 4: {
			C.Division(&A, &B);
			C.display();
			break;
		}
		case 5: {
			return 0;
		}
		default: {
			break;
		}

		}
	}
}


