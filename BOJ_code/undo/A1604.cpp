// BOJ 1604 정사각형 자르기
// 기하

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct Line {
	pii p1, p2;
};

pii operator- (pii a, pii b) {
	return pii(a.first - b.first, a.second - b.second);
}

int ccw(pii a, pii b) {
	int ret = a.second * b.first - a.first * b.second;
	if (!ret) return 0;
	return (ret > 0 ? 1 : -1);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii> base = { {10, 10}, {-10, 10}, {-10, -10}, {10, -10} };
	vector<Line> line;
	for (int i = 0; i < n; ++i) {
		pii p1, p2; cin >> p1.first >> p1.second >> p2.first >> p2.second;

		bool posi = false, nega = true;
		for (auto po : base) {
			int t = ccw(p2 - p1, po - p1);
			if (!t) continue;
			if (t > 0) posi = true;
			else nega = true;
		}
		if (!posi || !nega) continue;

		line.push_back({ p1, p2 });
	}

	int lc = line.size(), pc = 0;

	for (int i = 0; i < lc; ++i) {
		for (int j = i + 1; j < lc; ++j) {
			if (!ccw(line[i].p2 - line[i].p1, line[j].p2 - line[j].p1)) continue;

		}
	}

}