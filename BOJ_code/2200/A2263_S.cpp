// BOJ 2263 트리의 순회
// tree traversal

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> pre, in, post;

void go(int prel, int prer, int inl, int inr, int postl, int postr) {
	if (prel == prer) {
		pre[prel] = post[postl];
		return;
	}
	int rt = post[postr];
	int inid = in[rt];
	pre[prel] = rt;

	if (inl != inid) go(prel + 1, prel + inid - inl, inl, inid - 1, postl, postl - 1 + inid - inl);
	if (inr != inid) go(prel + 1 + inid - inl, prer, inid + 1, inr, postl + inid - inl, postr - 1);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	post = vector<int>(n + 1);
	in = vector<int>(n + 1);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		in[x] = i;
	}
	for (int i = 0; i < n; ++i) cin >> post[i];

	pre = vector<int>(n + 1);
	go(0, n - 1, 0, n - 1, 0, n - 1);

	for (int i = 0; i < n; ++i) cout << pre[i] << ' ';
}