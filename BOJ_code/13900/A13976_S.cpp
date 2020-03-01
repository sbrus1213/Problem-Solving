// BOJ 13976 타일 채우기 2
// exponentiation by squaring

#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

struct mat {
	ll item[2][2];
	mat() {
		for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) item[i][j] = 0;
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
	mat tile, x, res;

	cin >> n;

	if (n % 2) cout << 0;
	else {
		tile.item[0][0] = 11, tile.item[0][1] = tile.item[1][0] = 3, tile.item[1][1] = 1;
		x.item[0][0] = 4, x.item[0][1] = 1, x.item[1][0] = -1, x.item[1][1] = 0;

		res = tile * x.exp(n / 2);
		cout << (res.item[1][1] + mod) % mod;
	}
}