// BOJ 13701 G4 중복 제거

using namespace std;
#include <bitset>

bitset<1 << 25> bs;

int main()
{
	int x;
	while (scanf("%d", &x) == 1) {
		if (!bs[x]) {	// !bs.test(x)
			printf("%d ", x);
		}
		bs[x] = 1;	// bs.set(x, true)
	}
}