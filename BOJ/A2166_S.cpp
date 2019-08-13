// BOJ 2166 다각형의 면적
// CCW

#include <iostream>
using namespace std;
#define ll	long long

struct node {
	ll x, y;
};

double ccw(node vec1, node vec2) {
	ll res = (vec1.x * vec2.y) - (vec2.x * vec1.y);

	return (double)res / 2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	double res = 0;
	node point[10001];

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> point[i].x >> point[i].y;

	for (int i = 2; i < n; ++i) {
		node vec1 = { point[i - 1].x - point[0].x , point[i - 1].y - point[0].y },
			vec2 = { point[i].x - point[0].x , point[i].y - point[0].y };

		res += ccw(vec1, vec2);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(res);
}