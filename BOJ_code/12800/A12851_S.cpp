// BOJ 12851 숨바꼭질 2
// bfs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	if (n >= k) {
		cout << n - k << ' ' << 1;
		return 0;
	}

	vector<int> time(2 * k + 1, -1), cnt(2 * k + 1);
	queue<int> q;
	time[n] = 0;
	cnt[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == k) break;

		if (cur * 2 <= 2 * k) {
			if (time[cur * 2] == -1) {
				time[cur * 2] = time[cur] + 1;
				cnt[cur * 2] = cnt[cur];
				q.push(cur * 2);
			}
			else if (time[cur * 2] == time[cur] + 1)
				cnt[cur * 2] += cnt[cur];
		}
		if (cur + 1 <= 2 * k) {
			if (time[cur + 1] == -1) {
				time[cur + 1] = time[cur] + 1;
				cnt[cur + 1] = cnt[cur];
				q.push(cur + 1);
			}
			else if (time[cur + 1] == time[cur] + 1)
				cnt[cur + 1] += cnt[cur];
		}
		if (cur - 1 >= 0) {
			if (time[cur - 1] == -1) {
				time[cur - 1] = time[cur] + 1;
				cnt[cur - 1] = cnt[cur];
				q.push(cur - 1);
			}
			else if (time[cur - 1] == time[cur] + 1)
				cnt[cur - 1] += cnt[cur];
		}
	}
	cout << time[k] << ' ' << cnt[k];
}