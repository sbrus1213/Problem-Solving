// BOJ 13291
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; cin >> s;
	
	if (s.size() % 2) {
		cout << "impossible";
		return 0;
	}

	vector<int> px(s.size());
	int sum = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') px[i] = ++sum;
		else px[i] = --sum;
	}


	if (sum == 0) {
		if (s.front() != s.back()) {
			cout << "possible";
			return 0;
	}
}