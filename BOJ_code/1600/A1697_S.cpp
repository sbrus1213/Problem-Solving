// BOJ 1697 ¼û¹Ù²ÀÁú
// BFS

#include <iostream>
#include <queue>
using namespace std;
const int MAXD = 200001;

int n, k, dist[MAXD];
queue<int> Q;

void bfs(int n, int k) {
	Q.push(n);
	dist[n] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == k) return;

		if (cur - 1 >= 0 && !dist[cur - 1]) {
			dist[cur - 1] = dist[cur] + 1;
			Q.push(cur - 1);
		}
		if (cur + 1 < MAXD && !dist[cur + 1]) {
			dist[cur + 1] = dist[cur] + 1;
			Q.push(cur + 1);
		}
		if (cur * 2 < MAXD && !dist[cur * 2]) {
			dist[cur * 2] = dist[cur] + 1;
			Q.push(cur * 2);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	if (n >= k) {
		cout << n - k;
		return 0;
	}

	bfs(n, k);
	cout << dist[k] - 1;
}