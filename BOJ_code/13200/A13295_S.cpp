// BOJ 13295 Nine Packs
// dynamic programming - knapsack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int h, hsum = 0; cin >> h;
	vector<int> hot(h);
	for (int i = 0; i < h; ++i) {
		cin >> hot[i];
		hsum += hot[i];
	}

	int b, bsum = 0; cin >> b;
	vector<int> burn(b);
	for (int i = 0; i < b; ++i) {
		cin >> burn[i];
		bsum += burn[i];
	}

	vector<int> hdp[2];
	hdp[0] = vector<int>(hsum + 1, hsum + 10);
	hdp[1] = vector<int>(hsum + 1, hsum + 10);
	hdp[1][0] = 0;
	for (int i = 0; i < h; ++i) {
		int cur = i % 2, prv = (i + 1) % 2;
		for (int j = 0; j <= hsum; ++j) {
			hdp[cur][j] = hdp[prv][j];
			if (j >= hot[i]) hdp[cur][j] = min(hdp[cur][j], hdp[prv][j - hot[i]] + 1);
		}
	}


	vector<int> bdp[2];
	bdp[0] = vector<int>(bsum + 1, bsum + 10);
	bdp[1] = vector<int>(bsum + 1, bsum + 10);
	bdp[1][0] = 0;
	for (int i = 0; i < b; ++i) {
		int cur = i % 2, prv = (i + 1) % 2;
		for (int j = 0; j <= bsum; ++j) {
			bdp[cur][j] = bdp[prv][j];
			if (j >= burn[i]) bdp[cur][j] = min(bdp[cur][j], bdp[prv][j - burn[i]] + 1);
		}
	}

	int hi = (h - 1) % 2, bi = (b - 1) % 2, ans = hsum + bsum + 10;
	for (int i = 1; i <= min(hsum, bsum); ++i) {
		if (hdp[hi][i] == hsum + 10) continue;
		if (bdp[bi][i] == bsum + 10) continue;
		ans = min(ans, hdp[hi][i] + bdp[bi][i]);
	}
	if (ans == hsum + bsum + 10) cout << "impossible";
	else cout << ans;
}