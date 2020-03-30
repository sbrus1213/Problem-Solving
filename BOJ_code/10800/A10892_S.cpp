// BOJ 10892 Divide into Triangle
// sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct po {
	int x, y, i;
};
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<po> P(3 * n);
	for (int i = 0; i < 3 * n; ++i) {
		cin >> P[i].x >> P[i].y;
		P[i].i = i + 1;
	}

	sort(P.begin(), P.end(), [&](po a, po b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
		});

	for (int i = 0; i < n; ++i)
		cout << P[i * 3].i << ' ' << P[i * 3 + 1].i << ' ' << P[i * 3 + 2].i << '\n';
}