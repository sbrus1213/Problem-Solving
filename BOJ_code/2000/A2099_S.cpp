// BOJ 2099 The game of death
// exponentiation by squaring

#include <iostream>
#include <vector>
using namespace std;

struct mat {
	int size;
	vector<vector<bool> > item;
	mat() :size(0) {}
	mat(int n) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	void init() {
		for (int i = 0; i < size; ++i) {
			int a, b;
			cin >> a >> b;
			item[i][a - 1] = item[i][b - 1] = true;
		}
	}
	mat operator * (const mat rhs) {
		mat temp(size);
		for (int k = 0; k < size; ++k)
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					temp.item[i][j] = (temp.item[i][j] | (item[i][k] & rhs.item[k][j]));
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
	void proc(int times) {
		for (int i = 0; i < times; ++i) {
			int a, b;
			cin >> a >> b;
			if (item[a - 1][b - 1]) cout << "death\n";
			else cout << "life\n";
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, m;
	cin >> n >> k >> m;

	mat matrix(n), res;
	matrix.init();
	res = matrix.exp(k);
	res.proc(m);
}