#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
	point(int a, int b) :x(a), y(b) {}
	point operator + (const point rhs) {
		return { x + rhs.x, y + rhs.y };
	}
};

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, l, board[101][101] = {}, di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
	char time[10001], direc = 0;
	queue<point> Q;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> l;
	fill(time, time + 10001, '-');
	for (int i = 0; i < l; ++i) {
		int t;
		char d;
		cin >> t >> d;
		time[t] = d;
	}

	int res;
	Q.push({ 1, 1 });
	board[1][1] = 2;

	for (int i = 1; i < 10001; ++i) {
		point prev = Q.back(),
			curr = prev + point(di[direc], dj[direc]);

		res = i;
		if (!(curr.x > 0 && curr.y > 0 && curr.x <= n && curr.y <= n)) break;
		if (board[curr.x][curr.y] == 2) break;
		
		if (board[curr.x][curr.y] != 1) {
			point last = Q.front();
			Q.pop();
			board[last.x][last.y] = 0;
		}
		Q.push(curr);
		board[curr.x][curr.y] = 2;

		if (time[i] == 'D')
			direc = (direc + 1) % 4;
		else if (time[i] == 'L')
			direc = (direc + 3) % 4;
	}

	cout << res;
}