// BOJ 10870 피보나치 수 5
// fibonacci 구현

#include <iostream>
using namespace std;

int fibo(int n) {
	if (n < 2) return n;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << fibo(n);
}