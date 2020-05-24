// BOJ 11286 절대값 힙
// heap 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	while (n--) {
		int x; cin >> x;
		if (x) pq.push(x);
		else {
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
}