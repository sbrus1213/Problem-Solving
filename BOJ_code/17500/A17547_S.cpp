// BOJ 17547 Floor Plan
// ¼öÇÐ

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	if (n % 2) cout << n / 2 + 1 << ' ' << n / 2;
	else if (n % 4) cout << "impossible";
	else cout << n / 4 + 1 << ' ' << n / 4 - 1;
}