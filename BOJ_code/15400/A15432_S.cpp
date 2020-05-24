// BOJ 15432 Suspension Bridges
// Binary search & 수학

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double cosh(double x) {
	return (exp(x) + exp(-x)) / 2;
}
double sinh(double x) {
	return (exp(x) - exp(-x)) / 2;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	double d, s; cin >> d >> s;
	double l = 0, r = 1e8, ep = 1e-10;
	while (r - l > ep) {
		double mid = (l + r) / 2;
		double res = mid + s - mid * cosh(d / 2.0 / mid);
		if (res > 0) r = mid;
		else l = mid;
	}
	cout << fixed;
	cout.precision(6);
	cout << 2 * l * sinh(d / 2.0 / l);
}