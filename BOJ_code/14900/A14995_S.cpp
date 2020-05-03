// BOJ 14995 Horror Film Night
// Greedy

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
const int mxn = 1000001;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int a; cin >> a;
	bitset<mxn> A;
	for (int i = 0; i < a; ++i) {
		int aa; cin >> aa;
		A[aa] = 1;
	}

	int b; cin >> b;
	bitset<mxn> B;
	for (int i = 0; i < b; ++i) {
		int bb; cin >> bb;
		B[bb] = 1;
	}

	int ans = 0, turn = -1;
	for (int i = 0; i < mxn; ++i) {
		if (turn == -1 && (A[i] ^ B[i])) {
			turn = (A[i] == 0);
		}
		if (A[i] && B[i]) {
			ans++;
			turn = -1;
		}
		else if (A[i] || B[i]) {
			if ((!turn && A[i]) || (turn && B[i])) {
				ans++;
				turn = 1 - turn;
			}
		}
	}
	cout << ans;
}