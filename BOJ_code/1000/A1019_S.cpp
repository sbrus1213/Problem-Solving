// BOJ 1019 책 페이지
// 수학

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

ll cnt[10];
ll count(int n) {
	// n = 5024 라면?

	if (!n) return 0;
	ll res = 0;
	string s = to_string(n);
	// 1000, 2000, ... , 5000 처리
	for (int i = 1; i <= s[0] - '0'; ++i) cnt[i] += 1;
	cnt[0] += (s[0] - '0') * (s.size() - 1);
	res += (s[0] - '0') * s.size();
	if (n < 10) return res;

	ll t1 = 0, t2 = 1, temp = 0, t3 = 0;
	for (int i = 0; i < s.size() - 1; ++i) {
		temp += t1 * t2 / 10 * 9;
		t3 += t2 - 1;
		t1++;
		t2 *= 10;
	}
	ll tmp = t1 * t2 / 10, tp = t2 - 1;
	// 1~999, 1001~1999, ... , 4001~4999 처리
	cnt[0] += temp * (s[0] - '0');
	for (int i = 1; i < 10; ++i) cnt[i] += tmp * (s[0] - '0');
	for (int i = 1; i < s[0] - '0'; ++i) cnt[i] += tp, cnt[0] += t3;
	res += tmp * 9 * (s[0] - '0') + temp * (s[0] - '0') + tp * (s[0] - '0' - 1) + t3 * (s[0] - '0' - 1);

	string s_ = s.substr(1);
	int m = stoi(s_);
	// 5001~5024의 5 처리
	cnt[s[0] - '0'] += m;
	// 001~024 처리 -> 앞의 0은 무시됨
	ll t = count(m);
	res += m + t;
	// 001~024 처리 -> 무시된 앞 0만
	cnt[0] += s_.size() * m - t;
	res += s_.size() * m - t;
	return res;
}

int  main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	count(n);
	for (int i = 0; i < 10; ++i) cout << cnt[i] << ' ';
}