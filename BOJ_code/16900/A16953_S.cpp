// BOJ 16953 A -> B
// bfs

#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a, b; cin >> a >> b;

	map<int, int> dist;
	dist[b] = 1;
	queue<int> q;
	q.push(b);
	while (!q.empty() && !dist[a]) {
		int x = q.front(); q.pop();

		if (!(x % 2) && x / 2 >= a && !dist[x / 2]) {
			dist[x / 2] = dist[x] + 1;
			q.push(x / 2);
		}

		if ((x % 10) == 1 && x / 10 >= a && !dist[x / 10]) {
			dist[x / 10] = dist[x] + 1;
			q.push(x / 10);
		}
	}

	if (dist[a]) cout << dist[a];
	else cout << -1;
}