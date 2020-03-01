// BOJ 18110 solved.ac
// Àý»çÆò±Õ

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> opinion(n);

	if (!n) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		cin >> opinion[i];
	}
	sort(BtoE(opinion));

	int except = (int)round((float)n * 0.15), tot_sum = 0;
	for (int i = except; i < n - except; ++i) {
		tot_sum += opinion[i];
	}
	cout << (int)round((float)tot_sum / (n - except * 2));
}