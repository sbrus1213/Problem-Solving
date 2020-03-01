// BOJ 14501 Επ»η
// Brute Force

#include <iostream>
#include <algorithm>
using namespace std;

int n, time[16], price[16], maxp[16] = {};

int find_max(int today) {
	if (today > n) return 0;
	if (today == n) {
		if (time[today] == 1) return price[today];
		else return 0;
	}

	int res = 0;

	if (time[today] <= n - today + 1) {
		res = max(res, find_max(today + time[today]) + price[today]);
	}
	res = max(res, find_max(today + 1));

	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> time[i] >> price[i];

	cout << find_max(1);
}