#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> vec;

    for (int i = 0; i < N; i++) {
        string file;
        cin >> file;

        int dot = file.find('.');
        string ext = file.substr(dot + 1);

        vec.push_back(ext);
    }

    for (int i = 0; i < N; ++i) {
        auto x = vec[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            auto y = vec[j];
            if (y > x) vec[j + 1] = y;
            else break;
        }
        vec[j + 1] = x;
    }

    for (int i = 0; i < N;) {
        string s = vec[i];
        int j = i;
        while (j < N && vec[j] == s)
            j++;
        cout << s << ' ' << j - i << '\n';
        i = j;
    }

    return 0;
}
