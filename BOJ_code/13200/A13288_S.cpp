// BOJ 13288 A New Alphabet
// string

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; getline(cin, s);

	map<char, int> dic;
	for (char c = 'a'; c <= 'z'; ++c)
		dic[c] = c - 'a';
	for (char c = 'a', ch = 'A'; c <= 'z'; ++c, ++ch)
		dic[ch] = c - 'a';

	string newc[26] = { "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]",
	"[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2" };

	for (char c : s) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			cout << newc[dic[c]];
		else cout << c;
	}
}