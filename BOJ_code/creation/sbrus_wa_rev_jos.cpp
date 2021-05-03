#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K, M;
	cin >> N >> K >> M;

	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

    int flag = 0;
	for (int i = 1, del = 0, ori = 1; del < N; i++) {
		int tmp;

		if (ori) {
			tmp = dq.front();
			dq.pop_front();
		}
		else {
			tmp = dq.back();
			dq.pop_back();
		}

		if (i % K) {
			if (ori) dq.push_back(tmp);
			else dq.push_front(tmp);
		}
		else {
			cout << tmp << '\n';
			del++;
		}

		if (!(del % M) && !(i % K) && flag == 0) {
			ori = 1 - ori;
            flag = 1;
        }
	}

	return 0;
}