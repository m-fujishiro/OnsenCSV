#include <iostream>
#include <vector>
//�t�@�C���ǂݍ��݊֘A
#include <fstream>
#include <sstream>
#include <iomanip>
//�ȍ~��Windows����܂�(�g��Ȃ��Ă��o����)
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
	//�t�@�C���ǂݍ���
	ifstream ifs("onsen.csv");//�t�@�C�����͔C�ӂ̃t�@�C�����ɏ�������
	if (!ifs) {
		//�G���[����
		cout << "�t�@�C���ǂݍ��݃G���[" << endl;
		system("pause");
		//�����I��
		return -1;
	}

	string line = "";
//	getline(ifs, line);
	vector<vector<string>> data;

	//1�s���ǂݍ��݁A�����𕪂���vecter�z��ɓ���Ă���
	for (int i = 0; getline(ifs, line); ++i) {
		auto hoge = split(line, ',');
//		hoge.erase(hoge.begin());
		hoge.erase(hoge.begin());
		data.push_back(hoge);
	}

	//�����o��
	ofstream outputfile("onsen.txt");
	for (auto hoge : data) {
			outputfile << hoge[0] << "/" << hoge[1]<< ":" << hoge[2] << endl;
	}
	outputfile.close();

	cout << "�������������܂����B" << endl;
	
	system("pause");

}