// BOJ 13298 Robotopia
// 수학

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int l1, a1; cin >> l1 >> a1;
		int l2, a2; cin >> l2 >> a2;
		int lt, at; cin >> lt >> at;

		vector<pii> ans;
		for (int i = l1; i < lt; i += l1) {
			int c1 = i / l1;
			int l = i, a = c1 * a1;
			if ((lt - l) % l2 != 0) continue;
			int c2 = (lt - l) / l2;
			int ll = c2 * l2, aa = c2 * a2;
			if (l + ll == lt && a + aa == at) {
				ans.push_back(pii(c1, c2));
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		if (ans.size() == 1) cout << ans[0].first << ' ' << ans[0].second << '\n';
		else cout << "?\n";
	}
}