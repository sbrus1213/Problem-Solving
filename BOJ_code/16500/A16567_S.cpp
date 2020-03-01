// BOJ 16567 바이너리 왕국

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, cnt = 0;
	bool dir = false;
	vector<bool> road;

	cin >> n >> m;
	road.resize(n + 1);

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (!dir && x == 1) cnt++;
		dir = road[i] = x;
	}

	for (int i = 0; i < m; ++i) {
		int comm;
		cin >> comm;
		if (comm) {
			int pos;
			cin >> pos;
			if (pos == 1) {
				if (!road[i]) {
					if (2 <= n && !road[2]) cnt++;
					else if (n < 2) cnt++;
				}
				road[1] = true;
			}
			else if (pos == n) {
				if (!road[n]) {
					if (2 <= n && !road[n - 1]) cnt++;
					else if (n < 2) cnt++;
				}
				road[n] = true;
			}
			else {
				if (!road[pos]) {
					if (road[pos - 1] && road[pos + 1]) cnt--;
					else if (!road[pos - 1] && !road[pos + 1]) cnt++;
				}
				road[pos] = true;
			}
		}
		else cout << cnt << '\n';
	}
}