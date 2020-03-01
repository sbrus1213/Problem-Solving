// BOJ Battle Royale
// Number

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ld long double
#define PI 3.14159265

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int si, sj, ei, ej;
	cin >> si >> sj >> ei >> ej;

	int dist_ = (si - ei) * (si - ei) + (sj - ej) * (sj - ej);

	int bi, bj, br, ri, rj, rr;
	cin >> bi >> bj >> br >> ri >> rj >> rr;

	int d1_ = (si - ri) * (si - ri) + (sj - rj) * (sj - rj);
	int d2_ = (ei - ri) * (ei - ri) + (ej - rj) * (ej - rj);

	int l1_ = d1_ - rr * rr;
	int l2_ = d2_ - rr * rr;

	ld whole = acosl((d1_ + d2_ - dist_) / (2 * sqrtl((ld)d1_) * sqrtl((ld)d2_)));
	ld ta1 = acosl((ld)rr / sqrtl((ld)d1_));
	ld ta2 = acosl((ld)rr / sqrtl((ld)d2_));

	cout << fixed;
	cout.precision(10);
	cout << (ld)((ld)rr * (whole - ta1 - ta2) + sqrtl(l1_) + sqrtl(l2_));
}