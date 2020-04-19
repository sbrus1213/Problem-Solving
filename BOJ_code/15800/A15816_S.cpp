// BOJ 15816 퀘스트 중인 모험가
// dynamic segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct qry {
	int c, l, r;
};
struct seg {
	int n, half;
	vector<int> item;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
	}
	void init() {
		for (int i = half - 1; i; --i)
			item[i] = item[i * 2] + item[i * 2 + 1];
	}
	int sum(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1; r >>= 1;
		}
		return res;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] += x;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] + item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> pos, pre;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		pos.push_back(x);
		pre.push_back(x);
	}

	int m; cin >> m;
	vector<qry> Q(m);
	for (int i = 0; i < m; ++i) {
		cin >> Q[i].c;
		if (Q[i].c == 1) {
			cin >> Q[i].l;
			pos.push_back(Q[i].l);
		}
		else {
			cin >> Q[i].l >> Q[i].r;
			pos.push_back(Q[i].l);
			pos.push_back(Q[i].r);
		}
	}

	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());

	seg S(pos.size());
	for (int i = 0, j = 0; i < pos.size(); ++i) {
		if (pos[i] == pre[j]) {
			S.item[S.half + i] = 1;
			j++;
		}
		if (j == n) break;
	}
	S.init();

	for (auto q : Q) {
		if (q.c == 1) {
			int x = lower_bound(pos.begin(), pos.end(), q.l) - pos.begin();
			S.update(x, 1);
		}
		else {
			int l = lower_bound(pos.begin(), pos.end(), q.l) - pos.begin();
			int r = lower_bound(pos.begin(), pos.end(), q.r) - pos.begin();
			cout << (q.r - q.l + 1) - S.sum(l, r) << '\n';
		}
	}
}