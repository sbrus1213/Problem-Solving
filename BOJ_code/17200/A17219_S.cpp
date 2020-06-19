// BOJ 17219 비밀번호 찾기
// string

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	map<string, string> dic;
	while (n--) {
		string home, pw; cin >> home >> pw;
		dic[home] = pw;
	}

	while (m--) {
		string home; cin >> home;
		cout << dic[home] << '\n';
	}
}