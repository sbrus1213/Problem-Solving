// BOJ 1181 단어정렬
// sort

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
	if (s1.size() < s2.size()) return true;
	if (s1.size() > s2.size()) return false;
	return s1 < s2;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string tmp;
	vector<string>vec;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), compare);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (auto s : vec) cout << s << '\n';
}