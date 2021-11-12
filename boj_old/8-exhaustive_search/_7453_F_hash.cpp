/* map, hash_map은 내부적으로 트리 형태를 이루므로 오버헤드가 많음.
 * 따라서 시간 초과에 가까운 점수를 받게 될 것.
 * 직접 해시 테이블을 만들어서 사용하는 것이 최적.
 * 
 * -> 다른 곳에서 가져온 코드인데도 시간 초과. 아예 해시로는 못 푸는 수준으로 보인다.
 */

#include <cstdio>
#include <cstring>

int A[4000], B[4000], C[4000], D[4000], N;

const int SIZE = 10'000'000, KEY = SIZE / 3;
int ht[SIZE], cnt[SIZE];
void put(int val) {
	int idx = val % SIZE;
	while (true) {
		idx = (idx + KEY) % SIZE;
		if (ht[idx] == val || ht[idx] == SIZE) {
		ht[idx] = val, cnt[idx]++;
		return;
        }
    }
}
int get(int val) {
	int idx = val % SIZE;
	while (true) {
		idx = (idx + KEY) % SIZE;
		if (ht[idx] == SIZE)
			return 0;
		if (ht[idx] == val)
			return cnt[idx];
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    
	for (int i = 0; i < SIZE; i++)
		ht[i] = SIZE;//, cnt[i] = 0;
    
	long long ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			put(A[i] + B[j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += get(-(C[i] + D[j]));
	printf("%lld", ans);
}