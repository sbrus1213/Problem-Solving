// BOJ 11279 최대 힙
// heap 

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	priority_queue<int> pq;
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