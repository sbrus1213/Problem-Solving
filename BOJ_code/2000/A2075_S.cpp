// BOJ 2075 N번째 큰 수
// sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> b[j];
		sort(b.begin(), b.end(), greater<int>());

		for (int j = 0, k = 0, l = 0; j + k < n; ++l)
			if (a[j] > b[k]) c[l] = a[j++];
			else c[l] = b[k++];
		a = c;
	}
	cout << a[n - 1];
}