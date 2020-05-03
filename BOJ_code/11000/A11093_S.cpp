// BOJ 11093 Secret Message
// ±¸Çö

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		string str; cin >> str;
		int sz = str.size(), l;
		for (l = 1; l * l < sz; ++l);
		vector<vector<char>> vec(l, vector<char>(l, ' '));
		for (int i = 0; i < sz; ++i)
			vec[i / l][i % l] = str[i];
		for (int j = 0; j < l; ++j)
			for (int i = l - 1; i >= 0; --i)
				if (vec[i][j] != ' ') cout << vec[i][j];
		cout << '\n';
	}
}