// BOJ 17300 ∆–≈œ
// Back Tracking

#include <iostream>
#include <vector>
using namespace std;

int l;
vector<int> pat;
vector<int> 

bool check(int idx) {

}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> l;

	pat = vector<int>(l);
	for (int &pi : pat) cin >> pi;

	if (check(0)) cout << "YES";
	else cout << "NO";

	return 0;
}