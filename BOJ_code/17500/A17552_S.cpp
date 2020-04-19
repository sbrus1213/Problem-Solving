// BOJ 17552 Knapsack Packing
// D&C

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> ans;

bool dnc(int m, vector<int>& vec) {
	if (vec[0]) return false;

	int mn = vec[1] - vec[0];

	if (m == 2) {
		ans.push_back(mn);
		return true;
	}

	map<int, int> dic;
	for (int i = m - 1; i >= 0; --i) dic[vec[i]] = i;

	vector<int> a, b;
	for (int i = 0; i < m; ++i) {
		int t = vec[i];
		if (t == -1) continue;
		a.push_back(t);
		vec[dic[t]] = -1;
		dic[t]++;
		if (dic[t + mn] <= 0 || dic[t + mn] >= m || vec[dic[t + mn]] != t + mn) return false;
		vec[dic[t + mn]] = -1;
		dic[t + mn]++;
	}

	ans.push_back(mn);
	return dnc(m / 2, a);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int m = pow(2, n);

	vector<int> seq(m);
	for (int i = 0; i < m; ++i) cin >> seq[i];
	sort(seq.begin(), seq.end());

	if (!dnc(m, seq)) cout << "impossible";
	else for (int x : ans) cout << x << '\n';
}