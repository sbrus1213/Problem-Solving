// BOJ 16569 È­»ê¼â¼³·ù
// BFS

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct P {
	int x, y;
	P() : x(0), y(0) {}
	P(int x, int y) : x(x), y(y) {}
	P operator + (const P rhs) {
		return P(x + rhs.x, y + rhs.y);
	}
};
bool interial(P pos, int n, int m) {
	if (pos.x > 0 && pos.y > 0 && pos.x <= n && pos.y <= m) return true;
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, v, height[101][101], check[101][101] = {},
		dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, max_h, min_t;
	vector<vector<P> > san(201);
	queue<P> man, yong;
	P cur, next;

	cin >> n >> m >> v;
	cin >> cur.x >> cur.y;

	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j) cin >> height[i][j];

	for (int i = 0; i < v; ++i) {
		int x, y, t;
		cin >> x >> y >> t;
		san[t].push_back({ x, y });
		check[x][y] = 2;
	}

	man.push(cur);
	max_h = height[cur.x][cur.y];
	min_t = 0;
	check[cur.x][cur.y] = 3;
	for (int j = 0; j < san[0].size(); ++j) {
		yong.push(san[0][j]);
		check[san[0][j].x][san[0][j].y] = 1;
	}

	for (int i = 1; ; ++i) {
		if (man.empty()) break;

		int cnt = yong.size();
		for (int j = 0; j < cnt; ++j) {
			cur = yong.front();
			yong.pop();

			for (int k = 0; k < 4; ++k) {
				next = cur + P(dx[k], dy[k]);
				if (interial(next, n, m)) {
					if (check[next.x][next.y] != 1) {
						yong.push(next);
						check[next.x][next.y] = 1;
					}
				}
			}
		}
		if (i <= 200) {
			cnt = san[i].size();
			for (int j = 0; j < cnt; ++j) {
				if (check[san[i][j].x][san[i][j].y] != 1) {
					yong.push(san[i][j]);
					check[san[i][j].x][san[i][j].y] = 1;
				}
			}
		}
		cnt = man.size();
		for (int j = 0; j < cnt; ++j) {
			cur = man.front();
			man.pop();

			for (int k = 0; k < 4; ++k) {
				next = cur + P(dx[k], dy[k]);
				if (interial(next, n, m)) {
					if (check[next.x][next.y] == 0) {
						man.push(next);
						check[next.x][next.y] = 3;
						if (height[next.x][next.y] > max_h) {
							max_h = height[next.x][next.y];
							min_t = i;
						}
					}
				}
			}
		}
	}

	cout << max_h << ' ' << min_t;
}