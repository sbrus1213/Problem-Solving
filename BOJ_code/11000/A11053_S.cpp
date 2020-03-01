// BOJ 11053 가장 긴 증가하는 부분 수열
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> lis(n, 1), arr(n);

	cin >> arr[0];
	for (int i = 1; i < n; ++i) {
		cin >> arr[i];
		for (int j = i - 1; j >= 0; --j)
			if (arr[j] < arr[i])
				lis[i] = max(lis[i], lis[j] + 1);
	}

	cout << *max_element(BtoE(lis));
}