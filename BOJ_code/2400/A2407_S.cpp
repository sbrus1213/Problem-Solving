// BOJ 2407 а╤гу
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define INF (ll)(1e17)

void vec_plus(vector<ll>& s1, vector<ll>& s2, vector<ll>& dest) {
	int siz1 = s1.size(), siz2 = s2.size();
	dest.resize(max(siz1, siz2));
	for (int i = 0; i < min(siz1, siz2); ++i)
		dest[i] = s1[i] + s2[i];
	if (siz1 > siz2) for (int i = siz2; i < siz1; ++i) dest[i] = s1[i];
	if (siz2 > siz1) for (int i = siz1; i < siz2; ++i) dest[i] = s2[i];
	for (int i = 0; i < max(siz1, siz2); ++i) {
		if (dest[i] >= INF) {
			if (i != max(siz1, siz2) - 1) dest[i + 1] += dest[i] / INF;
			else dest.push_back(dest[i] / INF);
			dest[i] %= INF;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	vector<ll> ncm[101][101];

	cin >> n >> m;

	ncm[1][0].push_back(1);
	ncm[1][1].push_back(1);
	for (int i = 2; i <= n; ++i) {
		ncm[i][0].push_back(1);
		ncm[i][i].push_back(1);
		for (int j = 1; j < i; ++j)
			vec_plus(ncm[i - 1][j - 1], ncm[i - 1][j], ncm[i][j]);
	}

	cout << ncm[n][m][ncm[n][m].size() - 1];
	for (int i = ncm[n][m].size() - 2; i >= 0; --i) {
		int zero = INF / (ncm[n][m][i] * 10);
		while (zero) cout << 0, zero /= 10;
		cout << ncm[n][m][i];
	}
}