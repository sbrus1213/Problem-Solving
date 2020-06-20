// BOJ 1153 네 개의 소수
// 수학 erathosthenes sieve - 골드바흐의 추측

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
const int mxn = 1e6 + 1;

bitset<mxn> p;
vector<int> prime;

void sieve() {
	p.set();
	p[0] = p[1] = 0;
	for (int i = 2; i < mxn; ++i) {
		if (!p[i]) continue;
		prime.push_back(i);
		for (int j = 2; i * j < mxn; ++j)
			p[i * j] = 0;
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	if (n < 8) {
		cout << -1;
		return 0;
	}

	sieve();

	vector<int> ans;
	ans.push_back(2);
	if (n % 2) ans.push_back(3);
	else ans.push_back(2);
	n -= ans[0] + ans[1];

	for (int pr : prime) {
		if (!p[n - pr]) continue;
		ans.push_back(pr);
		ans.push_back(n - pr);
		break;
	}

	sort(ans.begin(), ans.end());
	for (int x : ans) cout << x << ' ';
}