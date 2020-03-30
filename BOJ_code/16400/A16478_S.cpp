// BOJ 16478 원의 분할
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int ab, bc, cd; cin >> ab >> bc >> cd;
	cout << fixed;
	cout.precision(6);
	cout << (double)ab * cd / bc;
}