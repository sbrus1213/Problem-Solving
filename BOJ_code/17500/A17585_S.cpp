// BOJ 17585 Circuit Math
// stack

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> tf(26);
	for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		if (c == 'T') tf[i] = 1;
		else tf[i] = 0;
	}

	char c;
	vector<int> st;
	while (cin >> c) {
		if (c >= 'A' && c <= 'Z') {
			st.push_back(tf[c - 'A']);
		}
		else {
			int op2 = st.back(); st.pop_back();
			int op1 = st.back(); st.pop_back();

			if (c == '*') st.push_back(op1 & op2);
			else if (c == '+') st.push_back(op1 | op2);
			else {
				st.push_back(op1);
				st.push_back(!op2);
			}
		}
	}
	if (st[0]) cout << "T";
	else cout << "F";
}