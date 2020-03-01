// BOJ 13335 Æ®·°
// Greedy Algorithm

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, w, l, weight[1000], bridge[100] = {}, temp = 0, idx = 0, time = 0;

	cin >> n >> w >> l;

	for (int i = 0; i < n; ++i) cin >> weight[i];

	while (1) {
		time++;

		bool flag = false;

		if (bridge[w - 1])
			temp -= bridge[w - 1];

		for (int i = w - 1; i > 0; --i) {
			bridge[i] = bridge[i - 1];
			if (bridge[i]) flag = true;
		}
		bridge[0] = 0;

		if (idx == n && !flag) break;
		if (idx == n) continue;
		if (temp + weight[idx] > l) continue;

		bridge[0] = weight[idx++];
		temp += bridge[0];
	}

	cout << time;
}