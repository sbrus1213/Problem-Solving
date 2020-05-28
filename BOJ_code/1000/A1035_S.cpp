// BOJ 1035 조각 움직이기
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct node {
	int board;
	vector<int> po;
};

int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

bool check(node state) {
	int vis = 0, cnt = 0;
	queue<int> q;
	q.push(state.po[0]);
	vis ^= (1 << state.po[0]);
	while (!q.empty()) {
		cnt++;
		int cur = q.front(); q.pop();
		int cx = cur / 5, cy = cur % 5;
		for (int k = 0; k < 4; ++k) {
			int nx = cx + dx[k], ny = cy + dy[k];
			int y = nx * 5 + ny;
			if (nx < 0 || nx > 4) continue;
			if (ny < 0 || ny > 4) continue;
			if (vis & (1 << y)) continue;
			if (!(state.board & (1 << y))) continue;
			vis |= (1 << y);
			q.push(y);
		}
	}
	return cnt == state.po.size();
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int board = 0, p = 1;
	node start;
	for (int i = 0; i < 25; ++i) {
		char c; cin >> c;
		board += p * (c == '*' ? 1 : 0);
		p *= 2;
		if (c == '*') start.po.push_back(i);
	}
	start.board = board;

	map<int, int> dist;
	dist[board] = 1;
	queue<node> q;
	q.push(start);
	int ans = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (check(cur)) {
			ans = dist[cur.board] - 1;
			break;
		}
		for (int i = 0; i < cur.po.size(); ++i) {
			int x = cur.po[i];
			int cx = x / 5, cy = x % 5;
			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k], ny = cy + dy[k];
				int y = nx * 5 + ny;
				if (nx < 0 || nx > 4) continue;
				if (ny < 0 || ny > 4) continue;
				if (cur.board & (1 << y)) continue;

				int bo = cur.board;
				bo ^= (1 << x);
				bo |= (1 << y);
				if (dist[bo]) continue;

				dist[bo] = dist[cur.board] + 1;
				node nxt = { bo, cur.po };
				nxt.po[i] = y;
				q.push(nxt);
			}
		}
	}
	cout << ans;
}