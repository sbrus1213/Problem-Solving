// BOJ 3080 아름다룬 이름
// BOJ Trie

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 1000000007;
using pci = pair<char, int>;

ll facto[28];

struct trie {
	struct node {
		vector<pci > pvec;
		node() : pvec(vector<pci >()) {}
		int find_(char c) {
			for (auto p : pvec)
				if (p.first == c)
					return p.second;
			return -1;
		}
	};
	int sz;
	vector<node> next;
	trie() :sz(1) {
		next.push_back(node());
	}
	void insert(string& str) {
		int idx = 0;
		str += ' ';
		for (int i = 0; i < str.size(); ++i) {
			int id = next[idx].find_(str[i]);
			if (id == -1) {
				next.push_back(node());
				next[idx].pvec.push_back(pci(str[i], sz));
				idx = sz++;
			}
			else idx = id;
		}
	}
	ll count(int cur) {
		ll sum = 1;
		for (int i = 0; i < sz; ++i)
			sum = (sum * facto[next[i].pvec.size()]) % mod;
		return sum;
		/*int sum = 1;
		for (int i = 0; i < sz; ++i)
			sum = mulmod(sum, facto[next[i].pvec.size()]);
		return sum;
		/*int sum = facto[next[cur].pvec.size()];
		for (auto& nxt : next[cur].pvec)
			sum = mulmod(sum, count(nxt.second));
		return sum;*/
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	facto[0] = 1; for (int i = 1; i <= 27; ++i) facto[i] = (facto[i - 1] * i) % mod;

	int n; cin >> n;

	string s;
	trie T;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		T.insert(s);
	}
	cout << T.count(0);
}