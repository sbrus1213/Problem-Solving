// BOJ 5086 배수와 약수
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	while (1) {
		int a, b;
		cin >> a >> b;
		if (!a && !b) break;

		if (a % b == 0) cout << "multiple\n";
		else if (b % a == 0) cout << "factor\n";
		else cout << "neither\n";
	}
}