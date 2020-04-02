// BOJ 3827 일차원 세포 자동차
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;

int mod;
struct mat {
	int size;
	vector<vector<int> > item;
	mat(int n = 0) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init(int a, int b, int c) {
		for (int i = 1; i < size - 1; ++i) {
			item[i][i - 1] = a;
			item[i][i] = b;
			item[i][i + 1] = c;
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

	int n, a, b, c, t;
	while (cin >> n >> mod >> a >> b >> c >> t) {
		if (!n && !mod && !a && !b && !c && !t) break;

		mat M(n + 2);
		M.init(a, b, c);

		vector<int> S(n + 2);
		for (int i = 1; i <= n; ++i) cin >> S[i];

		mat res = M.exp(t);
		for (int i = 1; i <= n; ++i) {
			int ans = 0;
			for (int j = 0; j <= n + 1; ++j)
				ans = (ans + res.item[i][j] * S[j]) % mod;
			cout << ans << ' ';
		}
		cout << '\n';
	}
}