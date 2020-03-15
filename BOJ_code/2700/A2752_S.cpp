// BOJ 2752 세수정렬
// 정렬

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a[3]; cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[0] << ' ' << a[1] << ' ' << a[2];
}