// BOJ 16295 Criss-Cross Cables
// heap

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<int> x;

inline int dist(pii p) {
	return x[p.second] - x[p.first];
}

struct cmp {
	bool operator ()(pii a, pii b) {
		return dist(a) > dist(b);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	x = vector<int>(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	vector<int>l(m);
	for (int i = 0; i < m; ++i) cin >> l[i];
	sort(l.begin(), l.end());

	priority_queue<pii, vector<pii >, cmp> pq;
	for (int i = 0; i < n - 1; ++i) pq.push(pii(i, i + 1));

	map<pii, bool> dic;
	for (int i = 0; i < m; ++i) {
		while (!pq.empty() && dic[pq.top()]) pq.pop();
		if (pq.empty() || dist(pq.top()) > l[i]) {
			cout << "no";
			return 0;
		}
		pii p = pq.top(); pq.pop();
		if (p.first > 0)pq.push(pii(p.first - 1, p.second));
		if (p.second < n - 1) pq.push(pii(p.first, p.second + 1));
		dic[p] = true;
	}
	cout << "yes";
}