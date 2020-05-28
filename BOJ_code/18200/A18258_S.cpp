// BOJ 18258 큐 2
// queue

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	queue<int> q;
	while (n--) {
		string c; cin >> c;
		if (c == "push") {
			int x; cin >> x;
			q.push(x);
		}
		else if (c == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (c == "size") cout << q.size() << '\n';
		else if (c == "empty") cout << q.empty() << '\n';
		else if (c == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (c == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
	}
}