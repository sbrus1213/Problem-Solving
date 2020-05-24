// BOJ 2751 수 정렬하기 2
// heap sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		pq.push(x);
	}

	while (!pq.empty()) {
		cout << pq.top() << '\n'; pq.pop();
	}
}