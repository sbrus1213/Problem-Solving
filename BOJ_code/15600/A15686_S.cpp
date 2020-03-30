// BOJ 15686 치킨 배달
// Brute force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int mn = 5e8;
vector<int> dist, tmp;
vector<pii> chi, hom;

void get(int n, int k, int i) {
	if (tmp.size() == k) {
		int dsum = 0;
		for (int i = 0; i < hom.size(); ++i) {
			dist[i] = 5e8;
			for (auto& c : tmp)
				dist[i] = min(dist[i], abs(chi[c].first - hom[i].first) + abs(chi[c].second - hom[i].second));
			dsum += dist[i];
		}
		mn = min(mn, dsum);
		return;
	}
	for (int j = i; j < n; ++j) {
		tmp.push_back(j);
		get(n, k, j + 1);
		tmp.pop_back();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			if (x == 1) hom.push_back({ i, j });
			if (x == 2) chi.push_back({ i, j });
		}
	}

	dist = vector<int>(hom.size());
	get(chi.size(), m, 0);
	cout << mn;
}