// BOJ 2672 여러 직사각형의 전체 면적 구하기
// sweeping algorithm & segment tree

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<double> yidx;

struct seg {
	int n, half;
	vector<double> item;
	vector<int> cnt;
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
		if (cnt[node]) item[node] = yidx[ne] - yidx[ns - 1];
		else if (ns == ne) item[node] = 0;
		else item[node] = item[node * 2] + item[node * 2 + 1];
	}
};
struct square {
	double x, y, w, h;
};
struct line {
	double x;
	int yl, yh, lr;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<square> SQ(n);
	vector<double> Y;
	for (int i = 0; i < n; ++i) {
		cin >> SQ[i].x >> SQ[i].y >> SQ[i].w >> SQ[i].h;
		Y.push_back(SQ[i].y);
		Y.push_back(SQ[i].y + SQ[i].h);
	}

	int yc = 0; map<double, int> yd;
	yidx.resize(2 * n + 1);
	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (double yy : Y) yd[yy] = ++yc, yidx[yc] = yy;
	for (int i = 1; i < 2 * n; ++i) yidx[i] = yidx[i + 1] - yidx[i];
	for (int i = 1; i <= 2 * n; ++i) yidx[i] += yidx[i - 1];

	vector<line> L;
	for (int i = 0; i < n; ++i) {
		L.push_back({ SQ[i].x, yd[SQ[i].y], yd[SQ[i].y + SQ[i].h],1 });
		L.push_back({ SQ[i].x + SQ[i].w, yd[SQ[i].y], yd[SQ[i].y + SQ[i].h],-1 });
	}
	sort(L.begin(), L.end(), [&](line a, line b) {return a.x < b.x; });

	double ans = 0, prev;
	seg S(2 * n + 2);
	for (int i = 0; i < 2 * n; ++i) {
		if (i) ans += (L[i].x - prev) * S.item[1];
		S.update(1, 0, 2 * n + 1, L[i].yl, L[i].yh - 1, L[i].lr);
		prev = L[i].x;
	}

	if ((long long)ans * 100 == ans * 100) cout << (long long)ans;
	else {
		cout << fixed; cout.precision(2);
		cout << ans;
	}
}