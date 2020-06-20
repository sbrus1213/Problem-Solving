// BOJ 2854 문제 출제
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

// dp1 : 난이도 i짜리 쓸 때
// dp2 : 난이도 i-1~i 짜리 쓸 때
// dp3 : 난이도 i~i+1 짜리 쓸 때
vector<ll> cnt, bcnt, dp1, dp2, dp3;
void go(int i) {
	if (dp1[i] != -1) return;

	go(i - 1);

	dp1[i] = (cnt[i] * (dp1[i - 1] + dp2[i - 1] + dp3[i - 1])) % mod;

	if (bcnt[i - 1] == 0) dp2[i] = 0;
	else if (bcnt[i - 1] == 1) dp2[i] = (bcnt[i - 1] * (dp1[i - 1] + dp2[i - 1])) % mod;
	else dp2[i] = ((bcnt[i - 1] * (dp1[i - 1] + dp2[i - 1])) % mod + ((bcnt[i - 1] - 1) * dp3[i - 1]) % mod) % mod;

	dp3[i] = (bcnt[i] * (dp1[i - 1] + dp2[i - 1] + dp3[i - 1])) % mod;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	cnt = bcnt = vector<ll>(n);
	for (int i = 0; i < n; ++i)
		cin >> cnt[i];
	for (int i = 0; i < n - 1; ++i)
		cin >> bcnt[i];

	dp1 = dp2 = dp3 = vector<ll>(n, -1);
	dp1[0] = cnt[0];
	dp2[0] = 0;
	dp3[0] = bcnt[0];
	go(n - 1);

	cout << (dp1[n - 1] + dp2[n - 1] + dp3[n - 1]) % mod;
}