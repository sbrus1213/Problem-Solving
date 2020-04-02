// BOJ 1764 µèº¸Àâ
// ±¸Çö

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	map<string, int> dic;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		dic[s] = 1;
	}
	vector<string> vec;
	for (int i = 0; i < m; ++i) {
		string s; cin >> s;
		if (dic[s]) vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << '\n';
	for (string& s : vec) cout << s << '\n';
}