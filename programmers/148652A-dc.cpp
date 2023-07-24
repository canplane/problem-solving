// 유사 칸토어 비트열: https://school.programmers.co.kr/learn/courses/30/lessons/148652

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, long long l, long long r) {
	l -= 1, r -= 1;

	int nans = 0;
	for (long long i = l; i <= r; i++) {
		long long j = i;
		while (j) {
			if (j % 5 == 2) {
				nans += 1;
				break;
			}
			j /= 5;
		}

	}
    return (r - l + 1) - nans;
}

int main()
{
	cout << solution(2, 1, 5);
}