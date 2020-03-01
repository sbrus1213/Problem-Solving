// BOJ 17389 보너스 점수

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, bonus = 0, res = 0;
	char c;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> c;

		if (c == 'O') res += i + bonus++;
		else bonus = 0;
	}

	cout << res;
}