// BOJ 3780 네트워크 연결
// Union find

#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int par[20001], dist[20001];
int find(int x) {
	if (par[x] == -1) return x;
	int tmp = find(par[x]);
	dist[x] += dist[par[x]];
	return par[x] = tmp;
}
void merge(int a, int b, int d) {
	int pb = find(b);
	par[a] = pb;
	dist[a] = d + dist[b];
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		fill(par, par + 20001, -1);
		fill(dist, dist + 20001, 0);
		char com;
		while (1) {
			cin >> com;
			if (com == 'O') break;
			else if (com == 'E') {
				int x;
				cin >> x;
				find(x);
				cout << dist[x] << '\n';
			}
			else if (com == 'I') {
				int a, b;
				cin >> a >> b;// a를 b에 붙일거
				merge(a, b, abs(a - b) % 1000);
			}
		}
	}
}