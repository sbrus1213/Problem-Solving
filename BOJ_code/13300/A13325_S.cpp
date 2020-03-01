// BOJ 13325 이진 트리
// Tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define Pii pair<int, int>

int h, node, MM, total;
vector<Pii > son;
vector<int> sum;

int get_max(int lev, int x) {
	if (lev == h) return 0;

	int& res = sum[x];
	res = max(res, get_max(lev + 1, 2 * x) + son[x].first);
	res = max(res, get_max(lev + 1, (2 * x) + 1) + son[x].second);

	return res;
}

void make_same(int lev, int x, int plus) {
	if (lev == h) return;

	son[x].first = plus - (lev == h - 1 ? 0 : sum[x * 2]);
	make_same(lev + 1, 2 * x, plus - son[x].first);

	son[x].second = plus - (lev == h - 1 ? 0 : sum[(x * 2) + 1]);
	make_same(lev + 1, (2 * x) + 1, plus - son[x].second);
}

void get_sum(int lev, int x) {
	if (lev == h) return;

	total += (son[x].first + son[x].second);

	get_sum(lev + 1, 2 * x);
	get_sum(lev + 1, (2 * x) + 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> h;
	node = pow(2, h) - 1;
	son.resize(node + 1);
	sum.resize(node + 1);

	for (int i = 1; i <= node; ++i) cin >> son[i].first >> son[i].second;

	MM = get_max(0, 1);
	make_same(0, 1, MM);
	get_sum(0, 1);

	cout << total;
}