// BOJ 16928 뱀과 사다리 게임
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int r, s; cin >> r >> s;

	int go[101] = {};
	for (int i = 0; i < r + s; ++i) {
		int f, t; cin >> f >> t;
		go[f] = t - f;
	}

	int dist[101] = {};
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= 6; ++i) {
			int nxt = cur + i;
			if (nxt > 100) break;
			if (dist[nxt]) continue;
			dist[nxt] = dist[cur] + 1;
			if (go[nxt]) {
				nxt += go[nxt];
				if (dist[nxt]) continue;
				dist[nxt] = dist[cur] + 1;
			}
			q.push(nxt);
		}
	}
	cout << dist[100];
}