// BOJ 18120 ¥Î≥Û∫Œ ±ËªÛ«ı
// Prefix sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define pdd pair<double, double>
#define BtoE(vec) vec.begin(), vec.end()

double w_pxsum[100001], d_w_pxsum[100001];
vector<pdd > nongjak;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a;

	cin >> n >> a;
	nongjak.resize(n);

	for (int i = 0; i < n; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		nongjak[i] = pdd(sqrt((x * x) + (y * y)), w);
	}
	sort(BtoE(nongjak));

	w_pxsum[0] = nongjak[0].second;
	d_w_pxsum[0] = nongjak[0].first * nongjak[0].second;
	for (int i = 1; i < n; ++i) {
		w_pxsum[i] = w_pxsum[i - 1] + nongjak[i].second;
		d_w_pxsum[i] = d_w_pxsum[i - 1] + nongjak[i].first * nongjak[i].second;
	}

	double res = 0, tmp;
	for (int i = 0; i < n - 1; ++i) {
		if (nongjak[i + 1].first < w_pxsum[i] / (2 * a)) {
			tmp = -a * nongjak[i + 1].first * nongjak[i + 1].first + nongjak[i + 1].first * w_pxsum[i] - d_w_pxsum[i];
			res = max(res, tmp);
		}
		if (nongjak[i].first < w_pxsum[i] / (2 * a)) {
			tmp = (w_pxsum[i] * w_pxsum[i] / (4 * a)) - d_w_pxsum[i];
			res = max(res, tmp);
		}
		else {
			continue;
		}
	}
	if (nongjak[n - 1].first < w_pxsum[n - 1] / (2 * a))
		tmp = (w_pxsum[n - 1] * w_pxsum[n - 1]) / (4 * a) - (d_w_pxsum[n - 1]);
	res = max(res, tmp);

	cout << fixed;
	cout.precision(9);
	cout << res;
}
