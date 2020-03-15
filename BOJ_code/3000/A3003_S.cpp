// BOJ 3003 Å·,Äý,·è,ºñ¼ó,³ªÀÌÆ®,Æù
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a[] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; ++i) {
		int x; cin >> x;
		cout << a[i] - x << ' ';
	}
}