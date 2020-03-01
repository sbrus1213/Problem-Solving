// BOJ 8462 ¹è¿­ÀÇ Èû
// MO's algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

struct query {
	int s, e, i;
};
int bsz;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> seq(n + 1);
	for (int i = 1; i <= n; ++i) cin >> seq[i];

	vector<query> Q(m);
	for (int i = 0; i < m; ++i) {
		int s, e;
		cin >> s >> e;
		Q[i] = { s, e, i };
	}

	bsz = sqrt(n) + 1;
	sort(Q.begin(), Q.end(), [](query a, query b) {
		return (a.s / bsz == b.s / bsz ? a.e < b.e : a.s / bsz < b.s / bsz);
		});

	vector<ll> cnt(1000001), ans(m);
	ll tmp = 0, t;
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; ++i) {
		tmp += ((cnt[seq[i]] + 1) * (cnt[seq[i]] + 1) - cnt[seq[i]] * cnt[seq[i]]) * seq[i];
		cnt[seq[i]]++;
	}
	ans[Q[0].i] = tmp;

	for (int i = 1; i < m; ++i) {
		while (s > Q[i].s) {
			t = cnt[seq[--s]]++;
			tmp += (2 * t + 1) * seq[s];
		}
		while (e < Q[i].e) {
			t = cnt[seq[++e]]++;
			tmp += (2 * t + 1) * seq[e];
		}
		while (s < Q[i].s) {
			t = --cnt[seq[s]];
			tmp -= (2 * t + 1) * seq[s++];
		}
		while (e > Q[i].e) {
			t = --cnt[seq[e]];
			tmp -= (2 * t + 1) * seq[e--];
		}
		ans[Q[i].i] = tmp;
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}