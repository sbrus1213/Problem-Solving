// BOJ 14289 본대 산책3
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1'000'000'007;

struct mat {
	int size;
	vector<vector<ll> > item;
	mat(int n = 0) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		int m, x, y;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			item[x - 1][y - 1] = item[y - 1][x - 1] = 1;
		}
	}
	mat identity() {
		mat res(size);
		for (int i = 0; i < size; ++i) res.item[i][i] = 1;
		return res;
	}
	mat operator * (const mat rhs) {
		mat temp(size);
		for (int k = 0; k < size; ++k)
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j) {
					temp.item[i][j] += item[i][k] * rhs.item[k][j];
					temp.item[i][j] %= mod;
				}
		return temp;
	}
	mat exp(int times) {
		mat res, tmp;

		res = mat(size).identity();
		tmp = *this;

		while (times) {
			if (times % 2)
				res = res * tmp;
			times /= 2;
			tmp = tmp * tmp;
		}
		return res;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d;
	cin >> n;

	mat matrix(n), res;
	matrix.init();

	cin >> d;
	res = matrix.exp(d);
	cout << res.item[0][0];
}