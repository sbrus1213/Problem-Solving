// BOJ 7568 µ¢Ä¡
// ±¸Çö

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct Man {
	int w, h, i;
};
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<Man> man(n);
	vector<int> rank(n);
	for (int i = 0; i < n; ++i) {
		cin >> man[i].w >> man[i].h;
		man[i].i = i;
	}
	sort(man.begin(), man.end(), [&](Man a, Man b) {
		if (a.w != b.w) return a.w > b.w;
		if (a.h != b.h) return a.h > b.h;
		return a.i < b.i;
		});

	for (int i = 0; i < n; ++i) {
		int c = 1;
		for (int j = i - 1; j >= 0; --j)
			if (man[j].w > man[i].w&& man[j].h > man[i].h) c++;
		rank[man[i].i] = c;
	}

	for (int r : rank) cout << r << ' ';
}