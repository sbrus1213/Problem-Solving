// BOJ 2628 종이자르기
// sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> m >> n;

	int c; cin >> c;
	vector<int> rcut = { 0, n }, ccut = { 0, m };
	while (c--) {
		int x, y; cin >> x >> y;
		if (x) ccut.push_back(y);
		else rcut.push_back(y);
	}
	sort(rcut.begin(), rcut.end());
	sort(ccut.begin(), ccut.end());

	int rmx = 0, cmx = 0;
	if (rcut.size() == 2) rmx = n;
	else
		for (int i = 1; i < rcut.size(); ++i)
			rmx = max(rmx, rcut[i] - rcut[i - 1]);
	if (ccut.size() == 2) cmx = m;
	else
		for (int i = 1; i < ccut.size(); ++i)
			cmx = max(cmx, ccut[i] - ccut[i - 1]);
	cout << rmx * cmx;
}