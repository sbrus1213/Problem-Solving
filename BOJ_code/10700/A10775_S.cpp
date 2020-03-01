// BOJ 10775 °øÇ×
// Union find

#include <iostream>
#include <algorithm>
using namespace std;

int par[100001];

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
void merge(int i, int j) {
	i = find(i), j = find(j);
	if (i == j) return;
	par[j] = i;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int g, p, ans = 0, gate[100001];

	cin >> g >> p;

	for (int i = 1; i <= p; ++i) cin >> gate[i];

	fill(par, par + 100001, -1);
	for (int i = 1; i <= p; ++i) {
		int locate = find(gate[i]);
		if (locate) {
			merge(locate - 1, gate[i]);
			ans++;
		}
		else
			break;
	}
	cout << ans;
}