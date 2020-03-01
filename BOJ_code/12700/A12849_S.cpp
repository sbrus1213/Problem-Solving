// BOJ 12849 본대 산책
// 구현

#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int d;
	ll cnt[8] = { 1 }, tmp[8] = {};
	cin >> d;
	for (int i = 0; i < d; ++i) {
		tmp[0] = cnt[1] + cnt[2];
		tmp[1] = cnt[0] + cnt[2] + cnt[3];
		tmp[2] = cnt[0] + cnt[1] + cnt[3] + cnt[4];
		tmp[3] = cnt[1] + cnt[2] + cnt[4] + cnt[5];
		tmp[4] = cnt[2] + cnt[3] + cnt[5] + cnt[6];
		tmp[5] = cnt[3] + cnt[4] + cnt[7];
		tmp[6] = cnt[4] + cnt[7];
		tmp[7] = cnt[5] + cnt[6];
		for (int j = 0; j < 8; ++j) cnt[j] = tmp[j] % mod;
	}

	cout << cnt[0];
}