// BOJ 2214 성냥깨비와 정사각형
// 구현

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m) {
		if (!n) break;

		vector<string> row(n + 1), col(n);
		for (int i = 0; i <= 2 * n; ++i)
			if (i % 2) cin >> col[i / 2];
			else cin >> row[i / 2];

		int cnt = 0;
		for (int d = 1; d <= min(n, m); ++d)
			for (int i = 0; i <= n - d; ++i)
				for (int j = 0; j <= m - d; ++j) {
					bool flag = true;
					for (int k = 0; k < d; ++k) {
						if (row[i][j + k] != '-') flag = false;
						if (row[i + d][j + k] != '-') flag = false;
						if (col[i + k][j] != '|') flag = false;
						if (col[i + k][j + d] != '|') flag = false;
					}
					if (flag) ++cnt;
				}
		cout << cnt << " squares\n";
	}
}