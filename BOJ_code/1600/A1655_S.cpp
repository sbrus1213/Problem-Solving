// BOJ 1655 가운데를 말해요
// Heap

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, mid, x;
	priority_queue<int, vector<int>, less<int> > max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;

	cin >> n >> x;
	max_heap.push(-10001);
	min_heap.push(10001);

	mid = x;
	cout << mid << '\n';

	for (int i = 1; i < n; ++i) {
		cin >> x;

		if (i % 2) {
			if (x >= mid)
				min_heap.push(x);
			else if (x< mid && x>max_heap.top()) {
				min_heap.push(mid);
				mid = x;
			}
			else {
				min_heap.push(mid);
				mid = max_heap.top();
				max_heap.pop();
				max_heap.push(x);
			}
		}
		else {
			if (x <= mid)
				max_heap.push(x);
			else if (x > mid && x < min_heap.top()) {
				max_heap.push(mid);
				mid = x;
			}
			else {
				max_heap.push(mid);
				mid = min_heap.top();
				min_heap.pop();
				min_heap.push(x);
			}
		}

		cout << mid << '\n';
	}
}