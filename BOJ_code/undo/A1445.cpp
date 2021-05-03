// BOJ 1445 일요일 아침의 데이트
// priority_queue

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;

const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};

bool in_range(int r, int c, int i, int j) {
    if (i < 0 || i >= r)
        return false;
    if (j < 0 || j >= c)
        return false;
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    char forest[60][60];
    pii S, E;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> forest[i][j];
            if (forest[i][j] == 'S')
                S = pii(i, j);
            if (forest[i][j] == 'F')
                E = pii(i, j);
        }
    }

    bool chk[60][60] = {};
    priority_queue<piii, vector<piii>, greater<piii> > pq;
    pq.push(piii(pii(0, 0), S.first * r + S.second));
    while (!pq.empty()) {
        pii cnt = pq.top().first;
        int thrgh = cnt.first, side = cnt.second;
        int cur = pq.top().second;
        int i = cur / r, j = cur % r;

        if (chk[i][j]) continue;
        chk[i][j] = 1;

        if (E == pii(i, j)) {
            cout << thrgh << ' ' << side;
            return 0;
        }

        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (!in_range(r, c, ni, nj)) continue;
            if (chk[ni][nj]) continue;
            if (E == pii(ni, nj)) {
                pq.push(piii(pii(thrgh, side), ni * r + nj));
            }
            else {
                bool gar = false;
                for (int l = 0; l < 4; ++l) {
                    int nni = ni + di[l], nnj = nj + dj[l];
                    if (!in_range(r, c, nni, nnj)) continue;
                    gar |= (forest[nni][nnj] == 'g');
                }
                if (forest[ni][nj] == 'g')
                    pq.push(piii(pii(thrgh + 1, side + gar), ni * r + nj));
                else
                    pq.push(piii(pii(thrgh, side + gar), ni * r + nj));
            }
        }
    }

    return 0;
}