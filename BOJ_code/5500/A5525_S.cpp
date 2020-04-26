// BOJ 5525 IOIOI
// string

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	string s; cin >> s;

	int idx = 0, cnt = 0, tmp = -1;
	while (idx < m) {
		while (tmp == -1 && idx < m) {
			if (s[idx++] == 'I') {
				tmp = 0;
				break;
			}
		}
		if (idx + 1 >= m) break;
		if (s[idx] == 'I') {
			idx++;
			tmp = 0;
		}
		else if (s[idx] == 'O' && s[idx + 1] == 'I') {
			tmp += 1;
			idx += 2;
			if (tmp == n) {
				tmp--;
				cnt++;
			}
		}
		else if (s[idx] == 'O' && s[idx + 1] == 'O') {
			idx += 1;
			tmp = -1;
		}
	}
	cout << cnt;
}