// BOJ 14425 문자열 집합
// Trie

/*
#include <iostream>
#include <string>
using namespace std;

struct trie {
	bool finish;
	trie* sub[26];
	trie() : finish(false) {
		for (int i = 0; i < 26; ++i) sub[i] = NULL;
	}
	void insert(string& str, int idx) {
		if (idx == str.size()) {
			finish = true;
			return;
		}

		int id = str[idx] - 'a';
		if (!sub[id]) sub[id] = new trie();
		sub[id]->insert(str, idx + 1);
	}
	bool search(string& str, int idx) {
		if (idx == str.size()) {
			return finish;
		}

		int id = str[idx] - 'a';
		if (!sub[id]) return false;
		return sub[id]->search(str, idx + 1);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	trie T;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		T.insert(s, 0);
	}

	int res = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (T.search(s, 0)) res++;
	}
	cout << res;
}
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using pci = pair<char, int>;

struct node {
	bool finish;
	vector<pci > next;
	int find_(char c) {
		for (auto p : next)
			if (p.first == c)
				return p.second;
		return -1;
	}
};
struct trie {
	int size;
	vector<node> sub;
	trie() :size(1) {
		sub.push_back(node());
	}
	void insert(string& str) {
		int idx = 0;
		for (int i = 0; i < str.size(); ++i) {
			int id = sub[idx].find_(str[i]);
			if (id == -1) {
				sub.push_back(node());
				sub[idx].next.push_back(pci(str[i], size));
				idx = size++;
			}
			else idx = id;
		}
		sub[idx].finish = true;
	}
	bool search(string& str) {
		int idx = 0;
		for (int i = 0; i < str.size(); ++i) {
			int id = sub[idx].find_(str[i]);
			if (id == -1)
				return false;
			idx = id;
		}
		return sub[idx].finish;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	trie T;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		T.insert(s);
	}

	int res = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (T.search(s)) res++;
	}
	cout << res;
}

/*
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<string, int> M;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		M[s] = 1;
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (M[s]) res++;
	}
	cout << res;
}
*/