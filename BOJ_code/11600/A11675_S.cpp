// BOJ 11675 Jumbled Communication
// Brute force & bitwise operation

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; ++i)cin >> num[i];

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int j = 0, k = 0;
		while (1) {
			if ((j ^ k) == num[i]) {
				ans.push_back(j);
				break;
			}
			j++;
			k = (j * 2) % 256;
		}
	}

	for (int i = 0; i < n; ++i)cout << ans[i] << ' ';
}