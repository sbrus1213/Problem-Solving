// BOJ 11672 Guessing Camels
// Algorithm

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>
#define half 262144
#define mxn 524288

int seg1[mxn], seg2[mxn], seg3[mxn];

int sum(int* seg, int l, int r) {
	int res = 0;

	l += half; r += half;

	while (l <= r) {
		if (l % 2) {
			res += seg[l];
			l++;
		}
		if (!(r % 2)) {
			res += seg[r];
			r--;
		}
		l >>= 1; r >>= 1;
	}

	return res;
}

void update(int* seg, int idx) {
	idx += half;
	seg[idx] = 1;
	idx >>= 1;

	while (idx) {
		seg[idx] = seg[idx * 2] + seg[(idx * 2) + 1];
		idx >>= 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	vector<Pii> bet1(n), bet2(n), bet3(n);

	for (int i = 0; i < n; ++i) cin >> bet1[i].first;
	for (int i = 0; i < n; ++i) cin >> bet2[i].first;
	for (int i = 0; i < n; ++i) cin >> bet3[i].first;
	for (int i = 0; i < n; ++i) bet1[i].second = bet2[i].second = bet3[i].second = i;

	sort(BtoE(bet1));
	sort(BtoE(bet2));
	sort(BtoE(bet3));

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int lcnt = n + 1, rcnt = n + 1;
		lcnt = sum(seg1, 0, bet1[i].second);
		rcnt = sum(seg1, bet1[i].second, n - 1);

		lcnt = min(lcnt, sum(seg2, 0, bet2[i].second));
		rcnt = min(rcnt, sum(seg2, bet2[i].second, n - 1));

		lcnt = min(lcnt, sum(seg3, 0, bet3[i].second));
		rcnt = min(rcnt, sum(seg3, bet3[i].second, n - 1));

		res = res + (ll)lcnt + (ll)rcnt;

		update(seg1, bet1[i].second);
		update(seg2, bet2[i].second);
		update(seg3, bet3[i].second);
	}

	cout << res;
}