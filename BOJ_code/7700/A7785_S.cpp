// BOJ 7785 회사에 있는 사람
// string sort

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n; cin.ignore(1);

	vector<string> str;
	for (int i = 0; i < n; ++i) {
		string name, move; cin >> name >> move;
		str.push_back(name);
	}
	sort(str.rbegin(), str.rend());

	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && str[i] == str[i + 1]) ++i;
		else cout << str[i] << '\n';
	}
}