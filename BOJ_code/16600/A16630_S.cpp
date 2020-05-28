// BOJ 16630 Left and Right
// greedy

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;

	int cnt = 0, l = s.size();
	vector<pii> move;
	for (int i = 0; i < l;) {
		if (s[i] == 'L') {
			while (i < l && s[i] == 'L') {
				cnt++;
				i++;
			}
		}
		else {
			while (i < l && s[i] == 'R') {
				cnt++;
				i++;
			}
		}
		if (s[i - 1] == 'L') move.push_back({ 1, cnt });
		else move.push_back({ 2, cnt - 1 });
		cnt = 0;
	}
	if (move[0].first == 2) move[0].second++;

	vector<int> ans;
	int c = 1;
	for (auto mv : move) {
		if (mv.first == 1) {
			int t = c + mv.second;
			for (int i = 0; i <= mv.second; ++i)
				ans.push_back(t--);
			c += mv.second + 1;
		}
		else {
			for (int i = 0; i < mv.second; ++i)
				ans.push_back(c++);
		}
	}
	if (ans.size() != n) ans.push_back(n);

	for (int x : ans) cout << x << '\n';
}