// BOJ 1193 분수찾기
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int c; cin >> c;

	int s = 0, t = 0;
	for (int i = 1; t < c; ++i) {
		t += i;
		s = i;
	}
	t -= s;
	s++;

	for (int i = (s % 2 ? 1 : s - 1), k = t + 1;; (s % 2 ? i++ : i--), k++) {
		if (k == c) {
			cout << i << '/' << s - i;
			return 0;
		}
	}
}