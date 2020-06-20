// BOJ 5559 JOI 깃발
// dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mod = 100000;

char flag[21][21];
ll n, m, dp[21][21][3];

int ci(char c) {
	if (c == 'J') return 0;
	if (c == 'O') return 1;
	if (c == 'I') return 2;
}

ll go(int i, int j, int f) {
	if (i == n - 1 || j == m - 1) return dp[i][j][f] = 0;

	ll& ret = dp[i][j][f];
	if (ret) return ret;

	if (flag[i + 1][j] != '?' && flag[i][j + 1] != '?') {
		ret = (go(i + 1, j, ci(flag[i + 1][j])) * go(i, j + 1, ci(flag[i][j + 1]))) % mod;
	}
	else if (flag[i + 1][j] != '?') {
		if (flag[i + 1][j] != 'I' || f!= 0) {
			for (int k = 0; k < 3; ++k) 
				ret = (ret + go(i + 1, j, ci(flag[i + 1][j])) * go(i, j + 1, k)) % mod;
		}
		else {
			ret 
		}
	}
	else if (flag[i][j + 1] != '?') {

	}
	else {

	}

	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> flag[i][j];
			if (flag[i][j] == '?') cnt++;
		}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (flag[i][j] != 'J') continue;
			if (flag[i][j + 1] != 'O') continue;
			if (flag[i + 1][j] != 'I') continue;
			int x = 1;
			for (int k = 0; k < cnt; ++k)
				x = (x * 3) % mod;
			cout << x;
			return 0;
		}
	}

	

}