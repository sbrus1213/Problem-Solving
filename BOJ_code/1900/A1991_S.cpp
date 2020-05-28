// BOJ 1991 트리 순회
// tree traversal

#include <iostream>
using namespace std;

int child[26][2];

void preorder(int cur) {
	cout << (char)(cur + 'A');
	if (child[cur][0] != -1) preorder(child[cur][0]);
	if (child[cur][1] != -1) preorder(child[cur][1]);
}
void inorder(int cur) {
	if (child[cur][0] != -1) inorder(child[cur][0]);
	cout << (char)(cur + 'A');
	if (child[cur][1] != -1) inorder(child[cur][1]);
}
void postorder(int cur) {
	if (child[cur][0] != -1) postorder(child[cur][0]);
	if (child[cur][1] != -1) postorder(child[cur][1]);
	cout << (char)(cur + 'A');
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 0; i < 26; ++i) child[i][0] = child[i][1] = -1;

	for (int i = 0; i < n; ++i) {
		char c, ch1, ch2; cin >> c >> ch1 >> ch2;
		if (ch1 != '.') child[c - 'A'][0] = ch1 - 'A';
		if (ch2 != '.') child[c - 'A'][1] = ch2 - 'A';
	}

	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';
}