// BOJ 13430 합 구하기
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define BtoE(vec) vec.begin(), vec.end()
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
		for (int i = 0; i < size; ++i)
			for (int j = 0; j <= i; ++j)
				item[i][j] = 1;
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
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n;

	cin >> k >> n;

	mat matrix(k + 2), res;
	vector<ll> column(k + 2);
	ll ans = 0;

	fill(BtoE(column), 1);
	matrix.init();
	res = matrix.exp(n - 1);

	for (int i = 0; i <= k + 1; ++i) ans = (ans + column[i] * res.item[k + 1][i]) % mod;
	cout << ans;
}