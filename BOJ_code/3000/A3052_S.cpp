// BOJ 3052 나머지
// 구현

#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x;
	map<int, bool> dic;
	for (int i = 0; i < 10; i++) cin >> x, dic[x % 42] = true;
	cout << dic.size();
}