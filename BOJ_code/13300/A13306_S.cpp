// BOJ 13306 Æ®¸®
// Offline query & Union find

#include <iostream>
#include <vector>
using namespace std;

struct Query {
	int op, a, b;
};

vector<int> root;

int find(int i) {
	if (root[i] == i) return i;
	return root[i] = find(root[i]);
}
void merge(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return;
	root[pb] = pa;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	vector<int> par;
	vector<bool> check;
	vector<Query> query;

	cin >> n >> q;
	root.resize(n + 1);
	par.resize(n + 1);

	for (int i = 2; i <= n; ++i) cin >> par[i];

	for (int i = 0; i < n + q - 1; ++i) {
		int op, a, b, c;
		cin >> op;
		if (op) {
			cin >> a >> b;
			query.push_back({ op, a, b });
		}
		else {
			cin >> c;
			query.push_back({ op, c, 0 });
		}
	}

	for (int i = 1; i <= n; ++i) root[i] = i;

	for (int i = n + q - 2; i >= 0; --i) {
		if (query[i].op) {
			if (find(query[i].a) == find(query[i].b)) check.push_back(true);
			else check.push_back(false);
		}
		else merge(query[i].a, par[query[i].a]);
	}

	for (int i = q - 1; i >= 0; --i)
		if (check[i]) cout << "YES\n";
		else cout << "NO\n";
}