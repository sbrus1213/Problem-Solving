// BOJ 14681 사분면 고르기
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int x, y; cin >> x >> y;

	if (x > 0 && y > 0) cout << 1;
	else if (x < 0 && y > 0) cout << 2;
	else if (x < 0) cout << 3;
	else cout << 4;
}