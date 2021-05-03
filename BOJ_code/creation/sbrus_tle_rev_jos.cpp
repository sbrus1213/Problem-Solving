#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K, M;
	cin >> N >> K >> M;

    vector<int> vec;
	for (int i = 1; i <= N; i++)
		vec.push_back(i);

	for (int id = 0, i = 1, del = 0, ori = 1; del < N; i++) {
        while(vec[id] == -1) {
            if (ori) id = (id + 1) % N;
    		else id = (id + N - 1) % N;
        }

        if ((i % K) == 0) {
            cout << vec[id] << '\n';
            del++;
            vec[id] = -1;
        }

		if (!(del % M) && !(i % K))
			ori = 1 - ori;

		if (ori) id = (id + 1) % N;
		else id = (id + N - 1) % N;
	}

	return 0;
}