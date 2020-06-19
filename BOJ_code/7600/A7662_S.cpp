// BOJ 7662 이중 우선순위 큐
// set - bst

#include <iostream>
#include <set>;
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		multiset<int> ms;
		while (n--) {
			char c; int x; cin >> c >> x;
			if (c == 'I') {
				ms.insert(x);
			}
			else {
				if (ms.empty()) continue;
				if (x == 1) ms.erase(--ms.end());
				else ms.erase(ms.begin());
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
	}
}