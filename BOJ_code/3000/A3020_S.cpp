// BOJ 3020 °³¶Ë¹ú·¹
// prefix sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, h; cin >> n >> h;

	vector<int> up(h + 1), down(h + 1);
	for (int i = 0; i < n; ++i) {
		int hh; cin >> hh;
		if (i % 2) up[h + 1 - hh]++;
		else down[hh]++;
	}

	for (int i = 1; i < h; ++i) up[i + 1] += up[i];
	for (int i = h; i > 1; --i) down[i - 1] += down[i];

	int mn = n * 5;
	for (int i = 1; i <= h; ++i) mn = min(mn, up[i] + down[i]);

	int cnt = 0;
	for (int i = 1; i <= h; ++i) if (mn == up[i] + down[i]) cnt++;

	cout << mn << ' ' << cnt;
}