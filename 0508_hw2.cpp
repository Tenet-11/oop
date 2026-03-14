// 0508 HW2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ifstream input_file("text.txt");
    ofstream output_file("answer.txt");

    map<string, int> count;
    string voc;
    while (input_file >> voc) {
        // 跑一次看字首是否為英文
        for (char c : voc) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                count[voc]++;
                break;
            }
            else break;
        }
    }

    for (auto& n : count) {
        // n.first 單字   n.second 次數
        cout << n.first << " 有" << n.second << "個" << endl;
        output_file << n.first << " 有" << n.second << "個" << endl;
    }
    input_file.close();
    output_file.close();
}


