// BOJ 16692 Greedy Scheduler
// Heap

#include <iostream>
#include <queue>
using namespace std;
#define Pii pair<int, int>

struct cmp
{
	bool operator() (Pii a, Pii b) {
		if (a.second > b.second) return true;
		else if (a.second < b.second) return false;
		else return a.first > b.first;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c, time[1001];
	priority_queue<Pii, vector<Pii >, cmp> pq;

	cin >> n >> c;

	for (int i = 0; i < c; ++i) cin >> time[i];

	for (int i = 1; i <= n; ++i) pq.push(Pii(i, 0));

	for (int i = 0; i < c; ++i) {
		Pii tmp = pq.top();
		pq.pop();

		cout << tmp.first << ' ';
		tmp.second += time[i];
		pq.push(tmp);
	}
}