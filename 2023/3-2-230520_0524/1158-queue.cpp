/* compile option
g++ --std=c++17 foo.cpp
*/

using namespace std;
#include <cstdio>
#include <iostream>
#include <queue>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	////

	int N, K;
	scanf("%d %d", &N, &K);
	
	queue<int> li;
	for (int i = 1; i <= N; i++)
		li.push(i);
	
	int i, x;
	printf("<");
	while (li.size() > 1) {
		for (i = 1; i < K; i++) {
			x = li.front(), li.pop();
			li.push(x);
		}
		x = li.front(), li.pop();
		printf("%d, ", x);
	}
	printf("%d>", li.front());
}