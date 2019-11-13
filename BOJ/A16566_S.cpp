// BOJ 16566 카드 게임
// Binary search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define BtoE(vec) vec.begin(), vec.end()

int n, m, k, chulsu[10000];
vector<int> minsu;
vector<bool> checked;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;

	minsu.resize(m);
	checked.resize(m, false);
	for (int i = 0; i < m; ++i) cin >> minsu[i];
	sort(BtoE(minsu));
	for (int i = 0; i < k; ++i) cin >> chulsu[i];

	for (int i = 0; i < k; ++i) {
		int mins = upper_bound(BtoE(minsu), chulsu[i]) - minsu.begin();
		while (checked[mins]) mins++;
		cout << minsu[mins] << '\n';
		checked[mins] = true;
	}
}