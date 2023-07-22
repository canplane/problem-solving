/*
	* 틀린 요인
		* long: stol()
*/

using namespace std;
#include <cstdio>
#include <iostream>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//

	string A, B, C, D;
	cin >> A >> B >> C >> D;
	A += B, C += D;
	cout << stol(A) + stol(C);
}