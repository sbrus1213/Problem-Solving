// BOJ 12850 본대 산책2
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1'000'000'007;

struct mat {
	ll item[8][8];
	mat() {
		for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) item[i][j] = 0;
	}
	void init() {
		for (int i = 0; i < 4; i++)
			item[i][i + 1] = item[i + 1][i] = item[i][i + 2] = item[i + 2][i] = item[i + 1][i + 2] = item[i + 2][i + 1] = 1;
		item[5][6] = item[6][5] = item[4][7] = item[7][4] = item[6][7] = item[7][6] = 1;
	}
	mat operator * (const mat rhs) {
		mat temp;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j) {
				temp.item[i][j] = 0;
				for (int k = 0; k < 8; ++k)
					temp.item[i][j] = (temp.item[i][j] + item[i][k] * rhs.item[k][j]) % mod;
			}
		return temp;
	}
	mat exp(int times) {
		mat res, tmp;

		for (int i = 0; i < 8; i++) {
			res.item[i][i] = 1;
			for (int j = 0; j < 8; j++)
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

	int d;
	cin >> d;

	mat matrix, res;
	matrix.init();
	res = matrix.exp(d);
	cout << res.item[0][0];
}