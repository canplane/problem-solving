/* compile option
g++ --std=c++17 foo.c
*/

using namespace std;
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

char s[1001];
array<char *, 1001> A;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	////

	cin >> s;
	for (n = 0; s[n]; n++)
		A[n] = s + n;
	A[n] = s + n;

	sort(&A.at(0), &A.at(n), [](char *&a, char *&b) -> bool {
		return strcmp(a, b) < 0;
	});

	for (n = 0; *A[n]; n++)
		cout << A[n] << "\n";
}