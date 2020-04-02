// BOJ 10814 나이순 정렬
// sort

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct man {
	int id, age;
	string name;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<man> V(n);
	for (int i = 0; i < n; ++i) {
		cin >> V[i].age >> V[i].name;
		V[i].id = i;
	}

	sort(V.begin(), V.end(), [&](man a, man b) {
		if (a.age == b.age) return a.id < b.id;
		return a.age < b.age;
		});
	for (int i = 0; i < n; ++i) cout << V[i].age << ' ' << V[i].name << '\n';
}