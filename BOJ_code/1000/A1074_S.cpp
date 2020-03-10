// BOJ 1074 Z
// D&C

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int get(int n, int r, int c) {
	if (n == 1) return 1;

	int hlf = n / 2;
	if (r < hlf && c < hlf)
		return get(hlf, r, c);
	else if (r < hlf && c >= hlf)
		return hlf * hlf + get(hlf, r, c - hlf);
	else if (r >= hlf && c < hlf)
		return 2 * hlf * hlf + get(hlf, r - hlf, c);
	else
		return 3 * hlf * hlf + get(hlf, r - hlf, c - hlf);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, r, c; cin >> n >> r >> c;
	cout << get(pow(2, n), r, c) - 1;
}