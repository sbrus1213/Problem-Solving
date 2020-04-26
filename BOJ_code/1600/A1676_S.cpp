// BOJ 1676 팩토리얼 0의 개수
// 수학

#include <iostream>
using namespace std;

inline int cnt(int i) {
	int res = 0;
	while (!(i % 5)) {
		i /= 5;
		res++;
	}
	return res;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 0;
	for (int i = 5; i <= n; ++i) {
		if (!(i % 5)) ans += cnt(i);
	}
	cout << ans;
}