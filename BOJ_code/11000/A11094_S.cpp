// BOJ 11094 Simon Says
// ±¸Çö

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	cin.ignore(1);
	while (tc--) {
		string s; getline(cin, s);
		if (s.size() <= 10) continue;
		if (s.substr(0, 10) != "Simon says") continue;
		cout << s.substr(10) << '\n';
	}
}