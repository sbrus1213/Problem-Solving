// BOJ 1236 성 지키기
// 구현

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	char castle[50][50];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> castle[i][j];

	int row = 0, col = 0;
	for (int i = 0; i < n; ++i) {
		bool found = 1;
		for (int j = 0; j < m; ++j)
			if (castle[i][j] == 'X')
				found = 0;
		if (found) row++;
	}
	for (int j = 0; j < m; ++j) {
		bool found = 1;
		for (int i = 0; i < n; ++i)
			if (castle[i][j] == 'X')
				found = 0;
		if (found) col++;
	}

	cout << max(row, col);
}