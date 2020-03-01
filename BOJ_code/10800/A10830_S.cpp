// BOJ 10830 Çà·Ä Á¦°ö
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000;

struct mat {
	int size;
	vector<vector<int> > item;
	mat() {}
	mat(int n) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				cin >> item[i][j];
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

	int n;
	ll b;
	cin >> n >> b;

	mat A(n), res;
	A.init();
	res = A.exp(b);
	res.print();
}