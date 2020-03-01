// BOJ 11003 최솟값 찾기
// Sliding window

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d;
	cin >> n >> d;

	vector<int> num(n);
	deque<int> DQ;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		while (!DQ.empty() && i - DQ.front() >= d) DQ.pop_front();
		while (!DQ.empty() && num[DQ.back()] > num[i]) DQ.pop_back();
		DQ.push_back(i);

		cout << num[DQ.front()] << ' ';
	}
}