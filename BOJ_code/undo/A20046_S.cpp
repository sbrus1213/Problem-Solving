// BOJ 20046 Road Reconstruction
// Dijkstra

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

const int di[] = { 1, 0, -1, 0 }, dj[] = { 0, 1, 0, -1 };

int r, c;
int road[1001][1001], dist[1001][1001];

bool in_range(int i, int j) {
    if (i < 0 || i >= r) return false;
    if (j < 0 || j >= c) return false;
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            cin >> road[i][j];

    for (int i = 0; i < r; i++)
        fill(dist[i], dist[i] + 1001, inf);

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    if (road[0][0] != -1) dist[0][0] = road[0][0];
    pq.push(pii(dist[0][0], 0));

    while (!pq.empty()) {
        int ci = pq.top().second / c, cj = pq.top().second % c, d = pq.top().first;
        pq.pop();
        if (road[ci][cj] == -1) continue;
        if (d > dist[ci][cj]) continue;
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (!in_range(ni, nj)) continue;
            if (road[ni][nj] == -1) continue;
            int w = road[ni][nj];
            if (d + w < dist[ni][nj]) {
                dist[ni][nj] = d + w;
                pq.push(pii(d + w, ni * c + nj));
            }
        }
    }

    if (dist[r - 1][c - 1] == inf) cout << -1;
    else cout << dist[r - 1][c - 1];

    return 0;
}