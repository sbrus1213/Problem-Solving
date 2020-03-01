// BOJ 16572 Pixel Triangles

#include <iostream>
#include <algorithm>
using namespace std;

int n, pixel[2001][2001], res;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		pixel[a][b] = max(pixel[a][b], c);
	}

	for (int i = 1; i <= 2000; ++i) {
		for (int j = 1; j <= 2000; ++j) {
			if (pixel[i][j] > 1) {
				if (i + 1 <= 2000) pixel[i + 1][j] = max(pixel[i + 1][j], pixel[i][j] - 1);
				if (j + 1 <= 2000) pixel[i][j + 1] = max(pixel[i][j + 1], pixel[i][j] - 1);
			}
			if (pixel[i][j]) res++;
		}
	}

	cout << res;
}