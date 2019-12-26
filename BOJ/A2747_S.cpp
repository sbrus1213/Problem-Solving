// BOJ 2747 피보나치 수
// Dynamic programming

#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n;
	int fibo[46] = { 0, 1 };

	cin >> n;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n];
}