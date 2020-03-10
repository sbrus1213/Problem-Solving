// BOJ 16936 ³ª3 °ö2
// Á¤·Ä

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;

vector<pii > A;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	A = vector<pii >(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i].first;
		ll a = A[i].first;
		while (!(a % 3)) {
			A[i].second++;
			a /= 3;
		}
	}
	sort(A.begin(), A.end(), [&](pii a, pii b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
		});
	for (int i = 0; i < n; ++i) cout << A[i].first << ' ';
}