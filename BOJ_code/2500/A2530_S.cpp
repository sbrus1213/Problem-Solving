// BOJ 2530 인공지능 시계
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, m, s, c; cin >> h >> m >> s >> c;
	int mm = (s + c) / 60;
	int hh = (m + mm) / 60;
	cout << (h + hh) % 24 << ' ' << (m + mm) % 60 << ' ' << (s + c) % 60;
}