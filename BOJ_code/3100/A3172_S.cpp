// BOJ 3172 현주와 윤주의 재미있는 단어 게임
// trie

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pci = pair<char, int>;
using pcii = pair<pci, int>;

struct node {
	int finish;
	vector<pcii> pvec;
	node() :finish(0), pvec(vector<pcii >()) {}
	int find_(char c) {
		for (auto p : pvec)
			if (p.first.first == c)
				return p.first.second;
		return-1;
	}
	void plus_(char c) {
		for (auto& p : pvec)
			if (p.first.first == c) {
				p.second++;
				break;
			}
	}
};
struct trie {
	int size;
	vector<node> next;
	trie() :size(1) {
		next.push_back(node());
	}
	int insert(string str) {
		int res = 0, idx = 0;
		for (auto c : str) {
			sort(next[idx].pvec.begin(), next[idx].pvec.end());
			for (auto& p : next[idx].pvec)
				if (p.first.first < c)
					res += p.second;
				else break;
			res += next[idx].finish;
			int id = next[idx].find_(c);
			if (id == -1) {
				next.push_back(node());
				next[idx].pvec.push_back(pcii(pci(c, size), 1));
				idx = size++;
			}
			else {
				next[idx].plus_(c);
				idx = id;
			}
		}
		next[idx].finish++;
		return res;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> word;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		word.push_back(s);
	}
	sort(word.begin(), word.end());

	for (int i = 0; i < n; ++i)reverse(word[i].begin(), word[i].end());

	long long res = 0;
	trie T;
	for (int i = n - 1; i >= 0; --i)
		res += T.insert(word[i]);
	cout << res;
}