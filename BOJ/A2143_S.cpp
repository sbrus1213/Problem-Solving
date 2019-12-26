// BOJ 2143 두 배열의 합
// prefix sum & two pointer

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	ll a[1001], b[1001], pa[1001] = { 0 }, pb[1001] = { 0 }, res = 0, t;
	vector<ll> as, bs;

	cin >> t;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) pa[i] = pa[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			as.push_back(pa[j] - pa[i - 1]);
	sort(as.begin(), as.end());

	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= m; i++) pb[i] = pb[i - 1] + b[i];
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
			bs.push_back(pb[j] - pb[i - 1]);
	sort(bs.begin(), bs.end(), greater<ll>());

	ll af, ae, bf, be;
	af = ae = bf = be = 0;

	while (af < as.size() && bf < bs.size()) {
		if (as[af] + bs[bf] == t) {
			ae = af;
			while (as[af] == as[ae])
				if (++ae == as.size()) break;
			be = bf;
			while (bs[bf] == bs[be])
				if (++be == bs.size()) break;
			res += (ae - af) * (be - bf);
			af = ae; bf = be;
		}
		else if (as[af] + bs[bf] > t) bf++;
		else af++;
	}

	cout << res;
}