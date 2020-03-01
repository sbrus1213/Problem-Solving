// BOJ 13328 Message passing
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
const int mod = 31991;

struct mat {
	int size;
	vector<vector<int> > item;
	mat() :size(0) {}
	mat(int n) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		for (int i = 0; i < size; ++i) item[i][0] = 1;
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

	int d, t;

	cin >> d >> t;

	vector<int> call(d + 1);

	call[0] = call[1] = 1;
	for (int i = 2; i <= d; ++i) call[i] = (call[i - 1] * 2) % mod;

	if (t <= d) cout << call[t];
	else {
		int ans = 0;
		mat x(d), res;

		x.init();
		res = x.exp(t - d);

		for (int i = 0; i < d; ++i)
			ans = (ans + call[d - i] * res.item[i][0]) % mod;
		cout << ans;
	}
}