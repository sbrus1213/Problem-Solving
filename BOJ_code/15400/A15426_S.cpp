// BOJ 15426 GlitchBot
// 완전 탐색

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int dx, dy, n; cin >> dx >> dy >> n;

	vector<int> ins(n + 1);
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		if (s[0] == 'F') ins[i] = 0;
		else if (s[0] == 'R') ins[i] = 1;
		else ins[i] = 2;
	}

	for (int i = 1; i <= n; ++i) {
		for (int k = (ins[i] + 1) % 3, t = 0; t < 2; t++, k = (k + 1) % 3) {
			int sx = 0, sy = 0, dir = 0,
				di[] = { 0, 1, 0, -1 },
				dj[] = { 1, 0, -1, 0 };
			ins[i] = k;
			for (int j = 1; j <= n; ++j) {
				if (ins[j] == 0) sx += di[dir], sy += dj[dir];
				else if (ins[j] == 1) dir = (dir + 1) % 4;
				else dir = (dir + 3) % 4;
			}
			if (sx == dx && sy == dy) {
				cout << i << ' ';
				if (ins[i] == 0) cout << "Forward";
				else if (ins[i] == 1) cout << "Right";
				else cout << "Left";
				return 0;
			}
		}
		ins[i] = (ins[i] + 1) % 3;
	}
}