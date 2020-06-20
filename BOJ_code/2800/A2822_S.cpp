// BOJ 2822 점수 계산
// 구현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	vector<int> num(8), chk(8);
	for (int i = 0; i < 8; ++i) cin >> num[i];

	int mn = 200, id;
	for (int i = 0; i < 8; ++i) {
		if (num[i] < mn) {
			mn = num[i];
			id = i;
		}
	}
	chk[id] = 1;

	mn = 200;
	for (int i = 0; i < 8; ++i) {
		if (!chk[i] && num[i] < mn) {
			mn = num[i];
			id = i;
		}
	}
	chk[id] = 1;

	mn = 200;
	for (int i = 0; i < 8; ++i) {
		if (!chk[i] && num[i] < mn) {
			mn = num[i];
			id = i;
		}
	}
	chk[id] = 1;

	int sum = 0;
	for (int i = 0; i < 8; ++i) 
		if (!chk[i])
			sum += num[i];
	cout << sum << "\n";
	for (int i = 0; i < 8; ++i)
		if (!chk[i])
			cout << i + 1 << ' ';
}