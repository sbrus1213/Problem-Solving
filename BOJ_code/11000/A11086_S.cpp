// BOJ 11086 All about that base
// ¼öÇÐ

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int ci(char c) {
	if (c <= '9') return c - '0';
	return 10 + c - 'a';
}
char ic(int i) {
	if (i == 36) return '0';
	if (i < 10) return i + '0';
	return -10 + i + 'a';
}
bool solve(int i, ll x, ll y, ll z) {
	if (!i) return (x + y == z);
	if (i == 1) return (x - y == z);
	if (i == 2) return (x * y == z);
	return ((double)x / y == (double)z);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		string x, y, z, op, d;
		cin >> x >> op >> y >> d >> z;
		int oper;

		if (op == "+") oper = 0;
		else if (op == "-") oper = 1;
		else if (op == "*") oper = 2;
		else oper = 3;

		int mx = 0, mn = 38;
		for (char c : x) mx = max(mx, ci(c)), mn = min(mn, ci(c));
		for (char c : y) mx = max(mx, ci(c)), mn = min(mn, ci(c));
		for (char c : z) mx = max(mx, ci(c)), mn = min(mn, ci(c));

		string ans = "";
		if (mn == 1 && mx == 1) if (solve(oper, x.size(), y.size(), z.size())) ans.push_back('1');
		for (int i = 2; i <= 36; ++i) {
			if (mx >= i) continue;
			ll xx = 0, yy = 0, zz = 0;
			for (char c : x) xx = xx * i + ci(c);
			for (char c : y) yy = yy * i + ci(c);
			for (char c : z) zz = zz * i + ci(c);
			if (solve(oper, xx, yy, zz)) ans.push_back(ic(i));
		}

		if (ans.empty()) cout << "invalid\n";
		else cout << ans << '\n';
	}
}