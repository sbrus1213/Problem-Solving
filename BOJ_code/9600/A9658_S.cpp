// BOJ 9658 µπ ∞‘¿” 4
// game theory & nim game

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	long long n; cin >> n;
	if (n % 7 == 1 || n % 7 == 3) cout << "CY";
	else cout << "SK";
}