/* compile option
g++ --std=c++17 foo.cpp
*/

using namespace std;
#include <cstdio>
#include <iostream>
#include <list>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	////

	int N, K;
	scanf("%d %d", &N, &K);
	
	list<int> li;
	for (int i = 1; i <= N; i++)
		li.push_back(i);
	
	printf("<");
	auto it = li.begin();
	while (true) {
		for (int i = 1; i < K; i++) {
			it++;
			if (it == li.end())
				it = li.begin();
		}
		printf("%d", *it);
		it = li.erase(it);
		if (li.begin() == li.end())
			break;
		if (it == li.end())
			it = li.begin();
		printf(", ");
	}
	printf(">");
}