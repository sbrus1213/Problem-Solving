// BOJ 14754 Pizza Boxes
// ±¸Çö

#include <iostream>
using namespace std;
#define ll long long

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, m, box[1000][1000], sum = 0;
	bool check[1000][1000] = {};

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> box[i][j];
			sum += box[i][j];
		}
	}

	ll mm, id;
	for (int i = 0; i < n; ++i) {
		mm = -1;
		for (int j = 0; j < m; ++j) {
			if (box[i][j] > mm) {
				mm = box[i][j];
				id = j;
			}
		}
		check[i][id] = 1;
	}
	for (int j = 0; j < m; ++j) {
		mm = -1;
		for (int i = 0; i < n; ++i) {
			if (box[i][j] > mm) {
				mm = box[i][j];
				id = i;
			}
		}
		check[id][j] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (check[i][j])
				sum -= box[i][j];
		}
	}

	cout << sum;
}