// BOJ 4920 테트리스
// simulation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int tc = 1;; ++tc) {
		int n; cin >> n;
		if (!n) break;

		vector<vector<int> > B(n, vector<int>(n));

		vector<vector<pii > > block[5];
		block[0].push_back({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
		block[0].push_back({ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } });
		block[1].push_back({ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } });
		block[1].push_back({ { 0, 0 }, { 1, 0 }, { 1, -1 }, { 2, -1 } });
		block[2].push_back({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } });
		block[2].push_back({ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, -1 } });
		block[2].push_back({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } });
		block[2].push_back({ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } });
		block[3].push_back({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } });
		block[3].push_back({ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, -1 } });
		block[3].push_back({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { -1, 1 } });
		block[3].push_back({ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, 1 } });
		block[4].push_back({ { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } });

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> B[i][j];

		int ans = -5000000;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				pii cur = pii(i, j);
				for (int k = 0; k < 5; ++k) {
					for (auto& bl : block[k]) {
						int l, sum = 0;
						for (l = 0; l < 4; ++l) {
							int xx = cur.x + bl[l].x, yy = cur.y + bl[l].y;
							if (xx < 0 || xx >= n) break;
							if (yy < 0 || yy >= n) break;
							sum += B[xx][yy];
						}
						if (l == 4) ans = max(ans, sum);
					}
				}
			}
		}
		cout << tc << ". " << ans << '\n';
	}
}