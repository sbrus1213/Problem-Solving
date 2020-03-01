// BOJ 1533 길의 개수
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000003;

struct mat {
	int size;
	vector<vector<ll> > item;
	mat() :size(0) {}
	mat(int n) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		int siz = size / 5, w;
		char ww;
		for (int i = 0; i < siz; ++i)
			for (int j = 0; j < siz; ++j) {
				cin >> ww;
				w = ww - '0';
				if (w) {
					for (int k = 1; k < w; ++k)
						item[i + (k - 1) * siz][i + k * siz] = 1;
					item[i + (w - 1) * siz][j] = 1;
				}
			}
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
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s, e;
	ll t;
	cin >> n >> s >> e >> t;

	mat A(n * 5), res;
	A.init();
	res = A.exp(t);
	cout << res.item[s - 1][e - 1];
}