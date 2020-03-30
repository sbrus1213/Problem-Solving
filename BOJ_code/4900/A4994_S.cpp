// BOJ 4994 배수 찾기
// BFS

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		if (!n) break;

		int par[201];
		fill(par, par + 201, -1);

		int s = 1;
		queue<int> Q;
		Q.push(s);
		par[s] = 0;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int nxt = cur * 10; nxt <= cur * 10 + 1; ++nxt) {
				if (par[nxt % n] == -1) {
					par[nxt % n] = cur;
					Q.push(nxt % n);
				}
			}
			if (par[0] != -1) break;
		}

		string str;
		s = 0;
		while (1) {
			if (!par[s]) break;
			if ((par[s] * 10) % n == s) str.push_back('0');
			else str.push_back('1');
			s = par[s];
		}
		str.push_back('1');
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}