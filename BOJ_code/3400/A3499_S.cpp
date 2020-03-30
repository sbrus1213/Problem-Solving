// BOJ 3499 미토콘드리아 이브
// union find

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using node = pair<int, int>;
#define id first
#define dna second

vector<int> par;
int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}
bool merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, i; cin >> n;
	vector<node> mito(n + 1);
	for (i = 1; i <= n; ++i) {
		char s; cin >> s;
		mito[i] = { i, -i };
	}

	int m; cin >> m;
	par = vector<int>(n + m + 1, -1);
	vector<bool> dead(n + m + 1);
	for (int j = 0; j < m; ++j) {
		int fa; cin >> fa;
		if (fa < 0) dead[-fa] = true;
		else {
			int mo; char se; cin >> mo >> se;
			mito.push_back({ i, -i });
			merge(mo, i++);
		}
	}

	int k; cin >> k;
	for (int j = 0; j < k; ++j) {
		int x, y; cin >> x >> y;
		mito[find(x)].dna = y;
	}

	int res = -1e9, flag = 0;
	for (auto& x : mito) {
		if (!x.id) continue;
		if (!dead[x.id]) {
			int tmp = mito[find(x.id)].dna;
			if (res == -1e9) {
				res = tmp;
				flag++;
			}
			else {
				if (tmp == res) continue;
				else {
					if (res > 0 && tmp > 0) {
						flag = -1;
						break;
					}
					else {
						res = max(res, tmp);
						flag++;
					}
				}
			}
		}
	}
	if (flag == -1) cout << "NO";
	else if (flag == 1) cout << "YES";
	else cout << "POSSIBLY";
}