// BOJ 1252 이진수 더하기
// 수학

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string a, b; cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector<int> av(90), bv(90);
	for (int i = 0; i < a.length(); ++i)
		av[i] = a[i] - '0';
	for (int i = 0; i < b.length(); ++i)
		bv[i] = b[i] - '0';

	vector<int> ansv(90);
	for (int i = 0; i < 89; ++i) {
		ansv[i] += av[i] + bv[i];
		if (ansv[i] > 1) {
			ansv[i + 1] += ansv[i] / 2;
			ansv[i] %= 2;
		}
	}
	string ans = "";
	for (int i = 0; i < 90; ++i)
		ans += '0' + ansv[i];
	while (ans.size() && ans.back() == '0') 
		ans.pop_back();
	if (ans.empty()) ans += "0";
	reverse(ans.begin(), ans.end());
	cout << ans;
}