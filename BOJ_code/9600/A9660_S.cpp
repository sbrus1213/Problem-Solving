// BOJ 9660 µπ ∞‘¿” 6
// game theory & nim game

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	long long n; cin >> n;
	if (n % 7 == 0 || n % 7 == 2) cout << "CY";
	else cout << "SK";
}