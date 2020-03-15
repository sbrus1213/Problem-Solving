// BOJ 2525 오븐 시계
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, m, c; cin >> h >> m >> c;
	int hh = (m + c) / 60;
	cout << (h + hh) % 24 << ' ' << (m + c) % 60;
}