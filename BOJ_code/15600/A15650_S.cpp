// BOJ 15650 N°ú M(2)
// Brute force & back tracking

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> st;
void n_m(int curr, int depth) {
	if (depth == m) {
		for (int item : st) cout << item << ' ';
		cout << '\n';
		return;
	}

	for (int i = curr; i <= n; ++i) {
		st.push_back(i);
		n_m(i + 1, depth + 1);
		st.pop_back();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	n_m(1, 0);
}