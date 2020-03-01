// BOJ 17415 Huge Integer!
// 비둘기 집 & prefix sum

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;

	ll ts, tsz;
	vector<ll> tens_idx(k, -1), tens = { 1 };
	tens_idx[1] = 0;
	while (1) {
		ll next = (tens.back() * 10) % k;
		if (tens_idx[next] != -1) {
			ts = tens_idx[next];
			tsz = tens.size() - tens_idx[next];
			break;
		}
		else {
			tens_idx[next] = tens.size();
			tens.push_back(next);
		}
	}

	vector<ll> ones(tens.size());
	ones[0] = 1;
	for (int i = 1; i < ones.size(); ++i)
		ones[i] = (ones[i - 1] + tens[i]) % k;

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll a, b, tmp;
		cin >> a >> b;

		if (b < ts + tsz) res = (res * tens[b]) % k;
		else res = (res * tens[ts + (b - ts) % tsz]) % k;

		if (b <= ts) tmp = ones[b - 1];
		else if (!ts) tmp = ((b / tsz) * ones[tsz - 1] + (b % tsz ? ones[b % tsz - 1] : 0)) % k;
		else tmp = ones[ts - 1] + (((b - ts) / tsz) % k * (ones[ts + tsz - 1] - ones[ts - 1]) % k + (ones[ts + (b - ts) % tsz - 1] - ones[ts - 1])) % k + k;

		tmp = (tmp * a) % k;
		res = (res + tmp) % k;
	}
	cout << res;
}