// BOJ 1931 회의실배정
// greedy algorithm

#include <iostream>
#include <queue>
using namespace std;

struct meet {
	int s, e;
};
struct comp {
	bool operator()(meet a, meet b) {
		if (a.e < b.e) return false;
		else if (a.e == b.e) return a.s > b.s;
		else return true;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, cnt = 0;
	priority_queue<meet, vector<meet>, comp> pq;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		pq.push({ s, e });
	}

	while (!pq.empty()) {
		meet tmp = pq.top();
		pq.pop();
		cnt++;
		while (!pq.empty() && pq.top().s < tmp.e)
			pq.pop();
	}

	cout << cnt;
}