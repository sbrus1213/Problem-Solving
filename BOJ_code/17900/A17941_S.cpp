// BOJ 17941 목장 CCTV
// Sparse Array & deque dynamic programming

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int mxsheep[500][500][2][10];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> mxsheep[i][j][0][0];
			mxsheep[i][j][1][0] = mxsheep[i][j][0][0];
		}

	for (int i = 0; i < n; ++i) {
		int pl = 1;
		for (int k = 1; k < 10; ++k) {
			for (int j = m - 1; j >= 0; --j) {
				if (j + pl >= m) mxsheep[i][j][0][k] = mxsheep[i][j][0][k - 1];
				else mxsheep[i][j][0][k] = max(mxsheep[i][j][0][k - 1], mxsheep[i][j + pl][0][k - 1]);
			}
			pl <<= 1;
		}
	}

	for (int j = 0; j < m; ++j) {
		int pl = 1;
		for (int k = 1; k < 10; ++k) {
			for (int i = n - 1; i >= 0; --i) {
				if (i + pl >= n) mxsheep[i][j][1][k] = mxsheep[i][j][1][k - 1];
				else mxsheep[i][j][1][k] = max(mxsheep[i][j][1][k - 1], mxsheep[i + pl][j][1][k - 1]);
			}
			pl <<= 1;
		}
	}

	int q; cin >> q;
	while (q--) {
		int lur, luc, rdr, rdc, r, c, k, d;
		cin >> lur >> luc >> r >> c >> k >> d;
		lur--; luc--;
		rdr = lur + r - 1, rdc = luc + c - 1;
		if (d == 1) rdr += k - 1;
		else if (d == 2) lur -= k - 1;
		else if (d == 3) rdc += k - 1;
		else if (d == 4) luc -= k - 1;

		int ans = 0, sz = 0;
		vector<int> tmp;

		if (d < 3) {
			sz = r;
			for (int i = lur; i <= rdr; ++i) {
				int len = rdc - luc + 1, seg = 512, res = 0, st = luc;
				for (int k = 9; k >= 0; --k) {
					if (len < seg);
					else {
						res = max(res, mxsheep[i][st][0][k]);
						st += seg;
						len -= seg;
					}
					seg >>= 1;
				}
				tmp.push_back(res);
			}
		}
		else {
			sz = c;
			for (int j = luc; j <= rdc; ++j) {
				int len = rdr - lur + 1, seg = 512, res = 0, st = lur;
				for (int k = 9; k >= 0; --k) {
					if (len < seg);
					else {
						res = max(res, mxsheep[st][j][1][k]);
						st += seg;
						len -= seg;
					}
					seg >>= 1;
				}
				tmp.push_back(res);
			}
		}

		deque<int> mx;
		for (int i = 0; i < tmp.size(); ++i) {
			if (mx.size() && mx.front() <= i - sz)
				mx.pop_front();
			while (mx.size() && tmp[mx.back()] <= tmp[i])
				mx.pop_back();
			mx.push_back(i);
			if(i >= sz-1) 
				ans ^= tmp[mx.front()];
		}

		cout << ans << '\n';
	}
}