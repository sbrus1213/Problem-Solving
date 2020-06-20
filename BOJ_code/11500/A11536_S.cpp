// BOJ 11536 줄 세우기
// string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<string> vs(n);
	for (auto& s : vs) cin >> s;

	int ud = (vs[0] < vs[1] ? 1 : -1);
	for (int i = 2; i < n; ++i) {
		if (ud == 1) {
			if (vs[i - 1] > vs[i]) {
				cout << "NEITHER";
				return 0;
			}
		}
		else {
			if (vs[i - 1] < vs[i]) {
				cout << "NEITHER";
				return 0;
			}
		}
	}
	if (ud == 1) cout << "INCREASING";
	else cout << "DECREASING";
}