// BOJ 13547 ¼ö¿­°ú Äõ¸® 5
// MO's algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct query {
	int s, e, i;
};
int bsz;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> seq(n + 1);
	for (int i = 1; i <= n; ++i) cin >> seq[i];

	int m;
	cin >> m;

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

	vector<int> cnt(1000001), ans(m);
	int tmp = 0, s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; ++i) {
		if (!cnt[seq[i]]) tmp++;
		cnt[seq[i]]++;
	}
	ans[Q[0].i] = tmp;

	for (int i = 1; i < m; ++i) {
		while (s > Q[i].s) {
			if (!cnt[seq[--s]]) tmp++;
			cnt[seq[s]]++;
		}
		while (e < Q[i].e) {
			if (!cnt[seq[++e]]) tmp++;
			cnt[seq[e]]++;
		}
		while (s < Q[i].s) {
			cnt[seq[s]]--;
			if (!cnt[seq[s++]]) tmp--;
		}
		while (e > Q[i].e) {
			cnt[seq[e]]--;
			if (!cnt[seq[e--]]) tmp--;
		}
		ans[Q[i].i] = tmp;
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}