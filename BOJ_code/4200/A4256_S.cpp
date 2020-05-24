// BOJ 4256 트리
// tree traversal

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> pre, in, post;

void go(int prel, int prer, int inl, int inr, int postl, int postr) {
	if (postl == postr) {
		post[postl] = pre[prel];
		return;
	}
	int rt = pre[prel];
	int inid = in[rt];
	post[postr] = rt;
	if (inl != inid) go(prel + 1, prel + inid - inl, inl, inid - 1, postl, postl - 1 + inid - inl);
	if (inr != inid) go(prel + 1 + inid - inl, prer, inid + 1, inr, postr - inr + inid, postr - 1);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		cin >> n;

		pre = vector<int>(n);
		in = vector<int>(n + 1);
		for (int& x : pre) cin >> x;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			in[x] = i;
		}

		post = vector<int>(n);
		go(0, n - 1, 0, n - 1, 0, n - 1);

		for (int x : post) cout << x << ' ';
		cout << '\n';
	}
}