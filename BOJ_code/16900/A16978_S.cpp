// BOJ 16978 ¼ö¿­°ú Äõ¸® 22
// offline query

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int mxn = 100001;

struct one {
	int i, v;
};
struct two {
	int l, r, k, idx;
	ll res;
};
struct seg {
	int n, half;
	vector<ll> item;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
	}
	void init() {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	ll sum(int l, int r) {
		ll res = 0;
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
		item[idx] = x;
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

	seg S(n);
	S.init();

	int q; cin >> q;
	vector<one> oq;
	vector<two> tq;
	for (int i = 0; i < q; ++i) {
		int c; cin >> c;
		if (c == 1) {
			int idx, v; cin >> idx >> v;
			oq.push_back({ --idx, v });
		}
		else {
			int l, r, k; cin >> k >> l >> r;
			tq.push_back({ --l, --r, k, i });
		}
	}

	sort(tq.begin(), tq.end(), [&](two a, two b) {
		return a.k < b.k;
		});
	int i = 0;
	for (auto& q : tq) {
		while (i < q.k) {
			S.update(oq[i].i, oq[i].v);
			++i;
		}
		q.res = S.sum(q.l, q.r);
	}

	sort(tq.begin(), tq.end(), [&](two a, two b) {
		return a.idx < b.idx;
		});
	for (auto& q : tq) cout << q.res << '\n';
}

// persistent segment tree
/*
// BOJ 16978 ¼ö¿­°ú Äõ¸® 22
// Persistent segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct pst {
	struct pst_node {
		int l, r;
		ll val;
		pst_node() :pst_node(0, 0, 0) {}
		pst_node(int l_, int r_, ll val_) :l(l_), r(r_), val(val_) {}
	};
	vector<ll> val;
	vector<int> rt;
	vector<pst_node> tree;
	pst(vector<ll>& ori) : tree(vector<pst_node>(2)), rt(vector<int>(1, 1)), val(move(ori)) {}
	void init(int node, int ns, int ne) {
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
	void update_(int node, int ns, int ne, int idx, ll diff) {
		if (ns == ne) return;
		int mid = (ns + ne) / 2;
		if (idx <= mid) {
			int l = tree[node].l;
			tree.push_back(pst_node(tree[l].l, tree[l].r, tree[l].val + diff));
			tree[node].l = tree.size() - 1;
			update_(tree[node].l, ns, mid, idx, diff);
		}
		else {
			int r = tree[node].r;
			tree.push_back(pst_node(tree[r].l, tree[r].r, tree[r].val + diff));
			tree[node].r = tree.size() - 1;
			update_(tree[node].r, mid + 1, ne, idx, diff);
		}
	}
	void update(int idx, ll x, int ns, int ne) {
		ll diff = x - val[idx];
		val[idx] = x;
		int prv = rt.back();
		tree.push_back(pst_node(tree[prv].l, tree[prv].r, tree[prv].val + diff));
		rt.push_back(tree.size() - 1);
		update_(rt.back(), ns, ne, idx, diff);
	}
	ll sum_(int node, int ns, int ne, int l, int r) {
		if (l <= ns && ne <= r) return tree[node].val;
		if (r < ns || ne < l) return 0;
		int mid = (ns + ne) / 2;
		return sum_(tree[node].l, ns, mid, l, r) + sum_(tree[node].r, mid + 1, ne, l, r);
	}
	ll sum(int k, int l, int r, int ns, int ne) {
		return sum_(rt[k], ns, ne, l, r);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<ll> seq(n + 1);
	for (int i = 1; i <= n; ++i) cin >> seq[i];

	pst S(seq);
	S.init(1, 1, n);

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int c; cin >> c;
		if (c == 1) {
			int id; ll x; cin >> id >> x;
			S.update(id, x, 1, n);
		}
		else {
			int k, l, r; cin >> k >> l >> r;
			cout << S.sum(k, l, r, 1, n) << '\n';
		}
	}
}
*/