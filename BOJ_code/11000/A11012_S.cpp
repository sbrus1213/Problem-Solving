// BOJ 11012 Egg
// Persistent segment tree

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int lower = 0;
const int upper = 1e5;

struct pst {
	struct pst_node {
		int l, r, val;
		pst_node() :pst_node(0, 0, 0) {}
		pst_node(int l_, int r_, int val_) :l(l_), r(r_), val(val_) {}
	};
	vector<int> val, rt;
	vector<pst_node> tree;
	pst(vector<int>& ori) : tree(vector<pst_node>(2)), rt(vector<int>(1, 1)), val(move(ori)) {}
	void init(int node = 1, int ns = lower, int ne = upper) {
		if (ns == ne) {
			tree[node].val = val[ns];
			return;
		}
		int mid = (ns + ne) / 2;
		tree.push_back(pst_node()); tree[node].l = tree.size() - 1;
		init(tree[node].l, ns, mid);
		tree.push_back(pst_node()); tree[node].r = tree.size() - 1;
		init(tree[node].r, mid + 1, ne);
		tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
	}
	void new_version(int sz) {
		int prv = rt.back();
		tree.push_back(pst_node(tree[prv].l, tree[prv].r, tree[prv].val + sz));
		rt.push_back(tree.size() - 1);
	}
	void update(int idx, int diff, int node, int ns = lower, int ne = upper) {
		if (ns == ne) return;
		int mid = (ns + ne) / 2;
		if (idx <= mid) {
			int l = tree[node].l;
			tree.push_back(pst_node(tree[l].l, tree[l].r, tree[l].val + diff));
			tree[node].l = tree.size() - 1;
			update(idx, diff, tree[node].l, ns, mid);
		}
		else {
			int r = tree[node].r;
			tree.push_back(pst_node(tree[r].l, tree[r].r, tree[r].val + diff));
			tree[node].r = tree.size() - 1;
			update(idx, diff, tree[node].r, mid + 1, ne);
		}
	}
	int sum(int l, int r, int node, int ns = lower, int ne = upper) {
		if (l <= ns && ne <= r) return tree[node].val;
		if (r < ns || ne < l) return 0;
		int mid = (ns + ne) / 2;
		return sum(l, r, tree[node].l, ns, mid) + sum(l, r, tree[node].r, mid + 1, ne);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n, q; cin >> n >> q;

		vector<pii> tmp(n);
		vector<int> X(n);
		for (int i = 0; i < n; ++i) {
			cin >> tmp[i].first >> tmp[i].second;
			X[i] = tmp[i].first;
		}
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());

		map<int, vector<int>> P;
		for (auto& p : tmp)
			P[p.first].push_back(p.second);

		vector<int> first(upper + 1);
		for (int y : P[X[0]]) first[y]++;

		pst S(first);
		S.init();
		for (int i = 1; i < X.size(); ++i) {
			S.new_version(P[X[i]].size());
			for (int y : P[X[i]])
				S.update(y, 1, S.rt.back());
		}

		X.push_back(upper + 1);
		long long ans = 0;
		for (int i = 0; i < q; ++i) {
			int x1, y1, x2, y2; cin >> x1 >> x2 >> y1 >> y2;
			int l = lower_bound(X.begin(), X.end(), x1) - X.begin();
			int r = upper_bound(X.begin(), X.end(), x2) - X.begin();

			if (r) ans += S.sum(y1, y2, S.rt[r - 1]);
			if (l) ans -= S.sum(y1, y2, S.rt[l - 1]);
		}
		cout << ans << '\n';
	}
}