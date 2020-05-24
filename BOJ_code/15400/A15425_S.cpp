// BOJ 15425 Company Picnic
// Tree dp

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<double> met, tmpr, dpr[2];
vector<int> tmpc, dpc[2];
vector<vector<int>> adj;

void go(int cur) {
	for (int nxt : adj[cur]) go(nxt);

	int totc = 0;
	double totr = 0;
	for (int nxt : adj[cur]) {
		if (dpc[0][nxt] > dpc[1][nxt] || (dpc[0][nxt] == dpc[1][nxt] && dpr[0][nxt] > dpr[1][nxt])) {
			totc += dpc[0][nxt];
			totr += dpc[0][nxt] * dpr[0][nxt];
			tmpc[nxt] = dpc[0][nxt];
			tmpr[nxt] = dpr[0][nxt];
		}
		else {
			totc += dpc[1][nxt];
			totr += dpc[1][nxt] * dpr[1][nxt];
			tmpc[nxt] = dpc[1][nxt];
			tmpr[nxt] = dpr[1][nxt];
		}
	}

	dpc[0][cur] = totc;
	if (!totc) dpr[0][cur] = 0;
	else dpr[0][cur] = totr / totc;

	int mxc = 0;
	double mxr = 0;
	for (int nxt : adj[cur]) {
		int c = dpc[0][nxt];
		double r = dpr[0][nxt];

		int cc = totc - tmpc[nxt] + c + 1;
		double rr = totr - tmpr[nxt] * tmpc[nxt] + r * c + min(met[cur], met[nxt]);

		if (mxc > cc) continue;
		else if (mxc < cc) {
			mxc = cc;
			mxr = rr / cc;
		}
		else if (mxr < (rr / cc))
			mxr = rr / cc;
	}
	dpc[1][cur] = mxc; dpr[1][cur] = mxr;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	met = vector<double>(n + 1);
	adj = vector<vector<int>>(n + 1);
	map<string, int> idx;
	int cnt = 0, st;
	for (int i = 0; i < n; ++i) {
		string man, par; double val; cin >> man >> val >> par;
		if (!idx[man]) idx[man] = ++cnt;
		met[idx[man]] = val;
		if (par != "CEO") {
			if (!idx[par]) idx[par] = ++cnt;
			adj[idx[par]].push_back(idx[man]);
		}
		else st = idx[man];
	}

	dpc[0] = vector<int>(n + 1);
	dpc[1] = vector<int>(n + 1);
	dpr[0] = vector<double>(n + 1);
	dpr[1] = vector<double>(n + 1);
	tmpc = vector<int>(n + 1);
	tmpr = vector<double>(n + 1);

	go(st);
	cout << fixed;
	cout.precision(5);
	if (dpc[0][st] > dpc[1][st] || (dpc[0][st] == dpc[1][st] && dpr[0][st] > dpr[1][st])) {
		cout << dpc[0][st];
		cout << ' ' << dpr[0][st];
	}
	else {
		cout << dpc[1][st];
		cout << ' ' << dpr[1][st];
	}
}