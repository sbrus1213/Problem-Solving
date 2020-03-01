// BOJ 13546 ¼ö¿­°ú Äõ¸® 4
// MO's algorithm

#include <iostream>
#include <vector>
#include <list>
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

	int n, k;
	cin >> n >> k;

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

	vector<list<int> > idx(k + 1);
	vector<int> cnt(n + 1), ans(m);
	cnt[0] = 1;
	int tmp = 0;
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; ++i) {
		if (idx[seq[i]].empty()) idx[seq[i]].push_back(i);
		else {
			tmp = max(tmp, i - idx[seq[i]].front());
			cnt[i - idx[seq[i]].front()]++;
			if (idx[seq[i]].size() > 1) cnt[idx[seq[i]].back() - idx[seq[i]].front()]--;
			idx[seq[i]].push_back(i);
		}
	}
	ans[Q[0].i] = tmp;

	for (int i = 1; i < m; ++i) {
		while (s > Q[i].s) {
			--s;
			if (idx[seq[s]].empty()) idx[seq[s]].push_front(s);
			else {
				tmp = max(tmp, idx[seq[s]].back() - s);
				cnt[idx[seq[s]].back() - s]++;
				if (idx[seq[s]].size() > 1)cnt[idx[seq[s]].back() - idx[seq[s]].front()]--;
				idx[seq[s]].push_front(s);
			}
		}
		while (e < Q[i].e) {
			++e;
			if (idx[seq[e]].empty()) idx[seq[e]].push_back(e);
			else {
				tmp = max(tmp, e - idx[seq[e]].front());
				cnt[e - idx[seq[e]].front()]++;
				if (idx[seq[e]].size() > 1)cnt[idx[seq[e]].back() - idx[seq[e]].front()]--;
				idx[seq[e]].push_back(e);
			}
		}
		while (s < Q[i].s) {
			if (idx[seq[s]].size() == 1) {
				idx[seq[s]].pop_front();
			}
			else {
				cnt[idx[seq[s]].back() - idx[seq[s]].front()]--;
				idx[seq[s]].pop_front();
				if (idx[seq[s]].size() > 1) cnt[idx[seq[s]].back() - idx[seq[s]].front()]++;
				while (!cnt[tmp]) {
					tmp--;
				}
			}
			s++;
		}
		while (e > Q[i].e) {
			if (idx[seq[e]].size() == 1) {
				idx[seq[e]].pop_back();
			}
			else {
				cnt[idx[seq[e]].back() - idx[seq[e]].front()]--;
				idx[seq[e]].pop_back();
				if (idx[seq[e]].size() > 1) cnt[idx[seq[e]].back() - idx[seq[e]].front()]++;
				while (!cnt[tmp]) {
					tmp--;
				}
			}
			e--;
		}
		ans[Q[i].i] = tmp;
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}