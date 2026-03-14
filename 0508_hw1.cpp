// 0508 HW1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	string search_name;
	cin >> search_name;
	string name, line;

	ifstream input_file ("basic.txt");
	ofstream output_file("output.txt");

	while (1) {
		input_file >> name;
		if (search_name == name) {
			getline(input_file, line);
			string result = name + line;
			cout << result << endl;
			output_file << result << endl;
			break;
		}
		getline(input_file, line);
	}

	input_file.close();
	output_file.close();

}


