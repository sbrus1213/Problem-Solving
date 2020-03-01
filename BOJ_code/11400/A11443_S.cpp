// BOJ 11443 홀수번째 피보나치 수의 합
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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n;
	cin >> n;
	mat fibo, res;

	fibo.item[0][0] = fibo.item[0][1] = fibo.item[1][0] = 1;
	if (n % 2) res = fibo.exp(n);
	else res = fibo.exp(n + 1);
	cout << res.item[0][1] - 1 << '\n';
}