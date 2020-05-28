// BOJ 2588 곱셈
// 수학

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    cout << a * (b % 10) << '\n';
    cout << a * ((b % 100) / 10) << '\n';
    cout << a * (b / 100) << '\n';
    cout << a * b;
}