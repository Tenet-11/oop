// 0501 HW2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    while (1)
    {
        int N;
        cin >> N;
        if (N == -1) break;
        vector<int> region;

        int found = 0;
        int result = 0;
        for (int m = 1; m <= N; m++) {

            region.clear();
            for (int j = 1; j <= N; j++) {
                region.push_back(j);
            }

            int index = 0;
            while (region.size() > 1) {
                region.erase(region.begin() + index);
                index = (index + m - 1) % region.size();
            }
            if (region[0] == 13) {
                found = 1;
                result = m;
                break;
            }
        }
        if (found == 1) {
            cout << result << endl << endl;
        }
        else cout << "no answer" << endl << endl;
    }
}

