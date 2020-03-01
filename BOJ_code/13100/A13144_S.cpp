// BOJ 13144 List of Unique Numbers
// Two pointer

#include <iostream>
#include <vector>
using namespace std;
#define ll	long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, res = 0, back = -1;
	bool check[100001] = {};

	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; ++i) cin >> num[i];

	for (ll front = 0; front < n; ++front) {
		while (check[num[front]])
			check[num[++back]] = false;

		check[num[front]] = true;

		res += (front - back);
	}

	cout << res;
}