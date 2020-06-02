// BOJ 3053 택시 기하학
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	double r; cin >> r;

	cout << fixed;
	cout.precision(6);
	cout << r * r * 3.141592653589 << '\n' << 2 * r * r;
}