// BOJ 2493 탑
// stack

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> h(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	h[0] = 1e9;

	vector<int> ans(n + 1), st = { 0 };
	for (int i = 1; i <= n; ++i) {
		if (h[i] < h[i - 1]) ans[i] = i - 1;
		else {
			while (!st.empty() && h[st.back()] < h[i])
				st.pop_back();
			ans[i] = st.back();
		}
		st.push_back(i);
	}

	for (int i = 1; i < ans.size(); ++i)
		cout << ans[i] << ' ';
}