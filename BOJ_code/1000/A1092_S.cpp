// BOJ 1092 น่
// greedy algorithm

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> crane(n);
	for (int i = 0; i < n; ++i) cin >> crane[i];
	sort(crane.begin(), crane.end());

	int m; cin >> m;

	vector<int> box(m);
	map<int, int> dic;
	for (int i = 0; i < m; ++i) {
		cin >> box[i];
		dic[box[i]]++;
	}
	sort(box.begin(), box.end());

	vector<priority_queue<int> > vpq(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (box[j] <= crane[i]) vpq[i].push(box[j]);

	if (vpq[n - 1].size() != m) {
		cout << -1;
		return 0;
	}

	int time = 0;
	for (int cnt = 0; cnt < m; ++time) {
		for (int i = n - 1; i >= 0; --i) {
			while (!vpq[i].empty() && dic[vpq[i].top()] == 0) vpq[i].pop();
			if (vpq[i].empty()) continue;
			dic[vpq[i].top()]--;
			vpq[i].pop();
			cnt++;
		}
	}
	cout << time;
}