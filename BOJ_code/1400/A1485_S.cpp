// BOJ 1485 정사각형
// 기하

#include <iostream>
#include <algorithm>
using namespace std;
#define ll	long long

struct P {
	ll x, y;
};
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		P point[4];
		ll len[6], idx = 0;

		for (int i = 0; i < 4; ++i)
			cin >> point[i].x >> point[i].y;

		for (int i = 0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j)
				len[idx++] = (point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y);

		sort(len, len + idx);

		cout << ((len[0] == len[3]) && (len[4] == len[5])) << '\n';
	}
}