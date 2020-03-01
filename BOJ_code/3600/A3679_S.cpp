// BOJ 3679 단순 다각형
// ccw & sort

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

int n;
vector<pii > P;

int ccw(pii a, pii b, pii c) {
	b = { b.x - a.x , b.y - a.y };
	c = { c.x - a.x, c.y - a.y };
	int ret = b.x * c.y - b.y * c.x;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}
bool cmp(pii& a, pii& b) {
	if (ccw(P[0], a, b) == 0)
		return (a.x != b.x ? a.x - P[0].x < b.x - P[0].x : a.y - P[0].y < b.y - P[0].y);
	else return ccw(P[0], a, b) == 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		P.clear();
		map<pii, int> dic;
		for (int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			P.push_back({ x, y });
			dic[{x, y}] = i;
		}
		swap(P[0], *min_element(P.begin(), P.end()));
		sort(P.begin() + 1, P.end(), cmp);
		int i;
		for (i = n - 1; i > 0; --i) {
			if (ccw(P[0], P[i], P[i - 1]) == 0) continue;
			else break;
		}
		reverse(P.begin() + i, P.end());
		for (int i = 0; i < n; ++i)
			cout << dic[P[i]] << ' ';
		cout << '\n';
	}
}