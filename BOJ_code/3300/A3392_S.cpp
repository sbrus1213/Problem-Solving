// BOJ 3392 화성지도
// sweeping algorithm & segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct seg {
	int n, half;
	vector<int> item, cnt;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		cnt.resize(half * 2);
	}
	void update(int node, int ns, int ne, int l, int r, int x) {
		if (r < ns || l > ne) return;
		else if (l <= ns && ne <= r)
			cnt[node] += x;
		else {
			int mid = (ns + ne) / 2;
			update(node * 2, ns, mid, l, r, x);
			update(node * 2 + 1, mid + 1, ne, l, r, x);
		}
		if (cnt[node]) item[node] = ne - ns + 1;
		else if (ns == ne) item[node] = 0;
		else item[node] = item[node * 2] + item[node * 2 + 1];
	}
};
struct line {
	int x, yl, yh, lr;
};


int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<line> L;
	for (int i = 0; i < n; ++i) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		L.push_back({ x1, y1, y2, 1 });
		L.push_back({ x2, y1, y2, -1 });
	}
	sort(L.begin(), L.end(), [&](line a, line b) {return a.x < b.x; });

	int ans = 0;
	seg S(30001);
	for (int i = 0, prev = 0; i < 2 * n; ++i) {
		if (i) ans += (L[i].x - prev) * S.item[1];
		S.update(1, 0, 30000, L[i].yl, L[i].yh - 1, L[i].lr);
		prev = L[i].x;
	}

	cout << ans;
}