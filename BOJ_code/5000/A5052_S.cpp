// BOJ 5052 전화번호 목록
// trie

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using pci = pair<char, int>;

struct node {
	bool finish;
	vector<pci > pvec;
	int find_(char c) {
		for (auto p : pvec)
			if (p.first == c)
				return p.second;
		return -1;
	}
};
struct trie {
	int size;
	vector<node> next;
	trie() :size(1) {
		next.push_back(node());
	}
	bool insert(string& str) {
		int idx = 0;
		bool flag = true;
		for (int i = 0; i < str.size(); ++i) {
			int id = next[idx].find_(str[i]);
			if (id == -1) {
				next.push_back(node());
				next[idx].pvec.push_back(pci(str[i], size));
				idx = size++;
			}
			else idx = id;
			if (next[idx].finish) flag = false;
		}
		next[idx].finish = true;
		if (next[idx].pvec.size()) return false;
		return flag;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		bool flag = true;
		cin >> n;

		trie T;
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			if (!T.insert(s)) flag = false;
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}