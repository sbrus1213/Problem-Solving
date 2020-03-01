// BOJ 14647 병아리의 변신은 무죄
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 100'000'007;

struct mat {
	int size;
	vector<vector<ll> > item;
	mat(int n = 0) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		if (size == 1) item[0][0] = 2;
		else {
			item[0][0] = item[0][size - 1] = 1;
			for (int i = 1; i < size; ++i) item[i][i - 1] = 1;
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

	int tc;
	cin >> tc;
	while (tc--) {
		int k, n, ans = 0;
		cin >> k >> n;

		mat M(k + 1), res;
		M.init();

		if (n <= k) cout << 1 << '\n';
		else {
			res = M.exp(n - k);
			for (int i = 0; i <= k; ++i)
				ans = (ans + res.item[0][i]) % mod;
			cout << ans << '\n';
		}
	}
}