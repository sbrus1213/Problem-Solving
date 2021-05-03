#include <iostream>
#include <string>
#include <vector>
using namespace std;


void merge(vector<string>& v, int l, int r) {
    vector<string> dump(v.size());
    int mid = (l + r) / 2, i, j, k;
    for (i = l, j = mid + 1, k = l; i <= mid && j <= r;) {
        if (v[i] >= v[j]) dump[k++] = v[j++];
        else dump[k++] = v[i++];
    }
    while (i <= mid) dump[k++] = v[i++];
    while (j <= r) dump[k++] = v[j++];
    for (int idx = l; idx <= r; idx++)
        v[idx] = dump[idx];
}

void merge_sort(vector<string>& v, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    merge(v, l, r);
}

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

    merge_sort(vec, 0, N - 1);

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
