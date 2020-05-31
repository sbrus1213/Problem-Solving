// BOJ 1672 DNA 해독
// stack

#include <iostream>
#include <stack>
using namespace std;

char dec(char a, char b) {
	if (a == 'A') {
		if (b == 'A' || b == 'C') return 'A';
		if (b == 'G') return 'C';
		if (b == 'T') return 'G';
	}
	else if (a == 'G') {
		if (b == 'A') return 'C';
		if (b == 'G') return b;
		if (b == 'C') return 'T';
		if (b == 'T') return 'A';
	}
	else if (a == 'C') {
		if (b == 'G') return 'T';
		if (b == 'T') return 'G';
		return b;
	}
	else if (a == 'T') {
		if (b == 'A') return 'G';
		if (b == 'G') return 'A';
		if (b == 'C') return 'G';
		return b;
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	stack<char> st;
	while (n--) {
		char x; cin >> x;
		st.push(x);
	}

	while (st.size() > 1) {
		char b = st.top(); st.pop();
		char a = st.top(); st.pop();
		st.push(dec(a, b));
	}
	cout << st.top();
}