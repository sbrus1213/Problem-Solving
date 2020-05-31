// BOJ 6359 만취한 상범
// math

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << (int)sqrt(n) << '\n';
	}
}