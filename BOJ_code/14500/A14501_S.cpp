// BOJ 14501 퇴사
// Brute Force

#include <iostream>
#include <algorithm>
using namespace std;

int n, time[16], price[16];

int go(int day) {
	if (day > n) return 0;
	if (day == n) return time[day] == 1 ? price[day] : 0;

	int ret = 0;
	if (day + time[day] <= n + 1)
		ret = max(ret, go(day + time[day]) + price[day]);
	ret = max(ret, go(day + 1));
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> time[i] >> price[i];

	cout << go(1);
}