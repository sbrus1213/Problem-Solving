// BOJ 13751 Barbells
// Backtracking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lim1, lim2;
int b, p, s;
bool f;

vector<int> used;
vector<int> B, P;
vector<int> res, answer;

void dfs2(int cur, int w, int g) {
	if (w > g) return;
	if (w == g) {
		res.push_back(w * 2);
		f = true;
		return;
	}

	for (int i = cur; i < p; ++i) {
		if (used[i]) continue;
		used[i] = 2;
		dfs2(i + 1, w + P[i], g);
		used[i] = 0;
		if (f) return;
	}
}

void dfs1(int cur, int cnt, int w) {
	if (w * 2 > s) return;
	if (cnt == lim1) {
		f = false;
		dfs2(0, 0, w);
		return;
	}

	for (int i = cur; i < p; ++i) {
		if (used[i]) continue;
		used[i] = 1;
		dfs1(i + 1, cnt + 1, w + P[i]);
		used[i] = 0;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> b >> p;

	used.resize(p, 0);
	B.resize(b);
	P.resize(p);

	for (int i = 0; i < b; ++i) cin >> B[i];
	for (int i = 0; i < p; ++i) cin >> P[i], s += P[i];

	res.push_back(0);
	for (int i = 1; i <= p / 2; ++i) {
		lim1 = i;
		dfs1(0, 0, 0);
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	for (int i = 0; i < res.size(); ++i)
		for (int j = 0; j < b; ++j)
			answer.push_back(res[i] + B[j]);

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (int i = 0; i < answer.size(); ++i) cout << answer[i] << '\n';
}