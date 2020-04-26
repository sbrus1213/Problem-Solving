// BOJ 11277 2-SAT - 1
// Backtracking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int n, m;
bool tf[21], res;
vector<pii> cla;

void sat(int i) {
	if (res) return;

	if (i == n + 1) {
		for (auto c : cla) {
			bool t = 0;
			if (c.first > 0) t |= tf[c.first];
			else t |= !tf[-c.first];
			if (c.second > 0) t |= tf[c.second];
			else t |= !tf[-c.second];
			if (!t) return;
		}
		res = 1;
		return;
	}

	tf[i] = 0;
	sat(i + 1);
	tf[i] = 1;
	sat(i + 1);
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		cla.push_back({ a, b });
	}

	sat(1);
	cout << res;
}