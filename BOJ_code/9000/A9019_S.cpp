// BOJ 9019 DSLR
// BFS

#include <iostream>
#include <queue>
using namespace std;
const int MAXD = 10000;

int n, k;
string command[MAXD];
queue<int> Q;

int D(int x) {
	x *= 2;
	return x > 9999 ? x - 10000 : x;
}
int S(int x) {
	x -= 1;
	return x == -1 ? 9999 : x;
}
int L(int x) {
	x *= 10;
	x = x % 10000 + x / 10000;
	return x;
}
int R(int x) {
	x = x / 10 + (x % 10) * 1000;
	return x;
}

void bfs(int n, int k) {
	Q.push(n);
	command[n] = "A";

	while (!Q.empty()) {
		int cur = Q.front(), next;
		Q.pop();

		if (cur == k) return;

		next = D(cur);
		if (!command[next].size()) {
			command[next] = command[cur] + 'D';
			Q.push(next);
		}

		next = S(cur);
		if (!command[next].size()) {
			command[next] = command[cur] + 'S';
			Q.push(next);
		}

		next = L(cur);
		if (!command[next].size()) {
			command[next] = command[cur] + 'L';
			Q.push(next);
		}

		next = R(cur);
		if (!command[next].size()) {
			command[next] = command[cur] + 'R';
			Q.push(next);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		while (1) {
			queue<int> qq;
			swap(Q, qq);
			break;
		}
		for (int i = 0; i < MAXD; ++i) command[i] = "";

		cin >> n >> k;

		bfs(n, k);
		for (int i = 1; i < command[k].size(); ++i) cout << command[k][i];
		cout << '\n';
	}
}