/* compile option
g++ --std=c++17 foo.c
*/

using namespace std;
#include <cstdio>
#include <iostream>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//

	string s;
	getline(cin, s);
	for (char& c : s) {
		if (islower(c))
			cout << (char)(97 + ((c - 97) + 13) % 26);
		else if (isupper(c))
			cout << (char)(65 + ((c - 65) + 13) % 26);
		else
			cout << c;
	}
}