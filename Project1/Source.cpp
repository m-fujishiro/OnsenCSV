#include <iostream>
#include <vector>
//ファイル読み込み関連
#include <fstream>
#include <sstream>
#include <iomanip>
//以降はWindows限定含む(使わなくても出来る)
#include <process.h>
#include <conio.h>

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
	//ファイル読み込み
	ifstream ifs("onsen.csv");//ファイル名は任意のファイル名に書き換え
	if (!ifs) {
		//エラー処理
		cout << "ファイル読み込みエラー" << endl;
		system("pause");
		//処理終了
		return -1;
	}

	string line = "";
//	getline(ifs, line);
	vector<vector<string>> data;

	//1行ずつ読み込み、それらを分けてvecter配列に入れていく
	for (int i = 0; getline(ifs, line); ++i) {
		auto hoge = split(line, ',');
//		hoge.erase(hoge.begin());
		hoge.erase(hoge.begin());
		data.push_back(hoge);
	}

	//書き出し
	ofstream outputfile("onsen.txt");
	for (auto hoge : data) {
			outputfile << hoge[0] << "/" << hoge[1]<< ":" << hoge[2] << endl;
	}
	outputfile.close();

	cout << "生成が完了しました。" << endl;
	
	system("pause");

}