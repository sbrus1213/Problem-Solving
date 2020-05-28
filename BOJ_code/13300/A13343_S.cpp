// BOJ 13343 Block Game
// game theory

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b; cin >> a >> b;
	bool fl = true;

	while (a && b) {
		if (a < b) swap(a, b);
		if (a == b || a >= 2 * b) break;
		else {
			a -= b;
			fl = !fl;
		}
	}
	if (fl) cout << "win";
	else cout << "lose";
}