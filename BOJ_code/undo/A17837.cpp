// BOJ 17837 새로운 게임 2
// 구현

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct point{
	int r, c, d;
};
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	
	int col[13][13];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> col[i][j];
	vector<point> p(k);
	for (int i = 0; i < k; ++i) cin >> p[i].r >> p[i].c >> p[i].d;

	for (int tc = 1; tc <= 1000; ++tc) {
		for (int l = 0; l < k; ++l) {

		}
	}


}
