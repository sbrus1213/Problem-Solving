// BOJ 1920 ¼ö Ã£±â
// Binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
		if (idx < n && a[idx] == x) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}