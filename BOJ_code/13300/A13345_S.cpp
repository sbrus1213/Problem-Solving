// BOJ 13345 Completing the Square
// ¼öÇÐ

#include <iostream>
using namespace std;
using pii = pair<int, int>;

int dist(pii p1, pii p2) {
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	pii p1, p2, p3, p;
	cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;

	if (dist(p1, p2) == dist(p1, p3)) swap(p1, p3);
	else if (dist(p1, p2) == dist(p2, p3)) swap(p2, p3);

	p.first = (p1.first + p2.first);
	p.second = (p1.second + p2.second);

	cout << p.first - p3.first << ' ' << p.second - p3.second;
}