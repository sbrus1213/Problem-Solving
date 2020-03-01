// BOJ 16066 Fighting Monsters
// ±¸Çö

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>\

using namespace std;
#define ll	long long
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Psi pair<string, int>
#define Tii tuple<int, int, int>

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a = 1, b = 2;
	vector<int> input;
	vector<Pii > index;

	bool check[1000001];
	memset(check, false, sizeof(check));

	map<int, int> dic;
	dic[a] = b;

	while (b < 1000000) {
		int t = b;
		b = a + b;
		a = t;

		dic[a] = b;
	}

	cin >> n;
	input.resize(n);
	index.resize(n);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		check[x] = true;
		input[i] = x;
		index[i] = { x, i + 1 };
	}
	sort(BtoE(index));
	sort(BtoE(input));

	bool flag = false;

	if (input[0] == input[1] && input[0] == 1) {
		flag = true;
		cout << index[0].second << ' ' << index[1].second;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (check[dic[input[i]]]) {
				int lb = lower_bound(BtoE(input), dic[input[i]]) - input.begin();
				flag = true;
				cout << index[i].second << ' ' << index[lb].second;
			}
		}
	}

	if (!flag) cout << "impossible";
}