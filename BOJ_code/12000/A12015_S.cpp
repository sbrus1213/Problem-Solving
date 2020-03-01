// BOJ 12015 가장 긴 증가하는 부분 수열 2
// Dynamic Programming - LIS(Lower bound) & Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

int seq[1'000'001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, idx;
	vector<int> lis;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> seq[i];

		if (lis.empty() || lis.back() < seq[i]) {
			lis.push_back(seq[i]);
		}
		else {
			int tmp = lower_bound(BtoE(lis), seq[i]) - lis.begin();

			lis[tmp] = seq[i];
		}
	}

	cout << lis.size();
}