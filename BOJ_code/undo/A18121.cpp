// BOJ 19121 문자열 압축
// Trie

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define Psi pair<string, int>
#define BtoE(vec) vec.begin(), vec.end()

struct Trie {
	map<string, Trie*> next;
	int end;
	Trie() :end(-1) {}
	~Trie() {
		map<string, Trie*>().swap(next);
	}
	void insert(string name, int id) {
		if (!name.size()) {
			end = id;
			return;
		}

		int len = name.size(), i;
		string tmp = "";

		for (i = 0; i < len; ++i) {
			tmp.push_back(name[i]);
			if (next[tmp]) {
				string subname = name.substr(i + 1);
				next[tmp]->insert(subname, id);
				break;
			}
		}
		if (i == len) {
			next[name] = new Trie;
			next[name]->insert("", id);
		}
	}
};

Trie* trie;
vector<int> res, st;
int res = 100000;

void go(Trie* cur, string name, int i) {
	if (!name.size()) {
		if (res > i) {
			res.clear();
			res = i;
			for (int j = 0; j < st.size(); ++j)
				res.push_back(st[j]);
		}
		else if (res == i) {
			for (int j = 0; j < st.size(); ++j) {
				if (res[j] <= st[j]) continue;
				else if (res[j] > st[j]) {
					res.clear();
					for (int j = 0; j < st.size(); ++j)
						res.push_back(st[j]);
					break;
				}
			}
		}
		return;
	}

	if (res <= i) return;
	if (!cur) return;

	int len = name.size(), k;
	string tmp = "";
	for (k = 0; k < len; ++k) {
		tmp.push_back(name[k]);
		if (cur->next[tmp]) {
			string subname = name.substr(k + 1);
			if (cur->next[tmp]->end != -1) {
				st.push_back(cur->next[tmp]->end);
				go(trie, subname, i + 1);
				st.pop_back();
			}
			if (subname.size())
				go(cur->next[tmp], subname, i);
			break;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<Psi > name_vec;

	cin >> n;
	trie = new Trie;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		name_vec.push_back(Psi(tmp, i));
	}
	sort(BtoE(name_vec));
	for (int i = 0; i < n; ++i) trie->insert(name_vec[i].first, name_vec[i].second);
	vector<Psi >().swap(name_vec);

	string goal;
	cin >> goal;
	go(trie, goal, 0);

	if (res == 100000) cout << "imppossible";
	else {
		cout << res << '\n';
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] + 1 << ' ';
	}
}