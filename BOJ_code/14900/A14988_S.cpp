// BOJ 14988 Abandoned Animal
// 

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int c; cin >> c;
	map<string, vector<int>> pdic, mdic;
	for (int i = 0; i < c; ++i) {
		int store; string food; cin >> store >> food;
		pdic[food].push_back(store);
		mdic[food].push_back(-store);
	}

	for (auto& it : pdic) sort(it.second.begin(), it.second.end());
	for (auto& it : mdic) sort(it.second.begin(), it.second.end());

	int t; cin >> t;
	vector<string> buy;
	for (int i = 0; i < t; ++i) {
		string s; cin >> s;
		buy.push_back(s);
	}

	bool flag = true;
	vector<int> fres = { pdic[buy[0]].front() }, bres = { mdic[buy[t - 1]].front() };
	for (int i = 1; i < t; ++i) {
		auto& vec = pdic[buy[i]];
		int id = lower_bound(vec.begin(), vec.end(), fres.back()) - vec.begin();
		if (id == vec.size()) {
			flag = false;
			break;
		}
		fres.push_back(vec[id]);
	}
	for (int i = t - 2; i >= 0; --i) {
		auto& vec = mdic[buy[i]];
		int id = lower_bound(vec.begin(), vec.end(), bres.back()) - vec.begin();
		if (id == vec.size()) {
			flag = false;
			break;
		}
		bres.push_back(vec[id]);
	}
	for (int& x : bres) x = -x;
	reverse(bres.begin(), bres.end());

	if (!flag) {
		cout << "impossible";
		return 0;
	}

	int x = fres[0];
	for (int i = 1; i < fres.size(); ++i) {
		if (x > fres[i]) {
			flag = false;
			break;
		}
		x = fres[i];
	}

	if (!flag) cout << "impossible";
	else if (fres == bres) cout << "unique";
	else cout << "ambiguous";
}