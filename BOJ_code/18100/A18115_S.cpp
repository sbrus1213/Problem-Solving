// BOJ 18115 카드 놓기
// Deque

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	vector<int> comm;
	deque<int> ans;

	cin >> n;
	comm.resize(n);

	for (int i = n - 1; i >= 0; --i)
		cin >> comm[i];

	for (int i = 0; i < n; ++i) {
		if (comm[i] == 1) 
			ans.push_front(i + 1);
		else if (comm[i] == 2) {
			int tmp = ans.front();
			ans.pop_front();
			ans.push_front(i + 1);
			ans.push_front(tmp);
		}
		else 
			ans.push_back(i + 1);
	}

	deque<int>::iterator it = ans.begin();
	for (; it != ans.end(); it++)
		cout << *it << ' ';
}