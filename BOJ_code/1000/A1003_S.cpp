// BOJ 1003 피보나치 함수
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> zero(41, -1), one(41, -1);

void go(int n) {
	if (zero[n] != -1) return;

	go(n - 1);
	zero[n] = zero[n - 1] + zero[n - 2];
	one[n] = one[n - 1] + one[n - 2];
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	zero[1] = one[0] = 0;
	zero[0] = one[1] = 1;

	while (tc--) {
		int n; cin >> n;

		go(n);
		cout << zero[n] << ' ' << one[n] << '\n';
	}
}