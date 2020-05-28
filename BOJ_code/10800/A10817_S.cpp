// BOJ 10817 세 수
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a[3]; 
	for (int i = 0; i < 3; ++i) cin >> a[i];
	sort(a, a + 3);
	cout << a[1];
}