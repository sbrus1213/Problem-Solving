// BOJ 5568 카드놓기
// Combinatorics

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()

int n, m, card[10];
bool use[10];
vector<int> maked;

void make(int cnt, int num) {
	if (cnt == m) {
		maked.push_back(num);
	}

	for (int i = 0; i < n; ++i) {
		if (!use[i]) {
			use[i] = true;
			int param = num * 10;
			if (card[i] > 9) param *= 10;

			make(cnt + 1, param + card[i]);

			use[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> card[i];

	make(0, 0);

	sort(BtoE(maked));

	int l = maked.size(), tmp = -1, res = 0;
	for (int i = 0; i < l; ++i) {
		if (maked[i] != tmp) {
			++res;
			tmp = maked[i];
		}
	}

	cout << res;
}