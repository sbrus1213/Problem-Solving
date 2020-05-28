// BOJ 2753 윤년
// 수학

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n; cin >> n;
    if (n % 4) cout << "0";
    else if (!(n % 100) && (n % 400)) cout << "0";
    else cout << "1";
}