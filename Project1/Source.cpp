#include <iostream>
#include <vector>
#include <process.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> split(string& input, char delimiter)
{
	istringstream stream(input);
	string field;
	vector<string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

int main() {
	ifstream ifs("onsen.csv");
	if (!ifs) {
		cout << "ファイル読み込みエラー" << endl;
		system("pause");
		return -1;
	}

	string line = "";
	getline(ifs, line);
	vector<vector<string>> data;
	for (int i = 0; getline(ifs, line); ++i) {
		auto hoge = split(line, ',');
//		hoge.erase(hoge.begin());
		hoge.erase(hoge.begin());
		data.push_back(hoge);
	}

	
	ofstream outputfile("onsen.txt");
	for (auto hoge : data) {
			outputfile << hoge[0] << "/" << hoge[1]<< ":" << hoge[2] << endl;
	}
	outputfile.close();

	cout << "生成が完了しました。" << endl;
	
	system("pause");

}