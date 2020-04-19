// BOJ 17543 Bracket Sequence
// stack

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int cnt = 0;
	stack<ll> st;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (s == "(") {
			st.push(-1);
			cnt++;
		}
		else if (s == ")") {
			ll res = st.top(); st.pop();
			while (st.top() != -1) {
				if (cnt % 2) res = (res * st.top()) % mod;
				else res = (res + st.top()) % mod;
				st.pop();
			}
			st.pop();
			st.push(res);
			cnt--;
		}
		else {
			st.push(stoi(s));
		}
	}
	ll ans = st.top(); st.pop();
	while (!st.empty()) {
		ans = (ans + st.top()) % mod;
		st.pop();
	}
	cout << ans;
}