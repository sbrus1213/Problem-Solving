// BOJ 4344 평균은 넘겠지
// 수학

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		vector<int> score(n);
		int tot = 0;
		for (int i = 0; i < n; ++i) {
			cin >> score[i];
			tot += score[i];
		}

		double avg = 1.0 * tot / n;

		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (score[i] > avg)
				ans++;

		cout << fixed;
		cout.precision(3);
		cout << 1.0 * ans * 100 / n << "%\n";
	}
}