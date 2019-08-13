// BOJ 16425 Random Index Vertex

#include <iostream>
#include <vector>
using namespace std;
#define ll	long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k;
	vector<ll> mat1, mat2, matplus, matmul;
	int siz1, siz2;

	cin >> n >> k;

	cin >> siz1;
	mat1.resize(siz1);
	for (int i = 0; i < siz1; ++i)cin >> mat1[i];

	cin >> siz2;
	mat2.resize(siz2);
	for (int i = 0; i < siz2; ++i)cin >> mat2[i];

	int id1 = 0, id2 = 0;
	while (id1 < siz1 && id2 < siz2) {
		ll t1 = mat1[id1], t2 = mat2[id2];

		if (abs(t1) == abs(t2)) {
			if (t1 == t2) {
				matplus.push_back(t1);
				matmul.push_back(abs(t1));
			}
			else
				matmul.push_back(-abs(t1));
			++id1; ++id2;
		}
		else {
			if (abs(t1) < abs(t2)) {
				matplus.push_back(t1);
				++id1;
			}
			else {
				matplus.push_back(t2);
				++id2;
			}
		}
	}
	while (id1 < siz1) {
		matplus.push_back(mat1[id1]);
		++id1;
	}
	while (id2 < siz2) {
		matplus.push_back(mat2[id2]);
		++id2;
	}

	ll min1 = 1e18 + 7, min_id1 = 0;
	for (int i = 0; i < siz1; ++i) {
		if (mat1[i] > 0) {
			mat1[i] -= k;
			if (mat1[i] <= 0) mat1[i] += n;
		}
		else {
			mat1[i] *= -1;
			mat1[i] -= k;
			if (mat1[i] <= 0) mat1[i] += n;
			mat1[i] *= -1;
		}

		if (min1 > abs(mat1[i])) {
			min1 = abs(mat1[i]);
			min_id1 = i;
		}
	}

	ll min2 = 1e18 + 7, min_id2 = 0;
	for (int i = 0; i < siz2; ++i) {
		if (mat2[i] > 0) {
			mat2[i] -= k;
			if (mat2[i] <= 0) mat2[i] += n;
		}
		else {
			mat2[i] *= -1;
			mat2[i] -= k;
			if (mat2[i] <= 0) mat2[i] += n;
			mat2[i] *= -1;
		}

		if (min2 > abs(mat2[i])) {
			min2 = abs(mat2[i]);
			min_id2 = i;
		}
	}

	int plus_siz = matplus.size(), mul_siz = matmul.size();

	cout << plus_siz << ' ';
	for (int i = 0; i < plus_siz; ++i)
		cout << matplus[i] << ' ';
	cout << '\n';

	cout << mul_siz << ' ';
	for (int i = 0; i < mul_siz; ++i)
		cout << matmul[i] << ' ';
	cout << '\n';

	cout << siz1 << ' ';
	for (int i = min_id1; i < siz1; ++i)
		cout << mat1[i] << ' ';
	for (int i = 0; i < min_id1; ++i)
		cout << mat1[i] << ' ';
	cout << '\n';

	cout << siz2 << ' ';
	for (int i = min_id2; i < siz2; ++i)
		cout << mat2[i] << ' ';
	for (int i = 0; i < min_id2; ++i)
		cout << mat2[i] << ' ';
}