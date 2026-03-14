#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string c;
    cin >> c;
    int i = 0;
    int check = 0;

    while (c[i] != '\0') {
        if (c[i] == '(') check++;
        else if (c[i] == ')') check--;
        if (check < 0) {
            cout << "invalid";
            return 0;
        }
        i++;
    }
    if (check == 0) cout << "valid";
    else cout << "invalid";
}
