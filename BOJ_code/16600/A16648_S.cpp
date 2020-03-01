// BOJ 16648 Accumulator Battery
// ±¸Çö

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, p, use;
	float res;

	cin >> t >> p;

	if (p > 20) {
		use = 100 - p;
		p += 20;
	}
	else {
		use = (100 - p) + (20 - p);
		p *= 2;
	}

	res = (float)(t * p) / use;

	cout << fixed; cout.precision(6);
	cout << res;

}