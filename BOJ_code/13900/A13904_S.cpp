// BOJ 13904 °úÁ¦
// Greedy algorithm & Union find

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
using Pii = pair<int, int>;
#define BtoE(vec) vec.begin(), vec.end()

int par[1001];

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
void merge(int i, int j) {
	i = find(i), j = find(j);
	if (i == j) return;
	par[j] = i;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, ans = 0;
	priority_queue<Pii > pq;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int day, score;
		cin >> day >> score;
		pq.push(Pii(score, day));
	}

	fill(par, par + 1001, -1);
	while (!pq.empty()) {
		Pii tmp = pq.top();
		pq.pop();
		int locate = find(tmp.second);
		if (locate) {
			merge(locate - 1, tmp.second);
			ans += tmp.first;
		}
	}
	cout << ans;
}