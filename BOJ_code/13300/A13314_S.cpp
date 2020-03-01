// BOJ 13314 수강신청

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> k >> n;

	map<string, int> dic;
	vector<string> v;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (!v.empty() && v.back() == s) continue;
		v.push_back(s);
		dic[s]++;
	}

	for (int i = 0, j = 0; j < k && i < v.size(); ++i) {
		if (dic[v[i]] > 1) dic[v[i]]--;
		else {
			cout << v[i] << '\n';
			++j;
		}
	}
}