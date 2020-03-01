// BOJ 17272 리그 오브 레전설(large)
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000000007;

struct mat {
	int size;
	vector<vector<ll> > item;
	mat() {}
	mat(int n) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		item[0][0] = item[size - 1][0] = 1;
		for (int i = 0; i < size - 1; ++i) item[i][i + 1] = 1;
	}
	mat operator * (const mat rhs) {
		mat temp(size);
		for (int k = 0; k < size; ++k)
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					temp.item[i][j] = (temp.item[i][j] + item[i][k] * rhs.item[k][j]) % mod;
		return temp;
	}
	mat exp(ll times) {
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

	ll n;
	int m;
	cin >> n >> m;

	mat matrix(m), res;
	matrix.init();
	res = matrix.exp(n);
	cout << res.item[0][0];
}