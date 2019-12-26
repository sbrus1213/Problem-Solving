// BOJ 1806 ºÎºÐÇÕ
// Two pointer

#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 100005;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s, num[100001], res, f, e;
	ll sum;

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];

	res = INF;
	f = e = 0;
	sum = num[0];
	while (1) {
		if (sum >= s) {
			res = min(res, e - f + 1);
			sum -= num[f++];
		}
		else {
			if (++e == n) break;
			sum += num[e];
		}
	}
	if (res == INF) cout << 0;
	else cout << res;
}