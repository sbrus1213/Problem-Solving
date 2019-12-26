// BOJ 2003 수들의 합 2
// Two pointer

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, sum, num[10001], i, j, res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	i = j = 0;
	sum = num[0];
	while (1) {
		if (sum == m) {
			res++;
			sum -= num[i++];
			if (++j == n) break;
			sum += num[j];
		}
		else if (sum > m) {
			sum -= num[i++];
		}
		else {
			if (++j == n) break;
			sum += num[j];
		}
	}
	cout << res;
}