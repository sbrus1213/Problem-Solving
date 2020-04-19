// BOJ 13343 Block Game
// nim game

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
		if (!(a % b)) break;
		if (a >= 2 * b) {
			a %= b;
		}
		else {
			a -= b;
			fl = !fl;
		}
	}
	if (fl) cout << "win";
	else cout << "lose";
}