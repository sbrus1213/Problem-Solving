// BOJ 17546 Exits in Excess
// graph

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<int> asc, desc;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		if (u > v) desc.push_back(i);
		else asc.push_back(i);
	}
	
	if (asc.size() > m / 2) {
		cout << desc.size() << '\n';
		for (int e : desc) cout << e << '\n';
	}
	else {
		cout << asc.size() << '\n';
		for (int e : asc) cout << e << '\n';
	}
}