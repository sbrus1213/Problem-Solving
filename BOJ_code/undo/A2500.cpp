// BOJ 2500 บนบาบน
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 42043;

struct mat {
	int size;
	vector<vector<ll> > item;
	mat(int n = 0) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init(int t) {
		for (int i = 0; i < t; ++i) {
			int x;
			cin >> x;
			for (int i = 0; i < size - 1; ++i) {
				if (i + x < size) {
					item[i][i + x]++;
				}
			}
		}
		item[size - 1][size - 1] = t;
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
	mat exp(ll times) {
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

vector<ll> M;
void init(int t) {
	for (int i = 0; i < t; ++i) {
		int x;
		cin >> x;
		M[x]++;
	}
}


int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, t;
	cin >> n >> k >> t;

	mat M(k + 2), res;
	M.init(t);

	res = M.exp(n);

	ll ans = 0;
	for (int i = 0; i <= k; ++i) ans += res.item[0][i];

	cout << ans;
}