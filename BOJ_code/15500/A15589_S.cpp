// BOJ 15589 Lifeguards (silver)
// line sweeping

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct node {
	int t, lr, id;
};
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii > p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end());

	int l = p[0].first, r = p[0].second, tot = 0;
	for (int i = 1; i < n; ++i) {
		if (r < p[i].first) {
			tot += r - l;
			l = p[i].first, r = p[i].second;
		}
		else r = max(r, p[i].second);
	}
	tot += r - l;

	vector<node> v;
	for (int i = 0; i < n; ++i) {
		v.push_back({ p[i].first, 1, i });
		v.push_back({ p[i].second, -1, i });
	}

	sort(v.begin(), v.end(), [&](node a, node b) {
		return a.t < b.t;
		});

	int cnt = 0, id = 0;
	vector<int> minus(n);
	for (int i = 0; i < 2 * n;) {
		int t = v[i].t;
		do {
			cnt += v[i].lr;
			id += v[i].lr * v[i].id;
			i++;
		} while (i < 2 * n && v[i].t == t);
		if (cnt == 1)
			minus[id] += v[i].t - v[i - 1].t;
	}

	int mn = tot + 3;
	for (int i = 0; i < n; ++i) mn = min(mn, minus[i]);

	cout << tot - mn;
}