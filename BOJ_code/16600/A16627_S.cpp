// BOJ 16627 Froggie
// 구현

#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

struct lane {
	int start, inter, speed;
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int l, w; cin >> l >> w;

	vector<lane> info(l + 1);
	int road[12][20] = {};
	for (int i = 1; i <= l; ++i) {
		cin >> info[i].start >> info[i].inter >> info[i].speed;
		int start = (i % 2 ? info[i].start : w - 1 - info[i].start);
		if (i % 2) for (int j = start; j < w; j += info[i].inter)
			road[i][j] = 1;
		else for (int j = start; j >= 0; j -= info[i].inter)
			road[i][j] = 1;
	}

	int pos; string path; cin >> pos >> path;
	int fx = l + 1, fy = pos, len = path.size();
	for (int i = 0; i < len; ++i) {
		int nx = fx, ny = fy;
		if (path[i] == 'U') nx -= 1;
		else if (path[i] == 'D') nx += 1;
		else if (path[i] == 'L') ny -= 1;
		else if (path[i] == 'R') ny += 1;

		int tmp[12][20] = {};
		for (int k = 1; k <= l; ++k) {
			deque<int> dq, qq;
			for (int j = 0; j < w; ++j)
				if (road[k][j])
					dq.push_back(j);

			if (k % 2) for (int j = dq.front() - info[k].inter; j >= -2 * w; j -= info[k].inter)
				dq.push_front(j);
			else for (int j = dq.back() + info[k].inter; j < 3 * w; j += info[k].inter)
				dq.push_back(j);

			if (k % 2) {
				while (!dq.empty()) {
					int cur = dq.back(); dq.pop_back();
					qq.push_front(cur);
					if (info[k].speed == 0) {
						if (cur >= 0 && cur < w) tmp[k][cur] = 1;
						continue;
					}
					for (int j = cur + 1; j <= cur + info[k].speed; ++j)
						if (j >= 0 && j < w)
							tmp[k][j] = 1;
				}
			}
			else {
				while (!dq.empty()) {
					int cur = dq.front(); dq.pop_front();
					qq.push_back(cur);
					if (info[k].speed == 0) {
						if (cur >= 0 && cur < w) tmp[k][cur] = 1;
						continue;
					}
					for (int j = cur - 1; j >= cur - info[k].speed; --j)
						if (j >= 0 && j < w)
							tmp[k][j] = 1;
				}
			}

			if (k == nx && ny >= 0 && ny < w && tmp[nx][ny]) {
				cout << "squish";
				return 0;
			}

			if (k % 2) {
				while (!qq.empty()) {
					int cur = qq.back(); qq.pop_back();
					if (cur >= 0 && cur < w) road[k][cur] = 0;
					int nxt = cur + info[k].speed;
					if (nxt >= 0 && nxt < w) road[k][nxt] = 1;
				}
			}
			else {
				while (!qq.empty()) {
					int cur = qq.front(); qq.pop_front();
					if (cur >= 0 && cur < w) road[k][cur] = 0;
					int nxt = cur - info[k].speed;
					if (nxt >= 0 && nxt < w) road[k][nxt] = 1;
				}
			}
		}

		fx = nx, fy = ny;
	}

	if (fx == 0) cout << "safe";
	else cout << "squish";
	return 0;
}