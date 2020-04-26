// BOJ 13549 ¼û¹Ù²ÀÁú 3
// BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	if (n >= k) {
		cout << n - k;
		return 0;
	}

	vector<int> time(2 * k + 1, 3 * k);
	queue<int> q;
	time[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur * 2 <= 2 * k && time[cur * 2] > time[cur]) {
			time[cur * 2] = time[cur];
			q.push(cur * 2);
		}
		if (cur + 1 <= 2 * k && time[cur + 1] > time[cur] + 1) {
			time[cur + 1] = time[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && time[cur - 1] > time[cur] + 1) {
			time[cur - 1] = time[cur] + 1;
			q.push(cur - 1);
		}
	}
	cout << time[k];
}