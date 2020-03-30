// BOJ 2799 블라인드
// 구현

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	int ans[5] = {};
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		string bl[4];
		for (int j = 0; j < 4; ++j) cin >> bl[j];

		for (int k = 1, l = 0, j; l < m; ++l, k += 5) {
			j = 0;
			for (; j < 4; ++j) {
				if (bl[j][k] == '.') break;
			}
			ans[j]++;
		}
	}
	for (int i = 0; i < 5; ++i) cout << ans[i] << ' ';
}