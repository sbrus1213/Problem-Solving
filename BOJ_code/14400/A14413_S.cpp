// BOJ 14413 Poklon
// MO's algorithm

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct query {
	int s, e, i;
};
int bsz, tmp;
map<int, int> dic;
vector<int> cnt;

void add(int x) {
	if (cnt[x] == 2) tmp--;
	cnt[x]++;
	if (cnt[x] == 2) tmp++;
}
void del(int x) {
	if (cnt[x] == 2) tmp--;
	cnt[x]--;
	if (cnt[x] == 2) tmp++;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, id = 1;
	cin >> n >> m;

	vector<int> seq(n + 1), idx(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
		if (!dic[seq[i]]) idx[i] = dic[seq[i]] = id++;
		else idx[i] = dic[seq[i]];
	}

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

	cnt.resize(n + 1);
	vector<int> ans(m);
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; ++i) add(idx[i]);
	ans[Q[0].i] = tmp;

	for (int i = 1; i < m; ++i) {
		while (s > Q[i].s) add(idx[--s]);
		while (e < Q[i].e) add(idx[++e]);
		while (s < Q[i].s) del(idx[s++]);
		while (e > Q[i].e) del(idx[e--]);
		ans[Q[i].i] = tmp;
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}