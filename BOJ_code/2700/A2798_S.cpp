// BOJ 2798 ∫Ì∑¢¿Ë
// Brute force

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, num[101], sum, M = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++) {
				sum = num[i] + num[j] + num[k];
				if (sum <= m)
					M = max(M, sum);
			}
	cout << M;
}