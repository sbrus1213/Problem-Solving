// BOJ 15431 Space Probe
// line sweeping 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; ll t1, t2; cin >> n >> k >> t1 >> t2;
	double t = t2 - t1;

	vector<ll> m(n);
	for (int i = 0; i < n; ++i) cin >> m[i];

	vector<pii> be(k);
	for (int i = 0; i < k; ++i) cin >> be[i].first >> be[i].second;

	vector<pii> no;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			pii elem = pii(be[i].first - m[j], be[i].second - m[j]);
			if (elem.second <= t1) continue;
			if (elem.first >= t2) continue;
			elem.first = max(elem.first, t1);
			elem.second = min(elem.second, t2);
			no.push_back(elem);
		}
	}
	sort(no.begin(), no.end());
	no.erase(unique(no.begin(), no.end()), no.end());

	int l = no.size();
	ll s = t1, e = t1;
	double res = 0;
	for (int i = 0; i < l; ) {
		s = no[i].first;
		e = no[i].second;
		while (i < l && e >= no[i].first) {
			e = max(e, no[i].second);
			i++;
		}
		res += e - s;
	}
	cout << fixed;
	cout.precision(10);
	cout << (t - res) / t;
}