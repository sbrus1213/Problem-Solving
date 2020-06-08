// BOJ 17952 과제는 끝나지 않아!
// stack

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	stack<pii> q;
	pii cur = pii(-1, -1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x == 1) {
			if (cur.first != -1) q.push(cur);
			int a, t; cin >> a >> t;
			cur = pii(a, t - 1);
		}
		else {
			if (cur.first == -1) continue;
			else cur.second--;
		}
		if (cur.second == 0) {
			ans += cur.first;
			if (q.size()) cur = q.top(), q.pop();
			else cur = pii(-1, -1);
		}
	}
	cout << ans;
}