// BOJ 2754 학점계산
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	char c1, c2; cin >> c1;
	char ans[4] = { '0', '.', '0', '\0' };

	if (c1 != 'F') {
		ans[0] = 4 - (c1 - 'A') + '0';
		cin >> c2;
		if (c2 == '+') ans[2] = '3';
		else if (c2 == '0');
		else {
			ans[0]--;
			ans[2] = '7';
		}
	}
	cout << ans;
}