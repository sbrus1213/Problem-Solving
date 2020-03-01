// BOJ 2805 나무 자르기
// Binary search

#include <iostream>
using namespace std;
using ll = long long;

ll n, m, height[1000001];
ll cut_length(ll h) {
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += height[i] > h ? height[i] - h : 0;
	return res;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> height[i];

	ll low = 0, high = 2000000000, mid, tmp;
	while (low + 1 < high) {
		mid = (low + high) / 2;
		tmp = cut_length(mid);
		if (tmp >= m) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	cout << low;
}