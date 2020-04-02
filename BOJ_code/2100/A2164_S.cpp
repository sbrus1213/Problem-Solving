// BOJ 2164 Ä«µå 2
// simulation

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, j = 1; cin >> n;
	vector<int> v, t;
	for (int i = 1; i <= n; ++i) v.push_back(i);
	while (v.size() > 1) {
		for (int i = j; i < v.size(); i += 2)
			t.push_back(v[i]);
		if (v.size() % 2) j = 1 - j;
		v = t;
		t = {};
	}
	cout << v.back();
}