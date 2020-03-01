// BOJ 11440 피보나치 수의 제곱의 합
// Matrix exponentiation

#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

struct mat {
	ll item[2][2];
	mat() {
		item[0][0] = item[0][1] = item[1][0] = item[1][1] = 0;
	}
	mat operator * (const mat rhs) {
		mat temp;
		for (int k = 0; k < 2; k++)
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					temp.item[i][j] = (temp.item[i][j] + item[i][k] * rhs.item[k][j]) % mod;
		return temp;
	}
	mat exp(ll times) {
		mat res, tmp;

		for (int i = 0; i < 2; i++) {
			res.item[i][i] = 1;
			for (int j = 0; j < 2; j++)
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

int exp_2(int x) {
	ll a = 2, res = 1;

	while (x) {
		if (x % 2)
			res = (res * a) % mod;
		x >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, f2n, fn_2, ans;
	cin >> n;
	mat fibo, res;

	fibo.item[0][0] = fibo.item[0][1] = fibo.item[1][0] = 1;

	//	res = fibo.exp(n);
	//	cout << (res.item[0][0] * res.item[0][1]) % mod;

	f2n = fibo.exp(2 * n).item[0][1];
	fn_2 = fibo.exp(n).item[0][1];
	fn_2 = (fn_2 * fn_2) % mod;

	ans = (f2n + fn_2) % mod;
	ans = (ans * exp_2(mod - 2)) % mod;
	cout << ans;
}