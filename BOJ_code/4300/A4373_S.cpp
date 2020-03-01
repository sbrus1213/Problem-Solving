// BOJ 4373 МіС§Че
// Two pointer

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()
#define MX ((1<<31)-1)
#define MIN (-(1<<31)+1)

struct two {
	int x, y, res;
};
bool comp_less(two a, two b) {
	return a.res > b.res;
}
bool comp_greater(two a, two b) {
	return a.res < b.res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	while (n) {
		vector<int> num(n);

		for (int i = 0; i < n; ++i) cin >> num[i];
		sort(BtoE(num));

		if (n < 4) cout << "no solution\n";
		else {
			vector<two> a_plus_b, c_minus_d;

			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					a_plus_b.push_back({ num[i], num[j], num[i] + num[j] });
					c_minus_d.push_back({ num[i], num[j], num[i] - num[j] });
				}
			}

			int len = a_plus_b.size(), i = 0, j = 0, tmp, res = MIN;
			a_plus_b.push_back({ 0,0,MX });
			c_minus_d.push_back({ 0,0,MIN });
			sort(BtoE(a_plus_b), comp_greater);
			sort(BtoE(c_minus_d), comp_less);

			while (i < len && j < len) {
				tmp = a_plus_b[i].res + c_minus_d[j].res;

				if (tmp > 0) ++j;
				else if (tmp < 0) ++i;
				else {
					int ti = i, tj = j;
					while (a_plus_b[ti].res == a_plus_b[i].res) ++ti;
					while (c_minus_d[tj].res == c_minus_d[j].res) ++tj;

					for (int a = i; a < ti; ++a) {
						for (int b = j; b < tj; ++b) {
							if (a_plus_b[a].x == c_minus_d[b].x) continue;
							if (a_plus_b[a].x == c_minus_d[b].y) continue;
							if (a_plus_b[a].y == c_minus_d[b].x) continue;
							if (a_plus_b[a].y == c_minus_d[b].y) continue;

							res = max(res, c_minus_d[b].y);
						}
					}

					i = ti; j = tj;
				}
			}

			if (res == MIN) cout << "no solution\n";
			else cout << res << '\n';
		}

		cin >> n;
	}
}