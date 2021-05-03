#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	int N;
	cin >> N;

	map<string, int> dict;

	for (int i = 0; i < N; i++) {
		string file;
		cin >> file;

		int dot = file.find('.');
		string ext = file.substr(dot + 1);

		if (dict.find(ext) == dict.end())
			dict[ext] = 0;
		dict[ext]++;
	}

	for (auto it = dict.begin(); it != dict.end(); it++)
		cout << it->first << ' ' << it->second << '\n';

	return 0;
}
