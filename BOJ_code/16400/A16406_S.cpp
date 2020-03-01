// BOJ 16406 Exam

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int len, k, same = 0;
	string s1, s2;

	cin >> k;
	cin >> s1 >> s2;
	len = s1.size();

	for (int i = 0; i < len; ++i)
		if (s1[i] == s2[i]) ++same;

	if (same == k) cout << len;
	else if (same < k) cout << (len - k + same);
	else cout << (len - same + k);
}