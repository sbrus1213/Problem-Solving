// BOJ 16625 Das Blinkenlights
// 수학 최소공배수

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a > b) swap(a, b);
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a, b, s; cin >> a >> b >> s;

	int g = gcd(a, b);
	int l = a * b / g;

	if (s >= l) cout << "yes";
	else cout << "no";
}