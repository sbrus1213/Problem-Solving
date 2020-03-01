// BOJ 2254 °¨¿Á °Ç¼³
// ccw & convex hull
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define x first
#define y second

int n;
vector<pii > P, tmp;
vector<int> CH;
vector<bool> check;

int ccw(pii a, pii b, pii c) {
	b = { b.x - a.x , b.y - a.y };
	c = { c.x - a.x, c.y - a.y };
	ll ret = b.x * c.y - b.y * c.x;
	if (ret) return ret > 0 ? 1 : -1;
	return 0;
}
bool cmp(pii& a, pii& b) {
	if (ccw(tmp[0], a, b) == 0)
		if (a.x == b.x) return a.y - tmp[0].y < b.y - tmp[0].y;
		else return a.x - tmp[0].x < b.x - tmp[0].x;
	else return ccw(tmp[0], a, b) == 1;
}
void graham_scan() {
	int m = tmp.size();
	for (int i = 0; i < m; ++i) {
		while (CH.size() >= 2) {
			int sz = CH.size();
			if (ccw(tmp[CH[sz - 2]], tmp[CH[sz - 1]], tmp[i]) < 1)
				CH.pop_back();
			else break;
		}
		CH.push_back(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	map<pii, int> dic;
	for (int i = 0; i <= n; ++i) {
		int x, y; cin >> x >> y;
		P.push_back({ x, y });
		dic[{x, y}] = i;
	}

	int cnt = 0;
	bool f;
	check = vector<bool>(n + 1, false);
	for (;; ++cnt) {
		tmp.clear(); CH.clear(); f = true;
		for (int i = 0; i <= n; ++i)
			if (!check[i])
				tmp.push_back(P[i]);
		swap(tmp[0], *min_element(tmp.begin(), tmp.end()));
		sort(tmp.begin() + 1, tmp.end(), cmp);
		graham_scan();
		if (CH.size() <= 2) break;
		for (int i : CH) {
			if (dic[tmp[i]] == 0) {
				f = false;
				break;
			}
			check[dic[tmp[i]]] = true;
		}
		if (!f) break;
	}
	cout << cnt;
}