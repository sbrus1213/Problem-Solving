// BOJ 9202 Boggle
// Trie

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using pci = pair<char, int>;

struct node {
	bool finish;
	int finded;
	vector<pci > pvec;
	node() :finish(false), finded(0), pvec(vector<pci >()) {}
	int find_(char c) {
		for (auto p : pvec)
			if (p.first == c)
				return p.second;
		return -1;
	}
};
struct trie {
	int sz;
	vector<node> next;
	trie() :sz(1) {
		next.push_back(node());
	}
	void insert(string& str) {
		int idx = 0;
		for (int i = 0; i < str.size(); ++i) {
			int id = next[idx].find_(str[i]);
			if (id == -1) {
				next.push_back(node());
				next[idx].pvec.push_back(pci(str[i], sz));
				idx = sz++;
			}
			else idx = id;
		}
		next[idx].finish = true;
	}
	bool find_(string& str, int b) {
		int idx = 0;
		for (int i = 0; i < str.size(); ++i) {
			int id = next[idx].find_(str[i]);
			if (id == -1) return false;
			idx = id;
		}
		if (next[idx].finded == b || !next[idx].finish) return false;
		next[idx].finded = b;
		return true;
	}
};

int di[8] = { -1,-1,-1,0,1,1,1,0 }, dj[8] = { -1,0,1,-1,-1,0,1,1 };

int point(string& str) {
	if (str.size() < 3) return 0;
	else if (str.size() < 5) return 1;
	else if (str.size() < 6) return 2;
	else if (str.size() < 7) return 3;
	else if (str.size() < 8) return 5;
	else return 11;
}

trie T;
int tot_score;
string res;
vector<vector<char> > board;
vector<vector<bool> > vis;
vector<string> ans;

void dfs(pii cur, int b) {
	if (T.find_(res, b)) {
		tot_score += point(res);
		ans.push_back(res);
	}

	if (res.size() == 8) return;

	for (int k = 0; k < 8; ++k) {
		pii next;
		next.first = cur.first + di[k];
		next.second = cur.second + dj[k];

		if (!(next.first >= 0 && next.first < 4)) continue;
		if (!(next.second >= 0 && next.second < 4)) continue;
		if (vis[next.first][next.second]) continue;

		vis[next.first][next.second] = true;
		res.push_back(board[next.first][next.second]);
		dfs(next, b);
		res.pop_back();
		vis[next.first][next.second] = false;
	}
}

bool comp(string a, string b) {
	if (a.size() > b.size()) return true;
	else if (a.size() < b.size()) return false;
	else return a < b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		T.insert(s[i]);
	}

	int b;
	cin >> b;
	board.resize(4, vector<char>(4));
	vis.resize(4, vector<bool>(4));
	for (int i = 1; i <= b; ++i) {
		for (int j = 0; j < 4; ++j)
			fill(vis[j].begin(), vis[j].end(), false);
		tot_score = 0;
		ans.clear();

		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				cin >> board[j][k];

		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				vis[j][k] = true;
				res.push_back(board[j][k]);
				dfs(pii(j, k), i);
				res.pop_back();
				vis[j][k] = false;
			}
		}

		sort(ans.begin(), ans.end(), comp);
		cout << tot_score << ' ' << ans[0] << ' ' << ans.size() << '\n';
	}
}