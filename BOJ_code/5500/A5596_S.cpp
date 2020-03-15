// BOJ 5596 시험 점수
// 구현

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, s, t;
	cin >> a >> b >> c >> d; s = a + b + c + d;
	cin >> a >> b >> c >> d; t = a + b + c + d;
	cout << max(s, t);
}