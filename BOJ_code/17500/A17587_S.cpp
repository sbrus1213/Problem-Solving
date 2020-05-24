// BOJ 17587 Gerrymandering
// 구현

#include <iostream>
#include <vector>
using namespace std;

struct district {
	int a, b, wa, wb;
};
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int p, d; cin >> p >> d;

	vector<district> dis(d + 1);
	for (int i = 0; i < p; ++i) {
		int dd, a, b; cin >> dd >> a >> b;
		dis[dd].a += a;
		dis[dd].b += b;
	}

	for (int i = 1; i <= d; ++i) {
		if (dis[i].a > dis[i].b) {
			dis[i].wb += dis[i].b;
			dis[i].wa += dis[i].a - ((dis[i].a + dis[i].b) / 2 + 1);
			cout << "A " << dis[i].wa << ' ' << dis[i].wb << '\n';
		}
		else {
			dis[i].wa += dis[i].a;
			dis[i].wb += dis[i].b - ((dis[i].a + dis[i].b) / 2 + 1);
			cout << "B " << dis[i].wa << ' ' << dis[i].wb << '\n';
		}
	}

	int wa = 0, wb = 0, totv = 0;
	for (int i = 1; i <= d; ++i) {
		wa += dis[i].wa;
		wb += dis[i].wb;
		totv += dis[i].a + dis[i].b;
	}
	cout << fixed;
	cout.precision(8);
	cout << (double)abs(wa - wb) / totv;
}