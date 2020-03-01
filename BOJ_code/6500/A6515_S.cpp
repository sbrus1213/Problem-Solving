// BOJ 6515 Frequent values
// MO's algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct query {
	int s, e, i;
};
int bsz, tmp;
vector<int> cnt(200001), cnt_cnt(200001);

void add(int x) {
	cnt[x]++;
	if (!cnt_cnt[cnt[x]]) tmp++;
	cnt_cnt[cnt[x]]++;
}
void del(int x) {
	cnt_cnt[cnt[x]]--;
	if (!cnt_cnt[cnt[x]]) tmp--;
	cnt[x]--;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		int n, q;
		cin >> n;
		if (!n) break;
		cin >> q;

		vector<int> seq(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> seq[i];
			seq[i] += 100000;
		}

		vector<query> Q(q);
		for (int i = 0; i < q; ++i) {
			int s, e;
			cin >> s >> e;
			Q[i] = { s, e, i };
		}

		bsz = sqrt(n) + 1;
		sort(Q.begin(), Q.end(), [](query a, query b) {
			return (a.s / bsz == b.s / bsz ? a.e < b.e : a.s / bsz < b.s / bsz);
			});

		fill(cnt.begin(), cnt.end(), 0);
		fill(cnt_cnt.begin(), cnt_cnt.end(), 0);
		tmp = 0;
		vector<int> ans(q);
		int s = Q[0].s, e = Q[0].e;
		for (int i = s; i <= e; ++i) {
			add(seq[i]);
		}
		ans[Q[0].i] = tmp;

		for (int i = 1; i < q; ++i) {
			while (s > Q[i].s) add(seq[--s]);
			while (e < Q[i].e) add(seq[++e]);
			while (s < Q[i].s) del(seq[s++]);
			while (e > Q[i].e) del(seq[e--]);
			ans[Q[i].i] = tmp;
		}

		for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
	}
}