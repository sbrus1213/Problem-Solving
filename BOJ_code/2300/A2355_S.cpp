// BOJ 2355 시그마
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b; cin >> a >> b;
	if (a > b) swap(a, b);
	cout << (a + b) * (b - a + 1) / 2;
}