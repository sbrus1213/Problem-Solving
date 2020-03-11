// BOJ 11873 최대 직사각형
// stack - 히스토그램

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m) {
		if (!n) break;

		int height[1001];
		height[m] = -1;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!i) for (int j = 0; j < m; ++j) cin >> height[j];
			else for (int j = 0; j < m; ++j) {
				int x; cin >> x;
				height[j] = x ? height[j] + 1 : 0;
			}
			stack<pii > st;
			st.push(pii(0, height[0]));
			for (int j = 1; j <= m; ++j) {
				int l = j;
				while (!st.empty() && st.top().second > height[j]) {
					ans = max(ans, (j - st.top().first) * st.top().second);
					l = st.top().first;
					st.pop();
				}
				st.push(pii(l, height[j]));
			}
		}
		cout << ans << '\n';
	}
}