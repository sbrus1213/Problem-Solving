// BOJ 5430 AC
// deque

#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		string s, num; int n; cin >> s >> n >> num;

		int idx = 1;
		deque<int> dq;
		while (dq.size() < n) {
			int t = 0;
			while (num[idx] >= '0' && num[idx] <= '9') {
				t = t * 10 + num[idx++] - '0';
			}
			dq.push_back(t);
			if (num[idx] == ']') break;
			idx++;
		}

		bool rev = false, flg = true;
		for (char c : s) {
			if (c == 'R') rev = !rev;
			else {
				if (dq.empty()) {
					flg = false;
					break;
				}
				if (rev) dq.pop_back();
				else dq.pop_front();
			}
		}

		if (!flg) cout << "error\n";
		else if (rev) {
			cout << '[';
			while (!dq.empty()) {
				if (dq.size() > 1) cout << dq.back() << ',';
				else cout << dq.back();
				dq.pop_back();
			}
			cout << "]\n";
		}
		else {
			cout << '[';
			while (!dq.empty()) {
				if (dq.size() > 1) cout << dq.front() << ',';
				else cout << dq.front();
				dq.pop_front();
			}
			cout << "]\n";
		}
	}
}