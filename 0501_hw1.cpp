// 0501 Hw.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
using namespace std;

class matrix {
private:
    int N;
    vector<vector<int>> data;
public:
    matrix(int size):N(size),data(size,vector<int>(size)){}

    void input() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> data[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    static matrix add(matrix* a, matrix* b) {
        matrix result(a->N);
        for (int i = 0; i < a->N; i++) {
            for (int j = 0; j < a->N; j++) {
                result.data[i][j] = a->data[i][j] + b->data[i][j];
            }
        }
        return result;
    }

    static matrix sub(matrix* a, matrix* b) {
        matrix result(a->N);
        for (int i = 0; i < a->N; i++) {
            for (int j = 0; j < a->N; j++) {
                result.data[i][j] = a->data[i][j] - b->data[i][j];
            }
        }
        return result;
    }

    static matrix mul(matrix* a, matrix* b) {
        matrix result(a->N);
        for (int i = 0; i < a->N; i++) {
            for (int j = 0; j < a->N; j++) {
                for (int k = 0; k < a->N; k++) {
                    result.data[i][j] += a->data[i][k] * b->data[k][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    int N;
    cin >> N;
    matrix a(N), b(N);
    a.input();
    b.input();

    while (1) {
        cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            matrix result = matrix::add(&a, &b);
            result.print();
        }
        else if (choice == 2) {
            matrix result = matrix::sub(&a, &b);
            result.print();
        }
        else if (choice == 3) {
            matrix result = matrix::mul(&a, &b);
            result.print();
        }
        else {
            break;
        }
    }
}
// 注意是 static
