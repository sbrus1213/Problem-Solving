// BOJ 2004 조합 0의 개수
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int cnt(int x, int tf) {
	int res = 0;
	while (x > tf - 1) {
		res += x / tf;
		x /= tf;
	}
	return res;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, nm; cin >> n >> m;
	nm = n - m;

	int fn = cnt(n, 5), fm = cnt(m, 5), fnm = cnt(nm, 5);
	int tn = cnt(n, 2), tm = cnt(m, 2), tnm = cnt(nm, 2);
	cout << min(fn - fm - fnm, tn - tm - tnm);
}