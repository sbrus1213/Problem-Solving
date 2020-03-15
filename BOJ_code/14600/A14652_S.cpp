// BOJ 14652 나는 행복합니다~
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;
	cout << k / m << ' ' << k % m;
}