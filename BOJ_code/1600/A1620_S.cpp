// BOJ 1620 나는야 포켓몬 마스터 이다솜
// bst

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
	map<string, int> dic1;
	map<int, string> dic2;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		dic1[s] = i + 1;
		dic2[i + 1] = s;
	}

	for (int i = 0; i < m; ++i) {
		string s; cin >> s;
		if (s[0] <= '9') cout << dic2[stoi(s)] << '\n';
		else cout << dic1[s] << '\n';
	}
}