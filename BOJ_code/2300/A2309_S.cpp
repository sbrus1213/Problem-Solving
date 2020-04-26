// BOJ 2309 ¿œ∞ˆ ≥≠¿Ô¿Ã
// Brute force

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tall[9], sum = 0;
	for (int i = 0; i < 9; ++i) {
		cin >> tall[i];
		sum += tall[i];
	}

	for (int i = 0; i < 9; ++i)
		for (int j = i + 1; j < 9; ++j)
			if (sum - tall[i] - tall[j] == 100) {
				tall[i] = tall[j] = -1;
				sort(tall, tall + 9);
				for (int k = 2; k < 9; ++k)
					cout << tall[k] << '\n';
				return 0;
			}
}