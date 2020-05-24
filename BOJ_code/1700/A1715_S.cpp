// BOJ 1715 카드 정렬하기
// heap & greedy

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int x; cin >> x;
		pq.push(x);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans;
}