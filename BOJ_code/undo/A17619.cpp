// BOJ 17619 개구리 점프
// union find DSU

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int xl, xr, y, i;
};

vector<int> par;
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	par[y] = x;
	return;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	vector<node> tong(n);

}