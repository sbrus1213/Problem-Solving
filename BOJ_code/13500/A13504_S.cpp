// BOJ 13504 XOR гу
// trie

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXB = 31;

struct node {
	bool finish;
	int bit[2];
	node() :finish(false) { bit[0] = bit[1] = -1; }
};
struct trie {
	int size;
	vector<node> next;
	trie() :size(1) {
		next.push_back(node());
	}
	void insert(int num) {
		int idx = 0;
		for (int i = MAXB; i >= 0; --i) {
			int b = (num & (1 << i)) > 0;
			int id = next[idx].bit[b];
			if (id == -1) {
				next.push_back(node());
				idx = next[idx].bit[b] = size++;
			}
			else {
				idx = id;
			}
		}
		next[idx].finish = true;
	}
	int find_(int num) {
		int idx = 0, res = 0;
		for (int i = MAXB; i >= 0; --i) {
			int b = (num & (1 << i)) == 0;
			int id = next[idx].bit[b];
			if (id != -1) {
				idx = id;
				res += 1 << i;
			}
			else {
				id = next[idx].bit[1 - b];
				idx = id;
			}
		}
		return res;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<int> num(n + 1), pxor(n + 1);
		trie T;
		for (int i = 1; i <= n; ++i) {
			cin >> num[i];
			pxor[i] = pxor[i - 1] ^ num[i];
			T.insert(pxor[i]);
		}

		int res = -1;
		for (int i = 0; i <= n; ++i)
			res = max(res, T.find_(pxor[i]));
		cout << res << '\n';
	}
}