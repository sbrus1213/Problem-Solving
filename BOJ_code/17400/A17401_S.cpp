// BOJ 17401 일하는 세포
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000000007;

struct mat {
	int size;
	vector<vector<ll> > item;
	mat() :size(0) {}
	mat(int n) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		int m, s, e, w;
		cin >> m;
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				item[i][j] = 0;
		for (int i = 0; i < m; ++i) {
			cin >> s >> e >> w;
			item[s - 1][e - 1] = w;
		}
	}
	mat operator * (const mat rhs) {
		mat temp(size);
		for (int k = 0; k < size; ++k)
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					temp.item[i][j] = (temp.item[i][j] + item[i][k] * rhs.item[k][j]) % mod;
		return temp;
	}
	mat exp(int times) {
		mat res(size), tmp(size);

		for (int i = 0; i < size; i++) {
			res.item[i][i] = 1;
			for (int j = 0; j < size; j++)
				tmp.item[i][j] = item[i][j];
		}

		while (times) {
			if (times % 2)
				res = res * tmp;
			times /= 2;
			tmp = tmp * tmp;
		}
		return res;
	}
	void print() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j)
				cout << item[i][j] << ' ';
			cout << '\n';
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, d;
	cin >> t >> n >> d;

	mat all(n), rem(n), temp(n), res;

	for (int i = 0; i < n; ++i) all.item[i][i] = rem.item[i][i] = 1;

	for (int i = 0; i < t; ++i) {
		temp.init();
		all = all * temp;
		if (i < d % t) rem = rem * temp;
	}

	res = all.exp(d / t);
	res = res * rem;
	res.print();
}