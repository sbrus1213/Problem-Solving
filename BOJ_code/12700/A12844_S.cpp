// BOJ 12844 XOR
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg {
	int n, half;
	vector<int> item, lazy;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		lazy.resize(half * 2);
	}
	int init(int node, int ns, int ne, vector<int>& arr) {
		if (ns == ne) return item[node] = arr[ns];
		int mid = (ns + ne) / 2;
		return item[node] = init(node * 2, ns, mid, arr) ^ init(node * 2 + 1, mid + 1, ne, arr);
	}
	void propagate(int node, int ns, int ne) {
		if (!lazy[node]) return;
		if (ns == ne || (ne - ns + 1) % 2) item[node] ^= lazy[node];
		if (ns != ne) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
	int xor__(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return item[node];
		if (ne < l || r < ns) return 0;
		int mid = (ns + ne) / 2;
		return xor__(node * 2, ns, mid, l, r) ^ xor__(node * 2 + 1, mid + 1, ne, l, r);
	}
	void update(int node, int ns, int ne, int l, int r, int c) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			if (ns == ne || (ne - ns + 1) % 2) item[node] ^= c;
			if (ns != ne) {
				lazy[node * 2] ^= c;
				lazy[node * 2 + 1] ^= c;
			}
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2, ns, mid, l, r, c);
		update(node * 2 + 1, mid + 1, ne, l, r, c);
		item[node] = item[node * 2] ^ item[node * 2 + 1];
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n;

	seg S(n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	S.init(1, 0, n - 1, arr);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t, a, b, c;
		cin >> t >> a >> b;
		if (a > b) swap(a, b);
		if (t == 1) {
			cin >> c;
			S.update(1, 0, n - 1, a, b, c);
		}
		else
			cout << S.xor__(1, 0, n - 1, a, b) << '\n';
	}
}